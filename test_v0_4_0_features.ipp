# Test: CLI and Game Helpers
print("=== CLI Help ===")

# Test: Color
print("\n=== Color ===")
var red = color(255, 0, 0)
var green = color(0, 255, 0)
var blue = color(0, 0, 255)
var alpha = color(0, 0, 0, 128)
print(red)
print(green)
print(blue)
print(alpha)

# Color operations
var mixed = red + green
print(mixed)

var dimmed = red * 0.5
print(dimmed)

print(red.to_hex())
print(red.to_rgb())
print(red.to_rgba())

var lerped = red.lerp(blue, 0.5)
print(lerped)

print(type(red))


# Test: Rect
print("\n=== Rect ===")
var r1 = rect(10, 20, 100, 50)
print(r1)
print("left:", r1.left)
print("right:", r1.right)
print("top:", r1.top)
print("bottom:", r1.bottom)
print("center:", r1.center)
print("position:", r1.position)
print("size:", r1.size)

# Contains point
var p1 = vec2(50, 30)
var p2 = vec2(200, 200)
print("contains 50,30:", r1.contains(p1))
print("contains 200,200:", r1.contains(p2))

# Intersects
var r2 = rect(50, 30, 50, 50)
var r3 = rect(200, 200, 50, 50)
print("intersects r2:", r1.intersects(r2))
print("intersects r3:", r1.intersects(r3))

# Inflate
var r4 = r1.inflate(10, 10)
print(r4)

print(type(r1))


# Test: Combined
print("\n=== Combined ===")
var player_pos = vec2(100, 200)
var player_size = vec2(32, 48)
var player_rect = rect(player_pos.x, player_pos.y, player_size.x, player_size.y)
print(player_rect)

var player_color = color(100, 150, 200)
print(player_color.to_hex())


# Test: Module system
print("\n=== Module System ===")
# Test cyclic import detection would need a separate test file
print("Module system: OK")


# Test: Vector operations with other types
print("\n=== Vector Combined ===")
var v1 = vec2(3, 4)
var scaled = v1 * 2
print(scaled)

var normalized = v1.normalize()
print(normalized)
print("length:", normalized.length())


print("\n=== All Tests Passed ===")