# Test v1.5.6 - 3D Primitives

print("=== Testing v1.5.6 3D Primitives ===")

# Test 1: mesh_cube
print("\n--- Test 1: mesh_cube ---")
var c = mesh_cube(2)
print("Cube: " + str(c))

# Test 2: mesh_sphere
print("\n--- Test 2: mesh_sphere ---")
var s = mesh_sphere(1, 8, 4)
print("Sphere: " + str(s))

# Test 3: mesh_plane
print("\n--- Test 3: mesh_plane ---")
var p = mesh_plane(4, 3)
print("Plane: " + str(p))

# Test 4: Use in scene
print("\n--- Test 4: Scene with Primitives ---")
var scene = scene("game")
var cam = camera("main", 60, 1.5, 0.1, 100)
scene.add(cam)
scene.set_camera(cam)
scene.add(c)
scene.add(s)
scene.add(p)
print("Scene with 3 primitives: " + str(scene.render()))

# Test 5: Basic functionality
print("\n--- Test 5: Basic Functionality ---")
print("sum([1,2,3]) = " + str(sum([1, 2, 3])))

print("\n=== v1.5.6 Tests Complete ===")
print("New in v1.5.6:")
print("  mesh_cube(size)         - Create cube mesh")
print("  mesh_sphere(radius)    - Create sphere mesh")
print("  mesh_plane(width,height) - Create plane mesh")
print("  mesh.set_color(r,g,b)  - Set mesh color")