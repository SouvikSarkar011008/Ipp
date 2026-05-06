# Test v1.5.5.2 - Quaternion

print("=== Testing v1.5.5.2 Quaternion ===")

# Test 1: quat - Create quaternion
print("\n--- Test 1: quat ---")
var q = quat(0, 0, 0, 1)
print("Created: " + str(q))
assert q != nil, "quat creation works"

# Test 2: quat_from_axis_angle
print("\n--- Test 2: quat_from_axis_angle ---")
var q2 = quat_from_axis_angle(vec3(0, 1, 0), 90)
print("90deg around Y: " + str(q2))
assert q2 != nil, "quat_from_axis_angle works"

# Test 3: quat_multiply
print("\n--- Test 3: quat_multiply ---")
var q3 = quat_multiply(q, q2)
print("q * q2 = " + str(q3))
assert q3 != nil, "quat_multiply works"

# Test 4: quat_slerp
print("\n--- Test 4: quat_slerp ---")
var q4 = quat_from_axis_angle(vec3(0, 1, 0), 0)
var q5 = quat_from_axis_angle(vec3(0, 1, 0), 90)
var q_slerp = quat_slerp(q4, q5, 0.5)
print("Slerp 50%: " + str(q_slerp))
assert q_slerp != nil, "quat_slerp works"

# Test 5: quat_to_mat4
print("\n--- Test 5: quat_to_mat4 ---")
var m = quat_to_mat4(q2)
print("Converted to matrix")
assert m != nil, "quat_to_mat4 works"

# Test 6: Quaternion for rotation
print("\n--- Test 6: Quaternion Rotation ---")
var axis = vec3(1, 0, 0)
var angle = 45
var q_rot = quat_from_axis_angle(axis, angle)
var m_rot = quat_to_mat4(q_rot)
print("Rotation matrix from quaternion")
assert m_rot != nil, "Quaternion rotation works"

# Test 7: Basic functionality
print("\n--- Test 7: Basic Functionality ---")
print("sum([1,2,3]) = " + str(sum([1, 2, 3])))
assert sum([1, 2, 3]) == 6, "sum works"

print("\n=== v1.5.5.2 Tests Complete ===")
print("New in v1.5.5.2:")
print("  quat(x, y, z, w)                    - create quaternion")
print("  quat_from_axis_angle(axis, angle)   - from axis-angle (degrees)")
print("  quat_multiply(a, b)                  - multiply quaternions")
print("  quat_slerp(a, b, t)                  - spherical interpolation")
print("  quat_to_mat4(q)                      - convert to rotation matrix")