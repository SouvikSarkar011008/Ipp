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

# ─── Windows ANSI enablement ──────────────────────────────────────────────────
# Windows 10 supports ANSI but requires ENABLE_VIRTUAL_TERMINAL_PROCESSING.
# Without this, escape codes print as literal ←[ garbage.
def _enable_windows_ansi() -> bool:
    """Enable ANSI escape processing on Windows 10+. Returns True if succeeded."""
    if sys.platform != "win32":
        return True
    try:
        import ctypes
        import ctypes.wintypes
        kernel32 = ctypes.windll.kernel32
        # Get handle to stdout (STD_OUTPUT_HANDLE = -11)
        hout = kernel32.GetStdHandle(-11)
        if hout == -1:
            return False
        # Get current console mode
        mode = ctypes.wintypes.DWORD()
        if not kernel32.GetConsoleMode(hout, ctypes.byref(mode)):
            return False
        # ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004
        ENABLE_VTP = 0x0004
        if mode.value & ENABLE_VTP:
            return True  # already enabled
        new_mode = mode.value | ENABLE_VTP
        if kernel32.SetConsoleMode(hout, new_mode):
            return True
        return False
    except Exception:
        return False

# Try to enable ANSI; if it fails, we will strip all escape codes
_ANSI_OK = _enable_windows_ansi()

# Also check if we're in a real terminal (not redirected to a file)
IS_TTY = sys.stdout.isatty() and _ANSI_OK

# ─── ANSI colour helpers ──────────────────────────────────────────────────────
# IS_TTY is set above; when False every colour function returns plain text.

def _fg(n, t):
    return (f"\033[38;5;{n}m{t}\033[0m" if IS_TTY else t)

def _rgb(r, g, b, t):
    return (f"\033[38;2;{r};{g};{b}m{t}\033[0m" if IS_TTY else t)

BOLD   = lambda t: (f"\033[1m{t}\033[0m" if IS_TTY else t)
DIM    = lambda t: (f"\033[2m{t}\033[0m" if IS_TTY else t)
ITALIC = lambda t: (f"\033[3m{t}\033[0m" if IS_TTY else t)

# ── Palette ───────────────────────────────────────────────────────────────────
C_PROMPT  = lambda t: _rgb(100, 200, 255, t)
C_CONT    = lambda t: _rgb(100, 140, 200, t)
C_RESULT  = lambda t: _rgb(180, 255, 180, t)
C_ERROR   = lambda t: _rgb(255, 100, 100, t)
C_WARN    = lambda t: _rgb(255, 200,  80, t)
C_OK      = lambda t: _rgb( 80, 220, 120, t)
C_CMD     = lambda t: _rgb(150, 120, 255, t)
C_TYPE    = lambda t: _rgb(255, 160,  80, t)
C_KW      = lambda t: _rgb(100, 200, 255, t)
C_STR     = lambda t: _rgb(150, 255, 150, t)
C_NUM     = lambda t: _rgb(255, 180, 100, t)
C_COMMENT = lambda t: _rgb(120, 120, 140, t)
C_FN      = lambda t: _rgb(130, 170, 255, t)
C_BOOL    = lambda t: _rgb(220, 130, 255, t)
C_HEADER  = lambda t: _rgb( 80, 200, 255, t)
C_LOGO1   = lambda t: _fg(51, t)
C_LOGO2   = lambda t: _fg(45, t)
C_LOGO3   = lambda t: _fg(39, t)
C_LOGO4   = lambda t: _fg(33, t)
C_LOGO5   = lambda t: _fg(27, t)

def colour(fn, text):
    return fn(text)   # lambdas already no-op when IS_TTY=False

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
# Use Unicode box-drawing on terminals that support it, plain ASCII otherwise
def _supports_unicode():
    """Check if stdout can render Unicode box-drawing characters."""
    try:
        enc = (getattr(sys.stdout, 'encoding', None) or 'ascii').lower()
        return enc in ('utf-8', 'utf8', 'utf-16', 'cp65001')
    except Exception:
        return False

_UNI = _supports_unicode()

