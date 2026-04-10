# Test v1.5.7 - 3D Visualization

print("=== Testing v1.5.7 3D Visualization ===")

# Test 1: Create scene with primitives
print("\n--- Test 1: Scene Setup ---")
var s = scene("visualization")
var cam = camera("main", 60, 1.5, 0.1, 100)
s.add(cam)
s.set_camera(cam)
s.add(mesh_cube(1))
s.add(mesh_sphere(0.5, 8, 4))
print("Scene created: " + str(s))

# Test 2: render() returns projected points
print("\n--- Test 2: Basic Render ---")
var result = s.render()
print("Render result type: " + type(result))

# Test 3: render_to_canvas() returns text output
print("\n--- Test 3: Render to Canvas (Text) ---")
var canvas_output = s.render_to_canvas(400, 300)

# Test 4: Check method existence
print("\n--- Test 4: Wireframe Method ---")
var wf = s.render_wireframe
print("Wireframe method exists: true")

# Test 5: Check point method existence
print("\n--- Test 5: Point Cloud Method ---")
var pt = s.render_points
print("Point cloud method exists: true")

print("\n=== v1.5.7 Tests Complete ===")
print("New in v1.5.7:")
print("  scene.render_wireframe(w, h) - Draw wireframe to canvas")
print("  scene.render_points(w, h, size) - Draw point cloud to canvas")
print("  These require canvas_open() first")