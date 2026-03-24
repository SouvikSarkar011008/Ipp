var data = json_parse('{"name": "Alice", "age": 25}')
print(data["name"])
print(data["age"])

var obj = {"key": "value", "nums": [1, 2, 3]}
print(json_stringify(obj))
print(json_stringify(data))