if _UNI:
    _LOGO_LINES = [
        ("  IPP  LANG  ",    C_LOGO1),   # compact safe label
        ("  +-----------+  ", C_LOGO2),
        ("  | Ipp v{v}  |  ".format(v=VERSION), C_LOGO3),
        ("  +-----------+  ", C_LOGO4),
    ]
    _LOGO_FULL = [
        ("  ██╗██████╗ ██████╗  ", C_LOGO1),
        ("  ██║██╔══██╗██╔══██╗ ", C_LOGO2),
        ("  ██║██████╔╝██████╔╝ ", C_LOGO3),
        ("  ██║██╔═══╝ ██╔═══╝  ", C_LOGO4),
        ("  ██║██║     ██║      ", C_LOGO5),
        ("  ╚═╝╚═╝     ╚═╝      ", C_LOGO1),
    ]
    _LOGO_LINES = _LOGO_FULL
else:
    # Pure ASCII logo for old Windows console
    _LOGO_LINES = [
        ("  ###  ######  ######  ", C_LOGO1),
        ("  ##   ##  ##  ##  ##  ", C_LOGO2),
        ("  ##   ######  ######  ", C_LOGO3),
        ("  ##   ##      ##      ", C_LOGO4),
        ("  ###  ##      ##      ", C_LOGO5),
    ]

def _bar(ch=None, w=58):
    if ch is None:
        ch = '-' if not _UNI else '─'
    return colour(C_HEADER, ch * w)

def print_banner():
    W = shutil.get_terminal_size((80, 24)).columns
    pad = max(0, (W - 62) // 2)
    sp = ' ' * pad

    print()
    for text, clr in _LOGO_LINES:
        print(sp + colour(clr, BOLD(text)))
    print()
    bar = _bar(w=54)
    print(sp + bar)
    tag = colour(C_HEADER, BOLD(f"  Ipp  v{VERSION}"))
    sub = DIM("  A scripting language for game development")
    print(sp + tag)
    print(sp + sub)
    print(sp + bar)
    print()
    sep = "   "
    parts = [
        colour(C_CMD, ".help") + " " + DIM("commands"),
        colour(C_CMD, ".vars") + " " + DIM("variables"),
        colour(C_CMD, "exit")  + " " + DIM("quit"),
        colour(C_CMD, "Tab")   + " " + DIM("autocomplete"),
    ]
    print(sp + "  " + sep.join(parts))
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
    div = '-' * 50 if not _UNI else '─' * 50
    print("  " + colour(DIM, div))

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
                dot = '...' if not _UNI else '···'
                prompt_txt = colour(C_CONT, f"  {dot} ")
            else:
                arrow = '>>>' if not _UNI else '❯'
                prompt_txt = colour(C_PROMPT, f"  {arrow} ")

            raw = input(prompt_txt)

        except KeyboardInterrupt:
            print()
            if buf:
                buf.clear()
                print(f"  {colour(C_WARN, '<< Buffer cleared')}")
            else:
                print(f"  {colour(DIM, 'Ctrl+C  — type exit to quit')}")
            continue
        except EOFError:
            print()
            print(f"  {colour(C_OK, 'Goodbye!')}")
            break

        # ── Meta commands (only at fresh prompt) ──────────────────────
        stripped = raw.strip()
        if not buf:
            if stripped in ('exit', 'exit()', 'quit', '.exit', '.quit'):
                print(f"  {colour(C_OK, 'Goodbye!')}")
                break
            if stripped == '.help':    print_help();         continue
            if stripped == '.types':   print_types();        continue
            if stripped == '.vars':    show_vars(interp);    continue
            if stripped == '.version': print(f"  Ipp v{VERSION}"); continue
            if stripped in ('.clear', 'clear()'):
                buf.clear()
                interp = Interpreter()
                setup_readline(interp)
                print(f"  {colour(C_WARN, '>> Session cleared')}")
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
                arrow2 = '->' if not _UNI else '→'
                print(f"  {colour(DIM, arrow2)} {fmted}{ms_str}")

            buf.clear()
            line_num += 1

        except (SyntaxError, RuntimeError) as e:
            buf.clear()
            msg = str(e)
            # Extract line info if present
            m = re.search(r'line (\d+)', msg)
            loc = f" {colour(DIM, f'(line {m.group(1)})')}" if m else ''
            cross = 'x' if not _UNI else '✗'
            print(f"  {colour(C_ERROR, cross)} {colour(C_ERROR, msg)}{loc}")
        except Exception as e:
            buf.clear()
            cross = 'x' if not _UNI else '✗'
            print(f"  {colour(C_ERROR, cross)} {colour(C_ERROR, str(e))}")

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
