# Test v1.3.4 - Collections & Data Structures

print("=== Testing v1.3.4 Collections & Data Structures ===")

# ====== Set Tests ======
print("\n--- Set Tests ---")
var s = set([1, 2, 3])
print(s)
s.add(4)
print(s)
print(s.contains(3))
print(s.contains(5))
assert s.contains(3) == true
assert s.contains(5) == false
s.remove(2)
print(s)
print(s.len())
assert s.len() == 3
s.clear()
print(s.len())
assert s.len() == 0

# ====== Deque Tests ======
print("\n--- Deque Tests ---")
var dq = deque([1, 2, 3])
print(dq)
dq.push_back(4)
print(dq)
print(dq.front())
print(dq.back())
print(dq.len())
var popped = dq.pop_front()
print("Popped:", popped)
print(dq)
assert dq.front() == 2
assert dq.back() == 4
assert popped == 1

# ====== Ordered Dict Tests ======
print("\n--- Ordered Dict Tests ---")
var od = ordict()
print(od)

# ====== Dict Operations ======
print("\n--- Dict Operations ---")
var d = {"a": 1, "b": 2, "c": 3}
print(keys(d))
print(values(d))
print(items(d))
print(has_key(d, "a"))
print(has_key(d, "z"))

# ====== UUID Tests ======
print("\n--- UUID Tests ---")
var uuid = uuid4()
print(uuid)
var uuid_nil_val = uuid_nil()
print(uuid_nil_val)

# ====== DateTime Tests ======
print("\n--- DateTime Tests ---")
var now = datetime()
print(now)
print(now.year())
print(now.month())
print(now.day())
print(now.hour())
print(now.minute())
print(now.second())

# ====== Path Tests ======
print("\n--- Path Tests ---")
print(path_dirname("/home/user/file.txt"))
print(path_basename("/home/user/file.txt"))
print(path_join("folder", "subfolder", "file.txt"))
print(path_exists("tests/v1_3_4/test_collections.ipp"))

# ====== OS Tests ======
print("\n--- OS Tests ---")
print(os_platform())
print(os_cwd())

# ====== URL Tests ======
print("\n--- URL Tests ---")
var url = "https://example.com/path?query=value#fragment"
var parsed = url_parse(url)
print(parsed["scheme"])
print(parsed["netloc"])
print(parsed["path"])
print(url_encode("hello world"))
print(url_decode("hello%20world"))

# ====== Time Tests ======
print("\n--- Time Tests ---")
var t = time()
print(t)
print(clock())

print("\n=== v1.3.4 Collections & Data Structures tests complete! ===")
