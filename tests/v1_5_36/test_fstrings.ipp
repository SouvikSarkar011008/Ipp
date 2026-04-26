# Test v1.5.36: F-strings

var name = "World"
assert f"Hello {name}!" == "Hello World!"

var x = 10
var y = 20
assert f"{x} + {y} = {x + y}" == "10 + 20 = 30"

var items = [1, 2, 3]
assert f"count: {len(items)}" == "count: 3"

# Test escaped braces
assert f"{{escaped braces}}" == "{escaped braces}"

print("v1.5.36: F-strings tests PASSED")