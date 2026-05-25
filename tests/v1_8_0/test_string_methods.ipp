# v1.8.0 — Fix: str.replace() and String Method Naming (BUG-005, BUG-011)

print("Test 1: replace")
var s = "hello world"
assert s.replace("world", "ipp") == "hello ipp"
assert s.replace("l", "L") == "heLLo worLd"
assert "aaa".replace("a", "b") == "bbb"
print("  PASS")

print("Test 2: contains")
assert s.contains("world") == true
assert s.contains("python") == false
assert s.contains("hello") == true
print("  PASS")

print("Test 3: starts_with / ends_with")
assert s.starts_with("hello") == true
assert s.starts_with("world") == false
assert s.ends_with("world") == true
assert s.ends_with("hello") == false
print("  PASS")

print("Test 4: existing methods still work")
assert s.upper() == "HELLO WORLD"
assert s.lower() == "hello world"
assert "  hi  ".strip() == "hi"
assert s.find("world") == 6
assert s.split(" ") == ["hello", "world"]
assert s.startswith("hello") == true
assert s.endswith("world") == true
print("  PASS")

print("All string method tests passed!")
