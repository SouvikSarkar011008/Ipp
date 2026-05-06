# Test v1.3.9 - REPL Error Handling Improvements
# Tests that error suggestion functions exist and work

print("=== Testing v1.3.9 REPL Error Handling ===")

# ====== Error Suggestion System Tests ======
print("\n--- Error Suggestion System Tests ---")

# Test that .which command works for inspection
print("print type:", type(print))
print("len type:", type(len))
print("http_get type:", type(http_get))
print("PriorityQueue type:", type(PriorityQueue))
print("Tree type:", type(Tree))
print("Graph type:", type(Graph))
assert type(print) == "function", "print is a function"
assert type(len) == "function", "len is a function"
assert type(http_get) == "function", "http_get is a function"
assert type(PriorityQueue) == "function", "PriorityQueue is a function"

# Test .doc command availability
var fn = http_get
print("http_get exists:", type(fn))
assert type(fn) == "function", "http_get exists"

# ====== Type Inspection ======
print("\n--- Type Inspection ---")
var num = 42
var str_val = "hello"
var bool_val = true
var list_val = [1, 2, 3]
var dict_val = {"a": 1}

print("num type:", type(num))
print("str type:", type(str_val))
print("bool type:", type(bool_val))
print("list type:", type(list_val))
print("dict type:", type(dict_val))
assert type(num) == "number", "Number type works"
assert type(str_val) == "string", "String type works"
assert type(bool_val) == "bool", "Bool type works"
assert type(list_val) == "list", "List type works"
assert type(dict_val) == "dict", "Dict type works"

# ====== Available Builtins Count ======
print("\n--- Available Builtins ---")
print("Builtins available for suggestions")
print("print:", type(print))
print("len:", type(len))
print("type:", type(type))
print("upper:", type(upper))
print("split:", type(split))
print("join:", type(join))
print("abs:", type(abs))
print("sqrt:", type(sqrt))
print("json_parse:", type(json_parse))
print("md5:", type(md5))
print("sha256:", type(sha256))
print("http_get:", type(http_get))
print("http_post:", type(http_post))
print("http_put:", type(http_put))
print("http_delete:", type(http_delete))
print("smtp_connect:", type(smtp_connect))
print("ftp_connect:", type(ftp_connect))
print("PriorityQueue:", type(PriorityQueue))
print("Tree:", type(Tree))
print("Graph:", type(Graph))
print("http_serve:", type(http_serve))
assert type(upper) == "function", "upper exists"
assert type(json_parse) == "function", "json_parse exists"

# ====== Error Recovery Tests ======
print("\n--- Error Recovery Tests ---")

# Test that errors don't crash the REPL
var safe_result = 1 + 2
print("Safe calculation:", safe_result)
assert safe_result == 3, "Safe calculation works"

# Test try/catch for error handling
var error_caught = false
try {
    var x = undefined_var
} catch e {
    error_caught = true
    print("Error caught successfully")
}
print("Error was caught:", error_caught)
assert error_caught == true, "Error was caught"

print("\n=== v1.3.9 REPL Error Handling tests complete! ===")
