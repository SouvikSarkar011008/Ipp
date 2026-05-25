"""v1.7.9.1.13: Verify class-level field declaration error message."""
import sys, os
sys.path.insert(0, os.getcwd())

from ipp.lexer.lexer import tokenize
from ipp.parser.parser import parse

# Test: class-level 'var' should produce the new helpful error message
try:
    tokens = tokenize("class Bad { var x = 0 }")
    ast = parse(tokens)
    print("FAIL: Expected ParseError for class-level var declaration")
    sys.exit(1)
except Exception as e:
    msg = str(e)
    if "not yet supported" in msg and "class-level" in msg.lower():
        print("OK: 'var' error message is correct")
        print(f"  Message: {msg.split(chr(10))[0]}")
    else:
        print(f"FAIL: Wrong error message for 'var': {msg}")
        sys.exit(1)

# Test: class-level 'let' should also produce the new helpful error message
try:
    tokens = tokenize("class Bad { let y = 1 }")
    ast = parse(tokens)
    print("FAIL: Expected ParseError for class-level let declaration")
    sys.exit(1)
except Exception as e:
    msg = str(e)
    if "not yet supported" in msg and "class-level" in msg.lower():
        print("OK: 'let' error message is correct")
        print(f"  Message: {msg.split(chr(10))[0]}")
    else:
        print(f"FAIL: Wrong error message for 'let': {msg}")
        sys.exit(1)

# Test: correct class syntax still parses without error
tokens = tokenize("""
class Counter {
    func init() { self.count = 0 }
    func inc() { self.count = self.count + 1 }
}
""")
ast = parse(tokens)
print("OK: Correct class syntax parses without error")

print("\nv1.7.9.1.13: class field error message tests PASSED")
