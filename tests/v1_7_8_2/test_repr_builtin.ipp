# Test 1: repr() with basic types
var r1 = repr("hello")
print("repr('hello') = " + r1)
assert r1 == '"hello"'

var r2 = repr(42)
print("repr(42) = " + r2)
assert r2 == "42"

var r3 = repr(3.14)
print("repr(3.14) = " + r3)
assert r3 == "3.14"

var r4 = repr(true)
print("repr(true) = " + r4)
assert r4 == "true"

var r5 = repr(false)
print("repr(false) = " + r5)
assert r5 == "false"

var r6 = repr(nil)
print("repr(nil) = " + r6)
assert r6 == "nil"

print("Basic types test passed!")