"""v1.7.9.1.13+v1.7.9.1.16: Verify class-level field declarations (BUG-024 part B).

Before v1.7.9.1.16 these produced errors; now they are valid syntax.
"""
import sys, os
sys.path.insert(0, os.getcwd())

from ipp.lexer.lexer import tokenize
from ipp.parser.parser import parse

errors = 0

def check_ok(source, desc):
    """Parse `source`, expect no error."""
    global errors
    try:
        tokens = tokenize(source)
        ast = parse(tokens)
        print(f"OK: {desc}")
    except Exception as e:
        print(f"FAIL: {desc} — unexpected {type(e).__name__}: {e}")
        errors += 1

# ── Class-level var/let should now parse successfully ────────────

check_ok("class Good { var x = 0 }", "var with initializer")
check_ok("class Good { var x }", "var without initializer")
check_ok("class Good { let x = 1 }", "let with initializer")
check_ok("class Good { let x }", "let without initializer")

# ── static var/let (silently accepted, not truly static) ─────────

check_ok("class Good { static var x = 0 }", "static var with initializer")
check_ok("class Good { static let x = 0 }", "static let with initializer")

# ── Multiple var/let declarations ─────────────────────────────────

check_ok("class Good { var a = 1 var b = 2 }", "sequential var declarations")
check_ok("class Good { let a = 1 let b = 2 }", "sequential let declarations")
check_ok("class Good { var a = 1 let b = 2 }", "mixed var and let")

# ── var/let before valid methods ──────────────────────────────────

check_ok("""class Good {
    var x = 0
    func init() { self.x = 0 }
    func get() { return self.x }
}""", "var before method")

# ── Ensure old misleading message is GONE ─────────────────────────

# The old message was "Expect '}' after class body"
# Verify it never appears for class-level var/let
import re
old_msg_pattern = r"Expect.*\}.*after class body"
for src, desc in [
    ("class Bad { var x = 0 }", "var x"),
    ("class Bad { let x = 0 }", "let x"),
    ("class Bad { static var x = 0 }", "static var x"),
]:
    try:
        tokens = tokenize(src)
        ast = parse(tokens)
    except SyntaxError as e:
        if re.search(old_msg_pattern, str(e), re.IGNORECASE):
            print(f"FAIL: {desc} — still shows old misleading message: {e}")
            errors += 1
        else:
            print(f"OK: {desc} — old message not present")

# ── Things that should NOT be affected ─────────────────────────────

check_ok("""
class Counter {
    func init() { self.count = 0 }
    func inc() { self.count = self.count + 1 }
}
""", "normal class with init and methods")

check_ok("""
class Animal { func init(n) { self.name = n } }
class Dog : Animal { func speak() { return self.name } }
""", "class with inheritance")

check_ok("""
class Util { static func add(a, b) { return a + b } }
""", "class with static method")

check_ok("""
class Vec2 {
    func init(x, y) { self.x = x; self.y = y }
    func __add__(o) { return Vec2(self.x + o.x, self.y + o.y) }
}
""", "class with operator overloading")

check_ok("""
class Empty {}
""", "empty class body")

# ── Summmary ──────────────────────────────────────────────────────

if errors:
    print(f"\nFAILED: {errors} test(s) failed")
    sys.exit(1)
else:
    print("\nv1.7.9.1.13+v1.7.9.1.16: class field declaration tests PASSED")
