from .token import Token, TokenType, KEYWORDS


class Lexer:
    def __init__(self, source: str):
        self.source = source
        self.tokens = []
        self.start = 0
        self.current = 0
        self.line = 1
        self.column = 1
        self.at_line_start = True

    def scan(self):
        while not self.is_at_end:
            self.scan_token()
        
        self.add_token(TokenType.EOF, "", None)
        return self.tokens

    def scan_token(self):
        self.skip_whitespace()
        self.skip_comments()
        
        if self.is_at_end:
            self.add_token(TokenType.EOF, "", None)
            return

        self.start = self.current

        c = self.advance()
        
        # Single character tokens
        if c == '(':
            self.add_token(TokenType.LEFT_PAREN)
        elif c == ')':
            self.add_token(TokenType.RIGHT_PAREN)
        elif c == '{':
            self.add_token(TokenType.LEFT_BRACE)
        elif c == '}':
            self.add_token(TokenType.RIGHT_BRACE)
        elif c == '[':
            self.add_token(TokenType.LEFT_BRACKET)
        elif c == ']':
            self.add_token(TokenType.RIGHT_BRACKET)
        elif c == ',':
            self.add_token(TokenType.COMMA)
        elif c == '.':
            if self.peek() == '.':
                self.advance()
                if self.peek() == '.':
                    self.advance()
                    self.add_token(TokenType.TRIPLE_DOT)
                else:
                    self.add_token(TokenType.DOTDOT)
            else:
                self.add_token(TokenType.DOT)
        elif c == ':':
            if self.match(':'):
                self.add_token(TokenType.DOUBLE_COLON)
            else:
                self.add_token(TokenType.COLON)
        elif c == '?':
            if self.match('.'):
                self.add_token(TokenType.QUESTION_DOT)
            elif self.match('?'):
                self.add_token(TokenType.DOUBLE_QUESTION)
            else:
                self.add_token(TokenType.QUESTION)
        
        # Pipeline operator and bitwise OR
        elif c == '|':
            if self.match('>'):
                self.add_token(TokenType.PIPE)
            elif self.match('|'):
                self.add_token(TokenType.DOUBLE_PIPE)
            else:
                self.add_token(TokenType.OR)
        
        # Multi-character operators
        elif c == '+':
            self.add_token(TokenType.PLUS)
        elif c == '-':
            self.add_token(TokenType.MINUS)
        elif c == '*':
            if self.match('*'):
                self.add_token(TokenType.DOUBLE_STAR)
            else:
                self.add_token(TokenType.STAR)
        elif c == '/':
            if self.match('/'):
                self.add_token(TokenType.DOUBLE_SLASH)
            else:
                self.add_token(TokenType.SLASH)
        elif c == '%':
            self.add_token(TokenType.PERCENT)
        elif c == '^':
            self.add_token(TokenType.CARET)
        
        # Bitwise operators
        elif c == '&':
            if self.match('&'):
                self.add_token(TokenType.DOUBLE_AMP)
            else:
                self.add_token(TokenType.AND)
        elif c == '|':
            if self.match('|'):
                self.add_token(TokenType.DOUBLE_PIPE)
            else:
                self.add_token(TokenType.OR)
        elif c == '~':
            self.add_token(TokenType.TILDE)
        
        # Comparison operators
        elif c == '!':
            self.add_token(TokenType.BANG_EQUAL if self.match('=') else TokenType.BANG)
        elif c == '=':
            if self.match('>'):
                self.add_token(TokenType.ARROW)
            else:
                self.add_token(TokenType.EQUAL_EQUAL if self.match('=') else TokenType.EQUAL)
        elif c == '<':
            if self.match('<'):
                self.add_token(TokenType.DOUBLE_LESS)
            elif self.match('='):
                self.add_token(TokenType.LESS_EQUAL)
            else:
                self.add_token(TokenType.LESS)
        elif c == '>':
            if self.match('>'):
                self.add_token(TokenType.DOUBLE_GREATER)
            elif self.match('='):
                self.add_token(TokenType.GREATER_EQUAL)
            else:
                self.add_token(TokenType.GREATER)
        
        # String literals
        elif c == '"' or c == "'":
            self.string(c)
        
        # Numbers
        elif c.isdigit():
            self.number()
        
        # Identifiers and keywords
        elif c.isalpha() or c == '_':
            self.identifier()
        
        # Newline (significant in Ipp)
        elif c == '\n':
            if not self.at_line_start:
                self.add_token(TokenType.NEWLINE, "\n", None)
            self.line += 1
            self.column = 1
            self.at_line_start = True
        else:
            self.error(f"Unexpected character: {c}")

    def identifier(self):
        while self.peek().isalnum() or self.peek() == '_':
            self.advance()
        
        text = self.source[self.start:self.current]
        
        if text in KEYWORDS:
            token_type = KEYWORDS[text]
            if token_type in (TokenType.TRUE, TokenType.FALSE, TokenType.NIL):
                self.add_token(token_type, text, text == 'true' if token_type != TokenType.NIL else None)
            else:
                self.add_token(token_type)
        else:
            self.add_token(TokenType.IDENTIFIER)

    def number(self):
        has_decimal = False
        while self.peek().isdigit():
            self.advance()
        
        # Decimal part
        if self.peek() == '.' and self.peek_next().isdigit():
            has_decimal = True
            self.advance()
            while self.peek().isdigit():
                self.advance()
        
        # Create integer if no decimal point
        if has_decimal:
            value = float(self.source[self.start:self.current])
        else:
            value = int(self.source[self.start:self.current])
        self.add_token(TokenType.NUMBER, literal=value)

    def string(self, quote_char):
        while not self.is_at_end and self.peek() != quote_char:
            if self.peek() == '\n':
                self.error("Unterminated string")
            self.advance()
        
        if self.is_at_end:
            self.error("Unterminated string")
        
        self.advance()  # Closing quote
        value = self.source[self.start + 1:self.current - 1]
        self.add_token(TokenType.STRING, literal=value)

    def skip_whitespace(self):
        while not self.is_at_end and self.peek() in ' \t\r':
            self.advance()
            self.column += 1
            self.at_line_start = False

    def skip_comments(self):
        while not self.is_at_end and self.peek() == '#':
            while not self.is_at_end and self.peek() != '\n':
                self.advance()
            self.at_line_start = True

    def add_token(self, token_type, lexeme=None, literal=None):
        if lexeme is None:
            lexeme = self.source[self.start:self.current]
        
        token = Token(token_type, lexeme, literal, self.line, self.column)
        self.tokens.append(token)
        self.at_line_start = False

    def advance(self):
        c = self.source[self.current]
        self.current += 1
        self.column += 1
        return c

    def match(self, expected):
        if self.is_at_end:
            return False
        if self.source[self.current] != expected:
            return False
        self.current += 1
        self.column += 1
        return True

    def peek(self):
        if self.is_at_end:
            return '\0'
        return self.source[self.current]

    def peek_next(self):
        if self.current + 1 >= len(self.source):
            return '\0'
        return self.source[self.current + 1]

    @property
    def is_at_end(self):
        return self.current >= len(self.source)

    def error(self, message):
        raise RuntimeError(f"Lexical error at line {self.line}, column {self.column}: {message}")


def tokenize(source: str) -> list[Token]:
    lexer = Lexer(source)
    return lexer.scan()