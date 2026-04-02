# Test v1.3.4 - String Functions

print("=== Testing v1.3.4 String Functions ===")

# ====== Basic String Operations ======
print("\n--- Basic String Operations ---")
var s = "Hello, World!"
print(s)
print(upper(s))
print(lower(s))
print(len(s))

# ====== Split/Join ======
print("\n--- Split/Join ---")
var parts = split("a,b,c", ",")
print(parts)
var joined = join(["x", "y", "z"], "-")
print(joined)

# ====== Strip ======
print("\n--- Strip ---")
var spaced = "  hello  "
print(strip(spaced))

# ====== Replace ======
print("\n--- Replace ---")
print(replace("hello world", "world", "ipp"))
print(replace_all("aaa", "a", "b"))

# ====== Starts/Ends With ======
print("\n--- Starts/Ends With ---")
print(starts_with("hello", "hel"))
print(ends_with("hello", "lo"))
print(startswith("hello", "hel"))
print(endswith("hello", "lo"))

# ====== Find/Index ======
print("\n--- Find/Index ---")
print(find("hello world", "world"))
print(index_of("hello world", "world"))
print(char_at("hello", 1))

# ====== Substring ======
print("\n--- Substring ---")
print(substring("hello world", 0, 5))

# ====== Count ======
print("\n--- Count ---")
print(count("hello", "l"))
print(contains("hello", "ell"))

# ====== Split Lines ======
print("\n--- Split Lines ---")
var lines = split_lines("line1\nline2\nline3")
print(lines)

# ====== ASCII ======
print("\n--- ASCII ---")
print(ascii("A"))
print(from_ascii(65))

print("\n=== v1.3.4 String Functions tests complete! ===")
