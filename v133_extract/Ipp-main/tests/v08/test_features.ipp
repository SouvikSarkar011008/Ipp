# v0.8.0 Feature Tests

# Nullish coalescing
var n1 = nil ?? "default"
var n2 = "hello" ?? "default"
var n3 = 0 ?? "default"
var n4 = "" ?? "default"
var n5 = false ?? "default"
var n6 = nil ?? nil ?? "fallback"
print("Nullish nil: " + str(n1))
print("Nullish value: " + str(n2))
print("Nullish 0: " + str(n3))
print("Nullish empty: " + str(n4))
print("Nullish false: " + str(n5))
print("Nullish chain: " + str(n6))

# Optional chaining
var obj1 = nil
var o1 = obj1?.foo
var d1 = {"name": "Alice"}
var o2 = d1?.name
var nested = {"a": {"b": {"c": "deep"}}}
var o3 = nested?.a?.b?.c
print("Opt chain nil: " + str(o1))
print("Opt chain dict: " + str(o2))
print("Opt chain nested: " + str(o3))

# Spread operator
var arr1 = [1, 2, 3]
var arr2 = [...arr1]
var arr3 = [0, ...arr1, 4]
var arr4 = [...arr1, ...[4, 5, 6]]
print("Spread copy: " + str(arr2))
print("Spread with elements: " + str(arr3))
print("Spread multiple: " + str(arr4))

# Tuples
var t1 = (1, 2, 3)
var t2 = (1, "hello", true)
var t3 = (42)
var t4 = ()
print("Tuple: " + str(t1))
print("Tuple mixed: " + str(t2))
print("Tuple single: " + str(t3))
print("Tuple empty: " + str(t4))

print("v0.8.0 tests complete!")
