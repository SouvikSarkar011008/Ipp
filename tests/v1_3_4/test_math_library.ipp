# Test v1.3.4 - Math Library

print("=== Testing v1.3.4 Math Library ===")

# ====== Game Dev Math ======
print("\n--- Game Dev Math ---")

# Lerp
print("lerp(0, 10, 0.5):", lerp(0, 10, 0.5))
print("lerp(0, 100, 0.25):", lerp(0, 100, 0.25))

# Clamp
print("clamp(5, 0, 10):", clamp(5, 0, 10))
print("clamp(15, 0, 10):", clamp(15, 0, 10))
print("clamp(-5, 0, 10):", clamp(-5, 0, 10))

# Map Range
print("map_range(0.5, 0, 1, 0, 100):", map_range(0.5, 0, 1, 0, 100))

# Distance
print("distance(0, 0, 3, 4):", distance(0, 0, 3, 4))
print("distance_3d(0, 0, 0, 1, 2, 2):", distance_3d(0, 0, 0, 1, 2, 2))

# Normalize
var norm = normalize(3, 4)
print("normalize(3, 4):", norm)

# Dot Product
print("dot(1, 0, 0, 1):", dot(1, 0, 0, 1))
print("dot(1, 0, 1, 0):", dot(1, 0, 1, 0))

# Cross Product (2D)
print("cross(1, 0, 0, 1):", cross(1, 0, 0, 1))

# Sign
print("sign(5):", sign(5))
print("sign(-5):", sign(-5))
print("sign(0):", sign(0))

# Smoothstep
print("smoothstep(0, 1, 0.5):", smoothstep(0, 1, 0.5))

# Move Towards
print("move_towards(0, 10, 3):", move_towards(0, 10, 3))
print("move_towards(0, 10, 15):", move_towards(0, 10, 15))

# Angle
print("angle(0, 0, 1, 0):", angle(0, 0, 1, 0))
print("angle(0, 0, 0, 1):", angle(0, 0, 0, 1))

# Degree/Radian Conversion
print("deg_to_rad(180):", deg_to_rad(180))
print("rad_to_deg(3.14159):", rad_to_deg(3.14159))

# ====== Advanced Math ======
print("\n--- Advanced Math ---")

# Factorial
print("factorial(5):", factorial(5))
print("factorial(10):", factorial(10))

# GCD
print("gcd(12, 8):", gcd(12, 8))
print("gcd(100, 75):", gcd(100, 75))

# LCM
print("lcm(4, 6):", lcm(4, 6))
print("lcm(12, 18):", lcm(12, 18))

# Hypotenuse
print("hypot(3, 4):", hypot(3, 4))
print("hypot(5, 12):", hypot(5, 12))

# Floor Division
print("floor_div(7, 3):", floor_div(7, 3))
print("floor_div(10, 3):", floor_div(10, 3))

# ====== Vector2 Tests ======
print("\n--- Vector2 Tests ---")
var v1 = vec2(3, 4)
var v2 = vec2(1, 2)
print(v1)
print(v1 + v2)
print(v1 - v2)
print(v1 * 2)

# ====== Vector3 Tests ======
print("\n--- Vector3 Tests ---")
var v3 = vec3(1, 2, 3)
var v4 = vec3(4, 5, 6)
print(v3)
print(v3 + v4)
print(v3 - v4)

# ====== Color Tests ======
print("\n--- Color Tests ---")
var c = color(255, 128, 64, 255)
print(c)

# ====== Rect Tests ======
print("\n--- Rect Tests ---")
var r = rect(0, 0, 100, 50)
print(r)

# ====== Complex Numbers ======
print("\n--- Complex Numbers ---")
var c1 = complex(3, 4)
var c2 = complex(1, 2)
print(c1)
print(c2)
print(c1 + c2)
print(c1 - c2)
print(c1 * c2)
print(c1 / c2)
print(abs(c1))
print(c1.conjugate())

print("\n=== v1.3.4 Math Library tests complete! ===")
