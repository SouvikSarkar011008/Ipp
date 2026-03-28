#!/usr/bin/env python3
"""
Ipp Language — Main entry point + Gemini-CLI-inspired REPL
"""

import sys
import os
import re
import shutil
import atexit
import unicodedata
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from ipp.lexer.lexer import tokenize
from ipp.parser.parser import parse
from ipp.interpreter.interpreter import Interpreter

VERSION = "1.2.0"

# ─── ANSI colour helpers (no external deps) ───────────────────────────────────
def _esc(*codes): return f"\033[{';'.join(str(c) for c in codes)}m"
RESET   = _esc(0)
BOLD    = lambda t: f"{_esc(1)}{t}{RESET}"
DIM     = lambda t: f"{_esc(2)}{t}{RESET}"
ITALIC  = lambda t: f"{_esc(3)}{t}{RESET}"

def _fg(n, t):   return f"{_esc(38,5,n)}{t}{RESET}"   # 256-colour fg
def _rgb(r,g,b,t): return f"{_esc(38,2,r,g,b)}{t}{RESET}"  # true-colour fg

# Palette (Gemini-inspired: cyan/teal/purple gradient)
C_PROMPT   = lambda t: _rgb(100,200,255,t)   # bright sky blue
C_CONT     = lambda t: _rgb(100,140,200,t)   # muted blue  (continuation)
C_RESULT   = lambda t: _rgb(180,255,180,t)   # mint green
C_ERROR    = lambda t: _rgb(255,100,100,t)   # soft red
C_WARN     = lambda t: _rgb(255,200,80,t)    # amber
C_OK       = lambda t: _rgb(80,220,120,t)    # green
C_CMD      = lambda t: _rgb(150,120,255,t)   # violet (commands)
C_TYPE     = lambda t: _rgb(255,160,80,t)    # orange (types)
C_KW       = lambda t: _rgb(100,200,255,t)   # cyan (keywords)
C_STR      = lambda t: _rgb(150,255,150,t)   # green (strings)
C_NUM      = lambda t: _rgb(255,180,100,t)   # orange (numbers)
C_COMMENT  = lambda t: _rgb(120,120,140,t)   # grey (comments)
C_FN       = lambda t: _rgb(130,170,255,t)   # blue (functions)
C_BOOL     = lambda t: _rgb(220,130,255,t)   # purple (booleans)
C_HEADER   = lambda t: _rgb(80,200,255,t)    # header text
C_LOGO1    = lambda t: _fg(51,  t)
C_LOGO2    = lambda t: _fg(45,  t)
C_LOGO3    = lambda t: _fg(39,  t)
C_LOGO4    = lambda t: _fg(33,  t)
C_LOGO5    = lambda t: _fg(27,  t)

IS_TTY = sys.stdout.isatty()

def colour(fn, text):
    return fn(text) if IS_TTY else text

def strip_ansi(s):
    return re.sub(r'\033\[[0-9;]*m', '', s)

def visible_len(s):
    plain = strip_ansi(s)
    return sum(2 if unicodedata.east_asian_width(c) in ('W','F') else 1 for c in plain)

def pad_to(s, width):
    return s + ' ' * max(0, width - visible_len(s))

# ─── Syntax highlighter ───────────────────────────────────────────────────────
_KEYWORDS = frozenset([
    "var","let","func","class","if","else","elif","for","while",
    "match","case","default","try","catch","finally","throw","return",
    "break","continue","import","as","in","nil","true","false",
    "self","this","enum","static","repeat","until","and","or","not","with",
])
_BUILTINS = frozenset([
    "print","len","type","range","abs","min","max","sum","round",
    "floor","ceil","sqrt","pow","sin","cos","tan","log","input",
    "str","int","float","bool","randint","random","keys","values",
    "items","contains","split","join","upper","lower","strip",
    "replace","find","starts_with","ends_with","assert","exit",
])

