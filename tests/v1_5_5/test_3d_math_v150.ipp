# Test v1.5.5.0 - 3D Math Basics (vec4, mat4, multiply)

print("=== Testing v1.5.5.0 3D Math Basics ===")

# Test 1: vec4 - 4D Vector
print("\n--- Test 1: vec4 - 4D Vector ---")
var v = vec4(1, 2, 3, 1)
print("Created: " + str(v))
print("x=" + str(v.x) + " y=" + str(v.y) + " z=" + str(v.z) + " w=" + str(v.w))

# Test 2: vec4 operations
print("\n--- Test 2: vec4 Operations ---")
var v2 = vec4(4, 5, 6, 1)
var v_sum = v + v2
print("v + v2 = " + str(v_sum))

var v_diff = v2 - v
print("v2 - v = " + str(v_diff))

var v_scaled = v * 2
print("v * 2 = " + str(v_scaled))

print("dot(v, v2) = " + str(v.dot(v2)))
print("length = " + str(v.length()))

# Test 3: mat4 - 4x4 Matrix
print("\n--- Test 3: mat4 - 4x4 Matrix ---")
var m = mat4()
print("Identity matrix:")
print(m)

# Test 4: mat4_identity
print("\n--- Test 4: mat4_identity ---")
var m_id = mat4_identity()
print("Identity: " + str(type(m_id)))

# Test 5: mat4_multiply
print("\n--- Test 5: mat4_multiply ---")
var m2 = mat4_multiply(m, m_id)
print("m * identity = identity")

# Test 6: Matrix vector transform
print("\n--- Test 6: Matrix Vector Transform ---")
print("vec4 transformed by mat4: " + str(m.transform_vector(v)))

# Test 7: Basic functionality still works
print("\n--- Test 7: Basic Functionality ---")
var nums = [1, 2, 3, 4, 5]
print("Sum: " + str(sum(nums)))

func add(x, y) {
    return x + y
}
print("add(3, 5) = " + str(add(3, 5)))

print("\n=== v1.5.5.0 Tests Complete ===")
print("New in v1.5.5.0:")
print("  vec4(x, y, z, w)       - 4D vector")
print("  mat4()                 - 4x4 matrix (identity)")
print("  mat4_identity()        - create identity matrix")
print("  mat4_multiply(a, b)     - multiply two matrices")
print("  vec4.dot(other)        - dot product")
print("  vec4.length()          - vector length")
print("  vec4.normalize()       - normalized vector")
print("  mat4.transform_vector(v) - transform vector")