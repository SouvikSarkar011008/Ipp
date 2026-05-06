# Test v1.6.8: Matrix4x4 and Quaternion
var m = mat4_identity()
print(m)
assert len(m) == 16

var v = vec4(1, 0, 0, 1)
print(v)
assert v[0] == 1

var q = quat(0, 0, 0, 1)
print(q)
assert len(q) == 4

print("v1.6.8: Matrix4x4 and Quaternion tests PASSED")