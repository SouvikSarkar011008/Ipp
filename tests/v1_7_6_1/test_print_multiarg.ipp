# Test v1.7.6.1: print() with multiple arguments
# User impact: print("Testing:", x) was crashing with kwarg error

var x = 42
var name = "Alice"

# All of these must work
print("value:", x)
print("name:", name, "age:", 30)
print("result:", 1 + 2)
print("bool:", true, "nil:", nil)
print("list:", [1, 2, 3])
print("a", "b", "c")

# Single arg still works
print("hello")
print(42)
print(nil)

# Verify values
assert x == 42
assert name == "Alice"
assert (1 + 2) == 3

print("v1.7.6.1: print multiarg tests PASSED")