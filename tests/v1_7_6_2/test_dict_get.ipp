var d = {"name": "Alice", "age": 30, "city": "NYC"}

# get existing key
assert d.get("name") == "Alice"
assert d.get("age") == 30

# get missing key without default returns nil
var r = d.get("missing")
assert r == nil

# get missing key with default
assert d.get("missing", 0) == 0
assert d.get("country", "unknown") == "unknown"
assert d.get("name", "default") == "Alice"

# string keys that look like identifiers
var d2 = {"hello": 1, "world": 2}
assert d2.get("hello", 0) == 1
assert d2.get("nope", 99) == 99