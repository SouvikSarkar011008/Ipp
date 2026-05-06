# Test v1.5.5.4 - Basic Renderer

print("=== Testing v1.5.5.4 Basic Renderer ===")

# Test 1: Scene with camera
print("\n--- Test 1: Scene with Camera ---")
var s = scene("test_scene")
var cam = camera("main_cam", 60, 1.5, 0.1, 100)
s.add(cam)
s.set_camera(cam)
print("Scene with camera created")
assert s != nil, "Scene works"

# Test 2: Add mesh
print("\n--- Test 2: Add Mesh ---")
var m = mesh("cube")
s.add(m)
print("Mesh added to scene")
assert m != nil, "Mesh works"

# Test 3: Render
print("\n--- Test 3: Render ---")
var r = s.render()
print("Render result: " + str(r))
assert r != nil, "render works"

# Test 4: render_to_canvas
print("\n--- Test 4: render_to_canvas ---")
var canvas_output = s.render_to_canvas(800, 600)
print(canvas_output)
assert canvas_output != nil, "render_to_canvas works"

# Test 5: Basic functionality
print("\n--- Test 5: Basic Functionality ---")
print("sum([1,2,3]) = " + str(sum([1, 2, 3])))
assert sum([1, 2, 3]) == 6, "sum works"

print("\n=== v1.5.5.4 Tests Complete ===")
print("New in v1.5.5.4:")
print("  scene.render()           - Project 3D to 2D")
print("  scene.render_to_canvas() - Get 2D screen coordinates")
print("  3D -> 2D projection via MVP matrix")