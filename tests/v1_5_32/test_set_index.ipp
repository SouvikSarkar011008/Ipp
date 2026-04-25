# Test v1.5.32: SET_INDEX stack order fix
# Bug: SET_INDEX was popping wrong order (obj, idx, value instead of value, idx, obj)

let a = [1, 2, 3]
a[0] = 10
assert a[0] == 10
assert a[1] == 2
assert a[2] == 3

# Test dict
let d = {"x": 1}
d["x"] = 99
assert d["x"] == 99

print("v1.5.32: SET_INDEX stack fix tests PASSED")