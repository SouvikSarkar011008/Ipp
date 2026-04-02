# v0.6.0 Feature Tests

# Power operator
var p1 = 2 ** 10
var p2 = 3 ** 3
var p3 = 5 ** 2
print("Power 2**10: " + str(p1))
print("Power 3**3: " + str(p2))
print("Power 5**2: " + str(p3))

# Type annotations (syntax only - runtime not enforced)
var num: int = 42
var name: string = "Ipp"
print("Type annotations: OK")

# Enums
enum Direction {
    UP, DOWN, LEFT, RIGHT
}
var dir = Direction.UP
var dir2 = Direction.DOWN
print("Enum UP: " + str(dir))
print("Enum DOWN: " + str(dir2))

# Match with enum
var direction_name = "unknown"
match dir {
    case Direction.UP => direction_name = "UP"
    case Direction.DOWN => direction_name = "DOWN"
    default => direction_name = "other"
}
print("Direction: " + str(direction_name))

print("v0.6.0 tests complete!")
