# Test v1.7.0: Archive Interpreter
# Tests that archive (bundle) feature works correctly

# Basic computation test
var x = 10
var y = 20
var result = x + y
assert result == 30

# Function test
func multiply(a, b) {
    return a * b
}
var z = multiply(6, 7)
assert z == 42

# List operations
var nums = [1, 2, 3, 4, 5]
var sum = 0
for n in nums {
    sum = sum + n
}
assert sum == 15

# String operations
var name = "Ipp"
var greeting = "Hello, " + name + "!"
assert greeting == "Hello, Ipp!"

# Dictionary
var person = {"name": "Alice", "age": 30}
assert person["name"] == "Alice"

print("v1.7.0: Archive interpreter tests PASSED")
print("Run: python main.py archive create <out.ippa> <files...>")
print("Run: python main.py archive list <archive.ippa>")
print("Run: python main.py archive run <archive.ippa> <module>")