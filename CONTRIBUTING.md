# Contributing to Ipp

Thank you for your interest in contributing to Ipp!

## Development Philosophy

Ipp follows these principles:
1. **Simplicity First** - Keep things simple and learnable
2. **Progressive Power** - Add complexity gradually
3. **Game Dev Focus** - Prioritize game development features

## Getting Started

1. Fork the repository
2. Clone your fork
3. Create a branch for your feature

```bash
git checkout -b feature/your-feature
```

## Project Structure

```
Ipp/
├── ipp/
│   ├── lexer/         # Tokenizer
│   ├── parser/        # Parser & AST
│   ├── interpreter/   # Interpreter
│   ├── runtime/       # Built-in functions
│   └── vm/            # Bytecode VM (future)
├── examples/          # Example scripts
├── tests/             # Test files
└── main.py           # Entry point
```

## Running Tests

```bash
# Run example scripts
python main.py examples/hello_world.ipp
python main.py examples/functions.ipp
python main.py examples/class_example.ipp
```

## Code Style

- Use 4 spaces for indentation
- Use descriptive names
- Comment complex logic
- Keep functions small and focused

## Adding Features

1. **Lexer** - Add new tokens in `lexer/token.py`
2. **Parser** - Add parsing in `parser/parser.py`
3. **AST** - Define nodes in `parser/ast.py`
4. **Interpreter** - Add evaluation in `interpreter/interpreter.py`
5. **Built-ins** - Add functions in `runtime/builtins.py`

## Submitting Changes

1. Test your changes
2. Commit with clear messages
3. Push to your fork
4. Create a pull request

## Issue Guidelines

- Use clear titles
- Provide reproduction steps
- Include relevant code snippets

## Communication

- Be respectful and inclusive
- Help others learn
- Focus on constructive feedback
