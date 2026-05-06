# Test v1.3.4 - Data Formats (JSON, XML, YAML, TOML, CSV)

print("=== Testing v1.3.4 Data Formats ===")

# ====== JSON Tests ======
print("\n--- JSON Tests ---")
var json_str = '{"name": "Alice", "age": 30, "city": "NYC"}'
var json_obj = json_parse(json_str)
print(json_obj)
print(json_obj["name"])
print(json_obj["age"])
assert json_obj["name"] == "Alice"
assert json_obj["age"] == 30

var back_to_json = json_stringify(json_str)
print(back_to_json)
assert back_to_json.len() > 0

# ====== XML Tests ======
print("\n--- XML Tests ---")
var xml_str = "<root><item name='test'>value</item></root>"
var xml_parsed = xml_parse(xml_str)
print(xml_parsed)
var xml_back = xml_to_string(xml_parsed)
print(xml_back)
assert xml_parsed != nil

# ====== YAML Tests ======
print("\n--- YAML Tests ---")
var yaml_str = "name: Alice\nage: 30\ncity: NYC"
var yaml_parsed = yaml_parse(yaml_str)
print(yaml_parsed)
var yaml_back = yaml_to_string(yaml_parsed)
print(yaml_back)
assert yaml_parsed != nil

# ====== TOML Tests ======
print("\n--- TOML Tests ---")
var toml_str = "name = \"Alice\"\nage = 30"
var toml_parsed = toml_parse(toml_str)
print(toml_parsed)
var toml_back = toml_to_string(toml_parsed)
print(toml_back)

# ====== CSV Tests ======
print("\n--- CSV Tests ---")
var csv_data = "name,age,city\nAlice,25,NYC\nBob,30,LA"
var csv_parsed = csv_parse(csv_data)
print(csv_parsed)
print(len(csv_parsed))

var csv_dict = csv_parse_dict(csv_data)
print(csv_dict)

var csv_back = csv_to_string(csv_parsed)
print(csv_back)

# ====== Regex Tests ======
print("\n--- Regex Tests ---")
print(regex_match("hello123", "[a-z]+[0-9]+"))
print(regex_search("abc123def", "[0-9]+"))
print(regex_replace("hello world", "world", "ipp"))

# ====== Hash Tests ======
print("\n--- Hash Tests ---")
print(md5("hello"))
print(sha256("hello"))
print(sha1("hello"))
print(sha512("hello"))
print(hash("test"))

# ====== Base64 Tests ======
print("\n--- Base64 Tests ---")
var encoded = base64_encode("Hello, World!")
print(encoded)
var decoded = base64_decode(encoded)
print(decoded)

# ====== GZIP Tests ======
print("\n--- GZIP Tests ---")
var compressed = gzip_compress("Hello, World!")
print(compressed)
var decompressed = gzip_decompress(compressed)
print(decompressed)

# ====== ZIP Tests ======
print("\n--- ZIP Tests ---")
var zip_data = zip_create({"file1.txt": "content1", "file2.txt": "content2"})
print(zip_data)
var extracted = zip_extract(zip_data)
print(extracted)

print("\n=== v1.3.4 Data Formats tests complete! ===")
