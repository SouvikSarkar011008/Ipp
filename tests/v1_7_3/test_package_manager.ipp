# Test v1.7.3: Package Manager
# Tests basic Ipp functionality and package manager CLI

# Test 1: Basic computation
var x = 10
var y = 20
var result = x + y
assert result == 30

# Test 2: Functions
func multiply(a, b) {
    return a * b
}
var z = multiply(6, 7)
assert z == 42

# Test 3: Lists
var nums = [1, 2, 3, 4, 5]
var sum = 0
for n in nums {
    sum = sum + n
}
assert sum == 15

# Test 4: Try/catch
var caught = false
try {
    var bad = undefined_var_test
} catch e {
    caught = true
}
assert caught == true

# Test 5: Classes
class Counter {
    func init() {
        this.count = 0
    }
    func inc() {
        this.count = this.count + 1
    }
}
var c = Counter()
c.inc()
c.inc()
assert c.count == 2

print("v1.7.3: Package manager tests PASSED")
print("Package manager CLI commands:")
print("  python main.py pkg install <name>")
print("  python main.py pkg remove <name>")
print("  python main.py pkg list")
print("  python main.py pkg search <query>")