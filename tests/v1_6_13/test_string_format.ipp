# Test v1.6.13: String Format Method
# Uses format() builtin function or string.format() method

# Test basic positional format with builtin
var r1 = format("Hello {}!", "World")
assert r1 == "Hello World!"

# Test with multiple positional args
var r2 = format("x={}, y={}", 3, 4)
assert r2 == "x=3, y=4"

# Test with string concatenation in format
var name = "Bob"
var r3 = format("Hello {}!", name)
assert r3 == "Hello Bob!"

# Test empty format (no args)
var r4 = format("No args")
assert r4 == "No args"

# Test format with numbers
var r5 = format("Value: {}", 42)
assert r5 == "Value: 42"

# Test string.format() method (using builtin)
var r6 = "Hello {}".format("World")
assert r6 == "Hello World!"

print("v1.6.13: String Format Method tests PASSED")