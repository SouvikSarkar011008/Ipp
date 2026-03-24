# Test 4: JSON
print("=== JSON ===")
var data = json_parse('{"name": "Alice", "age": 25, "scores": [90, 85, 95]}')
print(data["name"])
print(data["age"])
print(data["scores"])

var obj = {"key": "value", "nums": [1, 2, 3], "nested": {"a": 1}}
print(json_stringify(obj))
print(json_stringify(data))
print(json_stringify({"empty": {}}))

# JSON with special characters
var json2 = '{"msg": "hello\\nworld"}'
print(json_parse(json2)["msg"])