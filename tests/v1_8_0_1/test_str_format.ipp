# v1.8.0.1 — Fix: str.format() Named Placeholders Work

print("Test 1: Basic positional")
assert "Hello {}!".format("World") == "Hello World!"
print("  PASS")

print("Test 2: Indexed positional")
assert "x={0}, y={1}".format(3, 4) == "x=3, y=4"
assert "{0} + {1} = {2}".format(1, 2, 3) == "1 + 2 = 3"
print("  PASS")

print("Test 3: Named placeholder")
assert "{name} says hi".format(name="Alice") == "Alice says hi"
print("  PASS")

print("Test 4: Format specifiers")
assert "Price: ${:.2f}".format(9.99) == "Price: $9.99"
assert "{:>10}".format("right") == "     right"
print("  PASS")

print("Test 5: Multiple named placeholders")
assert "{a} + {b} = {c}".format(a=1, b=2, c=3) == "1 + 2 = 3"
print("  PASS")

print("Test 6: format chained after upper")
var s = "hello {NAME}"
assert s.upper().format(NAME="World") == "HELLO World"
print("  PASS")

print("All str.format tests passed!")
