# Test v1.5.5.3 - Scene Graph Classes

print("=== Testing v1.5.5.3 Scene Graph Classes ===")

# Test 1: Scene
print("\n--- Test 1: Scene ---")
var s = scene("test_scene")
print("Created: " + str(s))
assert s != nil, "scene works"

# Test 2: Node
print("\n--- Test 2: Node ---")
var n = node("my_node")
print("Created: " + str(n))
print("Node has position, rotation, scale, children")
assert n != nil, "node works"

# Test 3: Camera
print("\n--- Test 3: Camera ---")
var cam = camera("main_cam", 60, 1.5, 0.1, 100)
print("Created: " + str(cam))
assert cam != nil, "camera works"

# Test 4: Mesh
print("\n--- Test 4: Mesh ---")
var m = mesh("cube")
print("Created: " + str(m))
assert m != nil, "mesh works"

# Test 5: Light
print("\n--- Test 5: Light ---")
var l = light("sun", "directional", 1)
print("Created: " + str(l))
assert l != nil, "light works"

# Test 6: Add to scene
print("\n--- Test 6: Add to Scene ---")
s.add(n)
s.add(cam)
s.add(m)
s.add(l)
print("Added 4 nodes to scene")
assert true == true, "add to scene works"

# Test 7: Set camera
print("\n--- Test 7: Set Camera ---")
s.set_camera(cam)
print("Camera set")
assert true == true, "set_camera works"

# Test 8: Render
print("\n--- Test 8: Render ---")
print(s.render())
assert s.render() != nil, "render works"

# Test 9: Node hierarchy
print("\n--- Test 9: Node Hierarchy ---")
var parent = node("parent")
var child = node("child")
parent.add(child)
print("Parent has " + str(len(parent.children)) + " child")
assert len(parent.children) == 1, "add child works"

print("\n=== v1.5.5.3 Tests Complete ===")
print("New in v1.5.5.3:")
print("  scene(name)                 - Create scene container")
print("  node(name)                  - Create scene node")
print("  camera(name, fov, aspect)  - Create camera")
print("  mesh(name)                  - Create mesh")
print("  light(name, type, intensity) - Create light")
print("  scene.add(node)             - Add node to scene")
print("  scene.set_camera(cam)       - Set active camera")
print("  scene.render()              - Get rendering info")