def highlight(code: str) -> str:
    if not IS_TTY:
        return code
    lines = code.split('\n')
    out = []
    for line in lines:
        # comment
        ci = line.find('#')
        comment = ''
        if ci >= 0:
            comment = colour(C_COMMENT, line[ci:])
            line = line[:ci]

        # strings
        def repl_str(m):
            return colour(C_STR, m.group())
        line = re.sub(r'"[^"\\]*(?:\\.[^"\\]*)*"', repl_str, line)
        line = re.sub(r"'[^'\\]*(?:\\.[^'\\]*)*'", repl_str, line)

        # booleans / nil
        line = re.sub(r'\b(true|false|nil)\b',
                      lambda m: colour(C_BOOL, m.group()), line)
        # numbers
        line = re.sub(r'\b(0[xXoObB][0-9a-fA-F_]+|\d[\d_]*\.?\d*)\b',
                      lambda m: colour(C_NUM, m.group()), line)
        # keywords
        line = re.sub(r'\b(' + '|'.join(_KEYWORDS) + r')\b',
                      lambda m: colour(C_KW, m.group()), line)
        # builtins
        line = re.sub(r'\b(' + '|'.join(_BUILTINS) + r')\b',
                      lambda m: colour(C_FN, m.group()), line)
        # user function calls
        line = re.sub(r'\b([a-zA-Z_]\w*)\s*(?=\()',
                      lambda m: (colour(C_FN, m.group(1)) + m.group()[len(m.group(1)):]),
                      line)
        out.append(line + comment)
    return '\n'.join(out)

# ─── Banner ───────────────────────────────────────────────────────────────────
_LOGO_LINES = [
    ("  ██╗██████╗ ██████╗  ", C_LOGO1),
    ("  ██║██╔══██╗██╔══██╗ ", C_LOGO2),
    ("  ██║██████╔╝██████╔╝ ", C_LOGO3),
    ("  ██║██╔═══╝ ██╔═══╝  ", C_LOGO4),
    ("  ██║██║     ██║      ", C_LOGO5),
    ("  ╚═╝╚═╝     ╚═╝      ", C_LOGO1),
]

def _bar(ch='─', w=58): return colour(C_HEADER, ch * w)

