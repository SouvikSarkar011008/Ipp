# Test v1.3.4 - String Functions

print("=== Testing v1.3.4 String Functions ===")

# ====== Basic String Operations ======
print("\n--- Basic String Operations ---")
var s = "Hello, World!"
print(s)
print(upper(s))
print(lower(s))
print(len(s))
assert upper(s) == "HELLO, WORLD!"
assert lower(s) == "hello, world!"
assert len(s) == 13

# ====== Split/Join ======
print("\n--- Split/Join ---")
var parts = split("a,b,c", ",")
print(parts)
var joined = join(["x", "y", "z"], "-")
print(joined)
assert len(parts) == 3
assert joined == "x-y-z"

# ====== Strip ======
print("\n--- Strip ---")
var spaced = "  hello  "
print(strip(spaced))
assert strip(spaced) == "hello"

# ====== Replace ======
print("\n--- Replace ---")
print(replace("hello world", "world", "ipp"))
print(replace_all("aaa", "a", "b"))
assert replace("hello world", "world", "ipp") == "hello ipp"
assert replace_all("aaa", "a", "b") == "bbb"

# ====== Starts/Ends With ======
print("\n--- Starts/Ends With ---")
print(starts_with("hello", "hel"))
print(ends_with("hello", "lo"))
print(startswith("hello", "hel"))
print(endswith("hello", "lo"))
assert starts_with("hello", "hel") == true
assert ends_with("hello", "lo") == true

# ====== Find/Index ======
print("\n--- Find/Index ---")
print(find("hello world", "world"))
print(index_of("hello world", "world"))
print(char_at("hello", 1))
assert find("hello world", "world") == 6
assert index_of("hello world", "world") == 6
assert char_at("hello", 1) == "e"

# ====== Substring ======
print("\n--- Substring ---")
print(substring("hello world", 0, 5))
assert substring("hello world", 0, 5) == "hello"

# ====== Count ======
print("\n--- Count ---")
print(count("hello", "l"))
print(contains("hello", "ell"))
assert count("hello", "l") == 2
assert contains("hello", "ell") == true

# ====== Split Lines ======
print("\n--- Split Lines ---")
var lines = split_lines("line1\nline2\nline3")
print(lines)
assert len(lines) == 3

# ====== ASCII ======
print("\n--- ASCII ---")
print(ascii("A"))
print(from_ascii(65))
assert ascii("A") == 65
assert from_ascii(65) == "A"

print("\n=== v1.3.4 String Functions tests complete! ===")
