# Test 8: Multiline Support
print("=== Multiline ===")

func multiline_add(
    a,
    b,
    c
) {
    return a + b + c
}
print(multiline_add(1, 2, 3))

var result = (
    1 + 2 + 3
)
print(result)

var obj = {
    "key1": "value1",
    "key2": "value2",
    "key3": "value3"
}
print(obj)

print(multiline_add(
    10,
    20,
    30
))