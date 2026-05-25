# v1.8.0.3 — Enhancement: str * n Repetition Operator

print("Test 1: String repetition")
assert "x" * 5 == "xxxxx"
assert "ab" * 3 == "ababab"
assert "" * 10 == ""
print("  PASS")

print("Test 2: Integer on left")
assert 3 * "x" == "xxx"
assert 0 * "hello" == ""
print("  PASS")

print("Test 3: Works in expressions")
var sep = "-"
assert sep * 3 == "---"
var bar = "=" * 10
assert bar == "=========="
print("  PASS")

print("All str repeat tests passed!")
