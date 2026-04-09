# Test v1.5.2 - WASM Backend Infrastructure

print("=== Testing v1.5.2 WASM Backend ===")

# Test 1: Basic function to be compiled to WASM
func add(a, b) {
    return a + b
}

var result = add(2, 3)
print("Test 1 - Basic function: " + str(result))
assert(result == 5, "add(2,3) should be 5")

# Test 2: Multiple functions
func multiply(a, b) {
    return a * b
}

func factorial(n) {
    if n <= 1 {
        return 1
    }
    return n * factorial(n - 1)
}

print("Test 2 - Multiple functions: " + str(multiply(4, 5)))
assert(factorial(5) == 120, "factorial(5) should be 120")

# Test 3: Closures
func counter() {
    var count = 0
    func inc() {
        count = count + 1
        return count
    }
    return inc
}

var c = counter()
print("Test 3 - Closures: " + str(c()))
assert(c() == 2, "counter should increment")

# Test 4: Classes
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
print("Test 4 - Classes: " + str(v3.x) + "," + str(v3.y))
assert(v3.x == 4 and v3.y == 6, "Vec2 add should work")

# Test 5: Async functions (from v1.5.0)
async func async_add(a, b) {
    return a + b
}

print("Test 5 - Async functions exist: " + str(type(async_add)))

# Test 6: Built-ins still work
print("Test 6 - Built-ins: " + str(abs(-5)))
assert(abs(-5) == 5, "abs should work")

print("\n=== v1.5.2 WASM Backend tests complete! ===")