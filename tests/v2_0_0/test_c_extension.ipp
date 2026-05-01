# Test v2.0.0: C Extension VM
# Tests basic Ipp functionality and C extension support

# Test 1: Basic arithmetic
var a = 10 + 5
assert a == 15
var b = 20 - 8
assert b == 12
var c = 6 * 7
assert c == 42
var d = 20 / 4
assert d == 5
var e = 17 % 5
assert e == 2
var f = 2 ** 6
assert f == 64

# Test 2: Functions
func add(a, b) {
    return a + b
}
func multiply(a, b) {
    return a * b
}
func fib(n) {
    if n <= 1 {
        return n
    }
    return fib(n - 1) + fib(n - 2)
}
assert add(5, 3) == 8
assert multiply(4, 5) == 20
assert fib(8) == 21

# Test 3: Lists
var nums = [1, 2, 3, 4, 5]
var sum = 0
for n in nums {
    sum = sum + n
}
assert sum == 15
assert len(nums) == 5
assert nums[0] == 1
assert nums[4] == 5

# Test 4: Dictionaries
var data = {"name": "Alice", "age": 30, "city": "NYC"}
assert data["name"] == "Alice"
assert data["age"] == 30

# Test 5: Classes
class Point {
    func init(x, y) {
        this.x = x
        this.y = y
    }
    func add(other) {
        return Point(this.x + other.x, this.y + other.y)
    }
}
var v1 = Point(1, 2)
var v2 = Point(3, 4)
var v3 = v1.add(v2)
assert v3.x == 4
assert v3.y == 6

# Test 6: Try/catch
var caught = false
try {
    var bad = undefined_test
} catch e {
    caught = true
}
assert caught == true

# Test 7: String operations
var s1 = "hello"
var s2 = "world"
assert s1 + " " + s2 == "hello world"
assert len("test") == 4

# Test 8: Control flow
var result = 0
if true {
    result = 1
}
assert result == 1

if false {
    result = 2
} else {
    result = 3
}
assert result == 3

print("v2.0.0: C extension VM tests PASSED")
print("C Extension features:")
print("  - Core VM data structures in C")
print("  - Stack-based bytecode execution")
print("  - Frame management")
print("  - Opcode implementations")
print("  - Run: python setup.py build_ext --inplace")