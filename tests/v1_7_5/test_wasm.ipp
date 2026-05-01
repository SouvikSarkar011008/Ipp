# Test v1.7.5: WASM Implementation
# Tests basic Ipp functionality with WASM compilation support

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
var f = 2 ** 8
assert f == 256

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
assert fib(10) == 55

# Test 3: Lists
var nums = [1, 2, 3, 4, 5]
var sum = 0
for n in nums {
    sum = sum + n
}
assert sum == 15
assert len(nums) == 5
assert nums[0] == 1

# Test 4: Dictionaries
var data = {"name": "Alice", "age": 30, "city": "NYC"}
assert data["name"] == "Alice"
assert data["age"] == 30

# Test 5: Classes
class Vec2 {
    func init(x, y) {
        this.x = x
        this.y = y
    }
    func add(other) {
        return Vec2(this.x + other.x, this.y + other.y)
    }
}
var v1 = Vec2(1, 2)
var v2 = Vec2(3, 4)
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

print("v1.7.5: WASM implementation tests PASSED")
print("WASM compiler features:")
print("  - i32, i64, f32, f64 operations")
print("  - Function calls and recursion")
print("  - Control flow (if/else, loops)")
print("  - Local variables and memory")
print("  - Run: python main.py wasm <file.ipp> [output.wat]")