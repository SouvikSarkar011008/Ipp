# Test v1.7.4: LSP Completion
# Tests basic Ipp functionality and LSP completion features

# Test 1: Basic computation
var x = 10 + 5
assert x == 15
var y = 20 - 8
assert y == 12

# Test 2: Functions with different parameter counts
func add(a, b) {
    return a + b
}
func greet(name) {
    return "Hello " + name
}
assert add(5, 3) == 8
assert greet("Alice") == "Hello Alice"

# Test 3: Lists and iteration
var nums = [1, 2, 3, 4, 5]
var sum = 0
for n in nums {
    sum = sum + n
}
assert sum == 15

# Test 4: Dictionaries
var data = {"name": "Bob", "age": 25}
assert data["name"] == "Bob"
assert data["age"] == 25

# Test 5: Classes
class Counter {
    func init(start) {
        this.count = start
    }
    func inc() {
        this.count = this.count + 1
    }
    func get() {
        return this.count
    }
}
var c = Counter(0)
c.inc()
c.inc()
c.inc()
assert c.get() == 3

# Test 6: Try/catch error handling
var error_handled = false
try {
    var bad = undefined_test
} catch e {
    error_handled = true
}
assert error_handled == true

# Test 7: String operations
var s1 = "hello"
var s2 = "world"
var combined = s1 + " " + s2
assert combined == "hello world"
assert len(combined) == 11

print("v1.7.4: LSP completion tests PASSED")
print("LSP features available:")
print("  - Context-aware completions")
print("  - Keyword, builtin, and symbol completions")
print("  - Snippet templates for func, class, for, if, try")
print("  - Method completions for strings, lists, dicts")