def print_banner():
    W = shutil.get_terminal_size((80,24)).columns
    pad = max(0, (W - 60) // 2)
    sp = ' ' * pad

    print()
    for text, clr in _LOGO_LINES:
        print(sp + colour(clr, BOLD(text)))
    print()
    print(sp + _bar())
    tag   = colour(C_HEADER, BOLD(f"  Ipp  v{VERSION}"))
    sub   = colour(DIM,     "  A scripting language for game development")
    print(sp + tag)
    print(sp + colour(DIM, sub))
    print(sp + _bar())
    print()
    hints = [
        (colour(C_CMD, ".help"),    "commands"),
        (colour(C_CMD, ".vars"),    "variables"),
        (colour(C_CMD, "exit"),     "quit"),
        (colour(C_CMD, "Tab"),      "autocomplete"),
    ]
    row = "  "
    for k, v in hints:
        row += f"{k} {colour(DIM, v)}   "
    print(sp + row)
    print()

# ─── Readline / autocomplete ──────────────────────────────────────────────────
try:
    import readline
    HAS_RL = True
except ImportError:
    HAS_RL = False

class IppCompleter:
    def __init__(self, interp):
        self.interp = interp
        self.matches = []

    def complete(self, text, state):
        if state == 0:
            buf = readline.get_line_buffer() if HAS_RL else text
            dot = re.match(r'.*?(\w+)\.([\w]*)$', buf)
            if dot:
                obj_name, prefix = dot.group(1), dot.group(2)
                self.matches = [m for m in self._members(obj_name) if m.startswith(prefix)]
            else:
                cands = set(list(_KEYWORDS) + list(_BUILTINS)) | self._globals()
                self.matches = sorted(c for c in cands if c.startswith(text))
        try:
            return self.matches[state]
        except IndexError:
            return None

    def _globals(self):
        names = set()
        if hasattr(self.interp, 'global_env'):
            env = self.interp.global_env
            while env:
                if hasattr(env, 'values'):
                    names |= env.values.keys()
                env = env.parent
        return names

    def _members(self, obj_name):
        try:
            env = self.interp.global_env
            obj = None
            while env:
                if hasattr(env, 'values') and obj_name in env.values:
                    obj = env.values[obj_name]; break
                env = env.parent
            if obj is None: return []
            m = []
            if hasattr(obj, 'fields'): m += list(obj.fields)
            if hasattr(obj, 'ipp_class') and hasattr(obj.ipp_class, 'methods'):
                m += list(obj.ipp_class.methods)
            if hasattr(obj, '_env') and hasattr(obj._env, 'values'):
                m += list(obj._env.values)
            return sorted(set(m))
        except Exception:
            return []

def setup_readline(interp):
    if not HAS_RL: return
    try:
        hdir = os.path.join(os.path.expanduser("~"), ".ipp")
        os.makedirs(hdir, exist_ok=True)
        hfile = os.path.join(hdir, "history")
        try: readline.read_history_file(hfile)
        except FileNotFoundError: pass
        readline.set_history_length(2000)
        readline.parse_and_bind("tab: complete")
        readline.parse_and_bind("set completion-ignore-case on")
        readline.set_completer_delims(" \t\n`~!@#$%^&*()-=+[]{}|;:',.<>?/")
        comp = IppCompleter(interp)
        readline.set_completer(comp.complete)
        atexit.register(readline.write_history_file, hfile)
        return comp
    except Exception:
        return None

# ─── Brace balance check ──────────────────────────────────────────────────────
def _balanced(src: str) -> bool:
    stack = []
    in_str = in_sq = False
    i = 0
    while i < len(src):
        c = src[i]
        if c == '\\' and (in_str or in_sq):
            i += 2; continue
        if c == '"' and not in_sq: in_str = not in_str
        elif c == "'" and not in_str: in_sq = not in_sq
        elif not in_str and not in_sq:
            if c in '([{': stack.append(c)
            elif c in ')]}':
                if not stack: return False
                opens = {'(':')', '[':']', '{':'}'}
                if opens[stack[-1]] != c: return False
                stack.pop()
        i += 1
    return len(stack) == 0

def _needs_more(src: str) -> bool:
    src = src.strip()
    if not src: return False
    if not _balanced(src): return True
    # ends with open brace or continuation keywords
    if re.search(r'[\{,]\s*$', src): return True
    return False

# ─── Help & meta commands ─────────────────────────────────────────────────────
def _section(title):
    print()
    print("  " + colour(C_CMD, BOLD(f" {title} ")))
    print("  " + colour(DIM, "─" * 50))

def print_help():
    _section("Commands")
    cmds = [
        (".help",       "Show this help"),
        (".vars",       "List all defined variables"),
        (".clear",      "Reset the session"),
        (".types",      "Show the type system"),
        (".version",    f"Show version (v{VERSION})"),
        ("exit / quit", "Exit the REPL"),
    ]
    for cmd, desc in cmds:
        c_cmd  = colour(C_CMD, cmd.ljust(16))
        c_desc = colour(DIM, desc)
        print(f"    {c_cmd} {c_desc}")

    _section("Quick Reference")
    snippets = [
        ("var x = 10",                  "mutable variable"),
        ("let y = 20",                  "immutable binding"),
        ("x += 5",                      "compound assignment  ✓ NEW"),
        ("func add(a, b) { return a+b }","function"),
        ("var f = func(a) => a*2",      "lambda  ✓ NEW"),
        ("class Dog : Animal { }",      "class with inheritance  ✓ NEW"),
        ("2 ** 10",                     "power operator  ✓ FIXED"),
        ("0xFF & 0x0F",                 "hex literals & bitwise  ✓ NEW"),
        ('var s = "Hi\\nWorld"',        "escape sequences  ✓ FIXED"),
        ("[x*x for x in 1..5]",         "list comprehension"),
        ('nil ?? "default"',            "nullish coalescing"),
        ("try { } catch e { }",         "error handling  ✓ FIXED"),
        ("import \"mod.ipp\" as m",     "modules"),
    ]
    for code, note in snippets:
        print(f"    {highlight(code.ljust(36))} {colour(DIM, note)}")
    print()

def print_types():
    _section("Type System")
    types_info = [
        ("number",    "42, 3.14, 0xFF, 0b1010"),
        ("string",    '"hello", escape \\n \\t supported'),
        ("bool",      "true / false"),
        ("nil",       "null value"),
        ("list",      "[1, 2, 3]"),
        ("dict",      '{"key": val}'),
        ("tuple",     "(1, 2, 3)"),
        ("function",  "first-class, closures, lambdas"),
        ("class",     "OOP with inheritance"),
        ("enum",      "enum Direction { UP, DOWN }"),
    ]
    for t, desc in types_info:
        print(f"    {colour(C_TYPE, t.ljust(12))} {colour(DIM, desc)}")
    print()

def show_vars(interp):
    _section("Defined Variables")
    env = interp.global_env
    all_vars = {}
    while env:
        if hasattr(env, 'values'):
            for k, v in env.values.items():
                if k not in all_vars and not k.startswith('_'):
                    all_vars[k] = v
        env = env.parent

    # filter builtins
    user_vars = {k: v for k, v in all_vars.items()
                 if k not in _BUILTINS and not callable(v)}

    if not user_vars:
        print(f"    {colour(DIM, '(none defined yet)')}")
    else:
        for name, val in sorted(user_vars.items()):
            vt = type(val).__name__
            if hasattr(val, 'cls'):  vt = val.cls.name
            elif hasattr(val, 'name') and hasattr(val, 'methods'): vt = 'class'
            elif callable(val): vt = 'function'
            val_str = str(val)
            if len(val_str) > 40: val_str = val_str[:37] + '...'
            print(f"    {colour(C_STR, name.ljust(16))} "
                  f"{colour(C_TYPE, vt.ljust(10))} "
                  f"{colour(DIM, val_str)}")
    print()

# ─── Output formatter ─────────────────────────────────────────────────────────
def format_output(val) -> str:
    if val is None:            return ''
    if isinstance(val, bool):  return colour(C_BOOL, 'true' if val else 'false')
    if isinstance(val, (int, float)):
        s = str(int(val)) if isinstance(val, float) and val.is_integer() else str(val)
        return colour(C_NUM, s)
    if isinstance(val, str):   return colour(C_STR, repr(val))
    return colour(C_RESULT, str(val))

# ─── REPL spinner (simple, no threads) ───────────────────────────────────────
_SPINNER = ['⣾','⣽','⣻','⢿','⡿','⣟','⣯','⣷']

# ─── Main REPL ────────────────────────────────────────────────────────────────
def run_repl():
    interp = Interpreter()
    setup_readline(interp)
    print_banner()

    buf = []
    line_num = 0

    while True:
        try:
            if buf:
                prompt_txt = colour(C_CONT, f"  {'·' * 3} ")
            else:
                prompt_txt = colour(C_PROMPT, "  ❯ ")

            raw = input(prompt_txt)

        except KeyboardInterrupt:
            print()
            if buf:
                buf.clear()
                print(f"  {colour(C_WARN, '↩  Buffer cleared')}")
            else:
                print(f"  {colour(DIM, 'Ctrl+C  — type exit to quit')}")
            continue
        except EOFError:
            print()
            print(f"  {colour(C_OK, 'Goodbye! 👋')}")
            break

        # ── Meta commands (only at fresh prompt) ──────────────────────
        stripped = raw.strip()
        if not buf:
            if stripped in ('exit', 'exit()', 'quit', '.exit', '.quit'):
                print(f"  {colour(C_OK, 'Goodbye! 👋')}")
                break
            if stripped == '.help':    print_help();         continue
            if stripped == '.types':   print_types();        continue
            if stripped == '.vars':    show_vars(interp);    continue
            if stripped == '.version': print(f"  Ipp v{VERSION}"); continue
            if stripped in ('.clear', 'clear()'):
                buf.clear()
                interp = Interpreter()
                setup_readline(interp)
                print(f"  {colour(C_WARN, '✦  Session cleared')}")
                continue

        if not stripped and not buf:
            continue

        buf.append(raw)
        source = '\n'.join(buf)

        if _needs_more(source):
            continue

        # ── Execute ───────────────────────────────────────────────────
        t0 = time.perf_counter()
        try:
            tokens = tokenize(source)
            ast    = parse(tokens)
            interp.run(ast)
            elapsed = time.perf_counter() - t0

            val = interp.return_value if interp.return_value is not None else interp.last_value
            interp.return_value = None
            interp.last_value   = None

            if val is not None:
                fmted = format_output(val)
                ms_str = colour(DIM, f"  {elapsed*1000:.1f}ms")
                print(f"  {colour(DIM, '→')} {fmted}{ms_str}")

            buf.clear()
            line_num += 1

        except (SyntaxError, RuntimeError) as e:
            buf.clear()
            msg = str(e)
            # Extract line info if present
            m = re.search(r'line (\d+)', msg)
            loc = f" {colour(DIM, f'(line {m.group(1)})')}" if m else ''
            print(f"  {colour(C_ERROR, '✗')} {colour(C_ERROR, msg)}{loc}")
        except Exception as e:
            buf.clear()
            print(f"  {colour(C_ERROR, '✗')} {colour(C_ERROR, str(e))}")

# ─── File runner ──────────────────────────────────────────────────────────────
def run_file(path: str) -> int:
    try:
        with open(path, 'r', encoding='utf-8') as f:
            source = f.read()
    except FileNotFoundError:
        print(f"{colour(C_ERROR, '[Error]')} File not found: {path}")
        return 1

    try:
        tokens = tokenize(source)
        ast    = parse(tokens)
        interp = Interpreter()
        interp.current_file = os.path.abspath(path)
        interp.run(ast)
        return 0
    except Exception as e:
        print(f"{colour(C_ERROR, '[Error]')} {e}")
        return 1

def check_file(path: str) -> int:
    try:
        with open(path, 'r', encoding='utf-8') as f:
            src = f.read()
        tokenize(src); parse(tokenize(src))
        print(f"{colour(C_OK, '✓')} Syntax OK: {path}")
        return 0
    except Exception as e:
        print(f"{colour(C_ERROR, '✗')} {e}")
        return 1

def lint_file(path: str) -> int:
    issues = []
    try:
        with open(path, 'r', encoding='utf-8') as f:
            src = f.read()
    except FileNotFoundError:
        print(f"{colour(C_ERROR, '[Error]')} File not found: {path}")
        return 1

    for i, line in enumerate(src.split('\n'), 1):
        if len(line.rstrip()) > 120:
            issues.append(f"line {i}: line too long ({len(line.rstrip())} > 120)")
        if '\t' in line:
            issues.append(f"line {i}: use spaces not tabs")
    try:
        tokenize(src); parse(tokenize(src))
    except Exception as e:
        issues.append(f"syntax: {e}")

    if issues:
        for iss in issues:
            print(f"  {colour(C_WARN, '⚠')} {iss}")
        print(f"\n{colour(C_ERROR, '✗')} {len(issues)} issue(s)")
        return 1
    print(f"{colour(C_OK, '✓')} No issues: {path}")
    return 0

def print_usage():
    print(f"\n{BOLD('Ipp')} v{VERSION} — A scripting language for game development\n")
    print(f"{BOLD('Usage:')}  python main.py [command] [file]\n")
    cmds = [
        ("<file>",    "Run a script"),
        ("run <f>",   "Run a script"),
        ("check <f>", "Syntax check"),
        ("lint <f>",  "Lint code"),
        ("repl",      "Start REPL (default)"),
    ]
    print(BOLD("Commands:"))
    for c, d in cmds:
        print(f"  {colour(C_CMD, c.ljust(14))} {d}")
    print()

def main():
    args = sys.argv[1:]
    if not args:
        run_repl(); return 0

    cmd = args[0]
    if cmd in ('--help', '-h'):
        print_usage(); return 0
    if cmd in ('--version', '-v'):
        print(f"Ipp v{VERSION}"); return 0
    if cmd == 'repl':
        run_repl(); return 0
    if cmd == 'run' and len(args) >= 2:
        return run_file(args[1])
    if cmd == 'check' and len(args) >= 2:
        return check_file(args[1])
    if cmd == 'lint' and len(args) >= 2:
        return lint_file(args[1])
    if not cmd.startswith('-'):
        return run_file(cmd)

    print_usage(); return 1

if __name__ == '__main__':
    sys.exit(main())
