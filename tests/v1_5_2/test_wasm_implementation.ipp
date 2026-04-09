# Test v1.5.2a - WASM Backend Implementation

print("=== Testing v1.5.2a WASM Backend ===")

# Test 1: Simple function compilation
print("Test 1 - Simple function compilation...")
func add(a, b) {
    return a + b
}
var result = add(10, 20)
assert(result == 30, "add(10,20) should be 30")
print("  PASS")

# Test 2: Multiple functions
print("Test 2 - Multiple functions...")
func multiply(a, b) {
    return a * b
}
func divide(a, b) {
    if b != 0 {
        return a / b
    }
    return 0
}
assert(multiply(3, 4) == 12, "multiply should work")
assert(divide(10, 2) == 5, "divide should work")
print("  PASS")

# Test 3: Recursion (factorial)
print("Test 3 - Recursion...")
func factorial(n) {
    if n <= 1 {
        return 1
    }
    return n * factorial(n - 1)
}
assert(factorial(5) == 120, "factorial(5) should be 120")
print("  PASS")

# Test 4: Closures
print("Test 4 - Closures...")
func make_counter() {
    var count = 0
    func inc() {
        count = count + 1
        return count
    }
    return inc
}
var counter = make_counter()
assert(counter() == 1, "first call should return 1")
assert(counter() == 2, "second call should return 2")
print("  PASS")

# Test 5: Classes
print("Test 5 - Classes...")
class Calculator {
    func init() {
        this.result = 0
    }
    func add(n) {
        this.result = this.result + n
        return this.result
    }
    func subtract(n) {
        this.result = this.result - n
        return this.result
    }
}
var calc = Calculator()
assert(calc.add(10) == 10, "add should work")
assert(calc.subtract(3) == 7, "subtract should work")
print("  PASS")

# Test 6: Async functions still work
print("Test 6 - Async functions...")
async func async_multiply(a, b) {
    return a * b
}
var coro = async_multiply(5, 6)
var async_result = async_run(coro)
assert(async_result == 30, "async function should work")
print("  PASS")

# Test 7: Built-in functions
print("Test 7 - Built-ins...")
assert(abs(-100) == 100, "abs should work")
assert(len([1, 2, 3]) == 3, "len should work")
assert(str(42) == "42", "str should work")
print("  PASS")

# Test 8: Complex expressions
print("Test 8 - Complex expressions...")
var x = 10
var y = 20
var z = x + y * 2
assert(z == 50, "expression should evaluate correctly")
print("  PASS")

# Test 9: Lists work
print("Test 9 - Lists...")
var lst = [1, 2, 3, 4, 5]
assert(len(lst) == 5, "list length should work")
assert(lst[0] == 1, "list indexing should work")
print("  PASS")

# Test 10: Dictionary
print("Test 10 - Dictionary...")
var d = {"a": 1, "b": 2}
assert(d["a"] == 1, "dict access should work")
d["c"] = 3
assert(d["c"] == 3, "dict assignment should work")
print("  PASS")

# Test 11: For loop with range (FIXED - was removed earlier)
print("Test 11 - For loop with range...")
var sum = 0
for i in range(1, 6) {
    sum = sum + i
}
assert(sum == 15, "for loop with range should sum 1+2+3+4+5 = 15")
print("  PASS")

# Test 12: While loop (FIXED)
print("Test 12 - While loop...")
var count = 0
var n = 3
while n > 0 {
    count = count + 1
    n = n - 1
}
assert(count == 3, "while loop should run 3 times")
print("  PASS")

print("\n=== v1.5.2a WASM Backend tests complete! ===")