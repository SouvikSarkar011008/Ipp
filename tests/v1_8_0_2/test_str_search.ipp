# v1.8.0.2 — Fix: str.count(), str.rfind(), str.rindex() Methods

print("Test 1: count")
var s = "hello world hello"
assert s.count("hello") == 2
assert s.count("xyz") == 0
print("  PASS")

print("Test 2: rfind")
assert s.rfind("hello") == 12
assert s.find("world") == 6
print("  PASS")

print("Test 3: rindex")
assert s.index("world") == 6
print("  PASS")

print("All str search tests passed!")
