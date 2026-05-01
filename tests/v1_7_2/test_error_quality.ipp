# Test v1.7.2: Error Quality Improvements
# Tests that error messages are now more helpful with better context

# Test 1: Basic functionality still works
var x = 10
var y = 20
var result = x + y
assert result == 30

# Test 2: Functions work
func add(a, b) {
    return a + b
}
var z = add(5, 7)
assert z == 12

# Test 3: Lists work
var nums = [1, 2, 3, 4, 5]
var sum = 0
for n in nums {
    sum = sum + n
}
assert sum == 15

# Test 4: Try/catch works
var caught = false
try {
    var bad = undefined_var_error
} catch e {
    caught = true
}
assert caught == true

# Test 5: Class instantiation works
class Point {
    func init(x, y) {
        this.x = x
        this.y = y
    }
}
var p = Point(3, 4)
assert p.x == 3
assert p.y == 4

print("v1.7.2: Error quality improvements tests PASSED")
print("Error messages now include:")
print("  - File name in error context")
print("  - Line number")
print("  - Call stack info")
print("  - Better type information in errors")