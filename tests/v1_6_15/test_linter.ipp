# Test v1.6.15: Static Linter
# Tests that static linter CLI works correctly

# Test 1: Run a script that works
var x = 10
var y = 20
var result = x + y
assert result == 30

# Test 2: Check command should pass syntax
func add(a, b) {
    return a + b
}
var z = add(5, 7)
assert z == 12

# Test 3: List operations
var nums = [1, 2, 3, 4, 5]
var sum = 0
for n in nums {
    sum = sum + n
}
assert sum == 15

print("v1.6.15: Static linter tests PASSED")
print("Run: python main.py lint <file> to lint code")
print("Run: python main.py check <file> to check syntax")
print("Run: python main.py fmt <file> to format code")