# Test v1.5.5.1 - Matrix Operations

print("=== Testing v1.5.5.1 Matrix Operations ===")

# Test 1: mat4_perspective
print("\n--- Test 1: mat4_perspective ---")
var proj = mat4_perspective(60, 1.5, 0.1, 100)
print("Perspective matrix created")

# Test 2: mat4_look_at
print("\n--- Test 2: mat4_look_at ---")
var eye = vec3(0, 2, 5)
var target = vec3(0, 0, 0)
var up = vec3(0, 1, 0)
var view = mat4_look_at(eye, target, up)
print("LookAt view matrix created")

# Test 3: mat4_translate
print("\n--- Test 3: mat4_translate ---")
var t = mat4_translate(1, 2, 3)
print("Translation matrix created")

# Test 4: mat4_rotate
print("\n--- Test 4: mat4_rotate ---")
var r = mat4_rotate(90, vec3(0, 1, 0))
print("Rotation 90deg around Y axis")

# Test 5: mat4_scale
print("\n--- Test 5: mat4_scale ---")
var s = mat4_scale(2, 2, 2)
print("Scale matrix created")

# Test 6: Combined transformations
print("\n--- Test 6: Combined Transformations ---")
var m = mat4()
var mt = mat4_multiply(m, mat4_translate(5, 0, 0))
var mr = mat4_multiply(mt, mat4_rotate(45, vec3(0, 1, 0)))
var ms = mat4_multiply(mr, mat4_scale(1.5, 1.5, 1.5))
print("Combined transform created")

# Test 7: Basic functionality
print("\n--- Test 7: Basic Functionality ---")
print("sum([1,2,3]) = " + str(sum([1, 2, 3])))

print("\n=== v1.5.5.1 Tests Complete ===")
print("New in v1.5.5.1:")
print("  mat4_perspective(fov, aspect, near, far) - perspective projection")
print("  mat4_look_at(eye, target, up)           - view matrix")
print("  mat4_translate(x, y, z)                 - translation matrix")
print("  mat4_rotate(angle, axis)                - rotation matrix")
print("  mat4_scale(x, y, z)                     - scale matrix")