#!/usr/bin/env python3
"""
Ipp - A simple, beginner-friendly scripting language for game development
"""

import sys
import os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from ipp.lexer.lexer import tokenize
from ipp.parser.parser import parse
from ipp.interpreter.interpreter import interpret


def run_file(filepath):
    """Run an Ipp source file"""
    import os
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            source = f.read()
    except FileNotFoundError:
        print(f"Error: File not found: {filepath}")
        return 1
    except Exception as e:
        print(f"Error reading file: {e}")
        return 1
    
    try:
        tokens = tokenize(source)
        ast = parse(tokens)
        result = interpret(ast, os.path.abspath(filepath))
        if result is not None:
            print(result)
    except Exception as e:
        print(f"Error: {e}")
        return 1
    
    return 0


def check_file(filepath):
    """Syntax check an Ipp source file without running"""
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            source = f.read()
    except FileNotFoundError:
        print(f"Error: File not found: {filepath}")
        return 1
    except Exception as e:
        print(f"Error reading file: {e}")
        return 1
    
    try:
        tokens = tokenize(source)
        ast = parse(tokens)
        print(f"Syntax OK: {filepath}")
        return 0
    except Exception as e:
        print(f"Syntax Error: {e}")
        return 1


def run_repl():
    """Run the Ipp REPL"""
    print("Ipp v0.4.0 - Type 'help()' for info, 'exit()' to quit")
    print()
    
    buffer = []
    
    while True:
        try:
            if buffer:
                prompt = "... "
            else:
                prompt = "ipp> "
            
            line = input(prompt)
            
            if not buffer and line.strip() in ("exit()", "exit", "quit"):
                break
            
            if line.strip() == "help()":
                print("Ipp v0.4.0")
                print("Commands: exit(), help(), clear()")
                print("Features: strings, lists, dicts, json, regex, files, math, random, vectors")
                continue
                
            if line.strip() == "clear()":
                buffer = []
                continue
                
            if not line.strip() and not buffer:
                continue
                
            buffer.append(line)
            
            source = "\n".join(buffer)
            
            try:
                tokens = tokenize(source)
                ast = parse(tokens)
                result = interpret(ast)
                buffer = []
                if result is not None:
                    print(result)
            except Exception as e:
                error_msg = str(e)
                if "Expect" in error_msg or "Parse error" in error_msg:
                    continue
                else:
                    buffer = []
                    print(f"Error: {e}")
                    
        except KeyboardInterrupt:
            print()
            if buffer:
                buffer = []
            else:
                break
        except EOFError:
            break
        except Exception as e:
            buffer = []
            print(f"Error: {e}")


def print_help():
    """Print help message"""
    print("""Ipp - A simple scripting language for game development

Usage: ipp [command] [options]

Commands:
  run <file>      Run an Ipp script file
  check <file>   Check syntax without running
  repl           Start the interactive REPL

Options:
  -h, --help     Show this help message
  -v, --version  Show version information

Examples:
  ipp hello.ipp          Run a script
  ipp run game.ipp      Run a game script
  ipp check script.ipp  Check syntax
  ipp                    Start REPL""")


def print_version():
    """Print version information"""
    print("Ipp v0.4.0")
    print("A beginner-friendly scripting language for game development")


def main():
    if len(sys.argv) == 1:
        run_repl()
        return 0
    
    cmd = sys.argv[1] if len(sys.argv) > 1 else None
    
    if cmd in ("--help", "-h"):
        print_help()
        return 0
    elif cmd in ("--version", "-v"):
        print_version()
        return 0
    elif cmd in ("run", "repl", "check"):
        if len(sys.argv) < 3 and cmd != "repl":
            print(f"Error: '{cmd}' requires a file argument")
            print(f"Usage: ipp {cmd} <file>")
            return 1
        
        if cmd == "run":
            return run_file(sys.argv[2])
        elif cmd == "check":
            return check_file(sys.argv[2])
        elif cmd == "repl":
            run_repl()
            return 0
    elif cmd and not cmd.startswith("-"):
        # Treat as file to run
        return run_file(cmd)
    else:
        print_help()
        return 1


if __name__ == "__main__":
    sys.exit(main())