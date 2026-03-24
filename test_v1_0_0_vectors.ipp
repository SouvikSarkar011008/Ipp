# Test: Vector2
print("=== Vector2 ===")

var v1 = vec2(3, 4)
var v2 = vec2(1, 2)
print(v1)
print(v2)

# Addition
var v3 = v1 + v2
print(v3)

# Subtraction
var v4 = v1 - v2
print(v4)

# Scalar multiplication
var v5 = v1 * 2
print(v5)

# Scalar division
var v6 = v1 / 2
print(v6)

# Dot product
var dot_prod = v1.dot(v2)
print(dot_prod)

# Length
var len_v1 = v1.length()
print(len_v1)

# Normalize
var v7 = v1.normalize()
print(v7)
print(v7.length())

# Distance
var dist = v1.distance(v2)
print(dist)

print(type(v1))
print(type(v2))


# Test: Vector3
print("\n=== Vector3 ===")

var v8 = vec3(1, 2, 3)
var v9 = vec3(4, 5, 6)
print(v8)
print(v9)

# Addition
var v10 = v8 + v9
print(v10)

# Subtraction
var v11 = v8 - v9
print(v11)

# Scalar multiplication
var v12 = v8 * 3
print(v12)

# Dot product
var dot3 = v8.dot(v9)
print(dot3)

# Cross product
var cross = v8.cross(v9)
print(cross)

# Length
print(v8.length())

# Normalize
var v13 = v8.normalize()
print(v13)
print(v13.length())

# Distance
print(v8.distance(v9))

print(type(v8))


# Test: Zero vectors
print("\n=== Zero Vectors ===")
var zero2 = vec2(0, 0)
var zero3 = vec3(0, 0, 0)
print(zero2)
print(zero3)
print(zero2.length())
print(zero3.length())


# Test: Chained operations
print("\n=== Chained Operations ===")
var chain = (vec2(1, 2) + vec2(3, 4)) * 2
print(chain)
print(chain.length())