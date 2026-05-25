# v1.8.0 — Fix: str.replace() and String Method Naming (BUG-005, BUG-011)
# BUG-005: kwarg heuristic in _call() treated string args as kwargs
# BUG-011: missing contains/starts_with/ends_with string methods

print("Test 1: replace — basic")
var s = "hello world"
assert s.replace("world", "ipp") == "hello ipp"
assert s.replace("l", "L") == "heLLo worLd"
assert "aaa".replace("a", "b") == "bbb"
print("  PASS")

print("Test 2: replace — edge: arg looks like kwarg key")
# BUG-005: "world" is a valid identifier, old heuristic treated it as kwarg key
var s2 = "the cat sat on the mat"
assert s2.replace("cat", "dog") == "the dog sat on the mat"
assert s2.replace("the", "a") == "a cat sat on a mat"
print("  PASS")

print("Test 3: replace — multiple occurrences")
assert "ababab".replace("a", "x") == "xbxbxb"
assert "test".replace("x", "y") == "test"
print("  PASS")

print("Test 4: contains")
assert s.contains("world") == true
assert s.contains("python") == false
assert s.contains("hello") == true
assert "".contains("") == true
print("  PASS")

print("Test 5: starts_with / ends_with")
assert s.starts_with("hello") == true
assert s.starts_with("world") == false
assert s.starts_with("") == true
assert s.ends_with("world") == true
assert s.ends_with("hello") == false
assert s.ends_with("") == true
print("  PASS")

print("Test 6: existing methods still work")
assert s.upper() == "HELLO WORLD"
assert s.lower() == "hello world"
assert "  hi  ".strip() == "hi"
assert s.find("world") == 6
assert s.split(" ") == ["hello", "world"]
assert s.startswith("hello") == true
assert s.endswith("world") == true
print("  PASS")

print("Test 7: chained method calls")
assert s.upper().lower() == "hello world"
assert s.replace("hello", "hi").upper() == "HI WORLD"
print("  PASS")

print("Test 8: method on literal")
assert "hello world".replace("world", "ipp") == "hello ipp"
assert "test".upper() == "TEST"
print("  PASS")

print("All string method tests passed!")
