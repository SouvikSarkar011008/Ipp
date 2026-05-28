print("=== Vector Arithmetic Tests ===")

# --- vec4 arithmetic ---
var v4a = vec4(1, 2, 3, 0)
var v4b = vec4(4, 5, 6, 0)

var v4_sum = v4a + v4b
assert v4_sum.x == 5
assert v4_sum.y == 7
assert v4_sum.z == 9
assert v4_sum.w == 0

var v4_diff = v4b - v4a
assert v4_diff.x == 3
assert v4_diff.y == 3
assert v4_diff.z == 3
assert v4_diff.w == 0

var v4_scaled = v4a * 2
assert v4_scaled.x == 2
assert v4_scaled.y == 4
assert v4_scaled.z == 6
assert v4_scaled.w == 0

var v4_rscaled = 2 * v4a
assert v4_rscaled.x == 2
assert v4_rscaled.y == 4
assert v4_rscaled.z == 6
assert v4_rscaled.w == 0

var v4_div = v4a / 2
assert v4_div.x == 0.5
assert v4_div.y == 1.0
assert v4_div.z == 1.5
assert v4_div.w == 0.0

var v4_eq = v4a == vec4(1, 2, 3, 0)
assert v4_eq == true
assert (v4a == v4b) == false

# --- vec3 arithmetic ---
var v3a = vec3(1, 0, 0)
var v3b = vec3(0, 1, 0)

var v3_sum = v3a + v3b
assert v3_sum.x == 1
assert v3_sum.y == 1
assert v3_sum.z == 0

var v3_diff = v3b - v3a
assert v3_diff.x == -1
assert v3_diff.y == 1
assert v3_diff.z == 0

var v3_scaled = v3a * 3
assert v3_scaled.x == 3
assert v3_scaled.y == 0
assert v3_scaled.z == 0

var v3_rscaled = 3 * v3a
assert v3_rscaled.x == 3
assert v3_rscaled.y == 0
assert v3_rscaled.z == 0

var v3_div = vec3(4, 6, 8) / 2
assert v3_div.x == 2
assert v3_div.y == 3
assert v3_div.z == 4

# --- vec2 arithmetic ---
var v2a = vec2(3, 4)
var v2b = vec2(1, 2)

var v2_sum = v2a + v2b
assert v2_sum.x == 4
assert v2_sum.y == 6

var v2_diff = v2b - v2a
assert v2_diff.x == -2
assert v2_diff.y == -2

var v2_scaled = v2a * 2
assert v2_scaled.x == 6
assert v2_scaled.y == 8

var v2_rscaled = 2 * v2a
assert v2_rscaled.x == 6
assert v2_rscaled.y == 8

var v2_div = v2a / 2
assert v2_div.x == 1.5
assert v2_div.y == 2.0

print("=== Vector Method Tests ===")

# --- vec3 methods ---
var v = vec3(3, 4, 0)
assert isclose(v.length(), 5.0) == true
assert isclose(v.length_squared(), 25.0) == true

var n = v.normalize()
assert isclose(n.length(), 1.0) == true
assert isclose(n.x, 0.6) == true
assert isclose(n.y, 0.8) == true
assert isclose(n.z, 0.0) == true

var a = vec3(1, 0, 0)
var b = vec3(0, 1, 0)
assert isclose(a.dot(b), 0.0) == true
assert isclose(a.dot(a), 1.0) == true
assert isclose(a.dot(vec3(2, 0, 0)), 2.0) == true

var cross = a.cross(b)
assert cross.x == 0
assert cross.y == 0
assert isclose(cross.z, 1.0) == true

# cross product perpendicular
assert isclose(cross.dot(a), 0.0) == true
assert isclose(cross.dot(b), 0.0) == true

var v3_lerp = vec3(1, 0, 0).lerp(vec3(0, 1, 0), 0.5)
assert isclose(v3_lerp.x, 0.5) == true
assert isclose(v3_lerp.y, 0.5) == true
assert isclose(v3_lerp.z, 0.0) == true

# lerp at endpoints
var lerp_start = vec3(5, 10, 15).lerp(vec3(20, 30, 40), 0)
assert lerp_start.x == 5
assert lerp_start.y == 10
assert lerp_start.z == 15

var lerp_end = vec3(5, 10, 15).lerp(vec3(20, 30, 40), 1)
assert lerp_end.x == 20
assert lerp_end.y == 30
assert lerp_end.z == 40

# --- vec4 methods ---
var v4 = vec4(3, 4, 0, 0)
assert isclose(v4.length(), 5.0) == true

var v4n = v4.normalize()
assert isclose(v4n.length(), 1.0) == true
assert isclose(v4n.x, 0.6) == true
assert isclose(v4n.y, 0.8) == true

var v4a2 = vec4(1, 0, 0, 0)
var v4b2 = vec4(0, 1, 0, 0)
assert isclose(v4a2.dot(v4b2), 0.0) == true
assert isclose(v4a2.dot(v4a2), 1.0) == true

var v4_lerp = vec4(1, 2, 3, 0).lerp(vec4(4, 5, 6, 0), 0.5)
assert isclose(v4_lerp.x, 2.5) == true
assert isclose(v4_lerp.y, 3.5) == true
assert isclose(v4_lerp.z, 4.5) == true

# --- vec2 methods ---
var v2 = vec2(3, 4)
assert isclose(v2.length(), 5.0) == true
assert isclose(v2.length_squared(), 25.0) == true

var v2n = v2.normalize()
assert isclose(v2n.length(), 1.0) == true
assert isclose(v2n.x, 0.6) == true
assert isclose(v2n.y, 0.8) == true

assert isclose(v2.dot(vec2(1, 0)), 3.0) == true
assert isclose(v2.dot(vec2(0, 1)), 4.0) == true

var v2_lerp = vec2(1, 0).lerp(vec2(0, 1), 0.5)
assert isclose(v2_lerp.x, 0.5) == true
assert isclose(v2_lerp.y, 0.5) == true

# --- distance (via (a-b).length()) ---
assert isclose((vec3(0, 0, 0) - vec3(3, 4, 0)).length(), 5.0) == true
assert isclose((vec2(0, 0) - vec2(3, 4)).length(), 5.0) == true
assert isclose((vec4(0, 0, 0, 0) - vec4(3, 4, 0, 0)).length(), 5.0) == true

# --- zero vector edge cases ---
var zero3 = vec3(0, 0, 0)
var zero3n = zero3.normalize()
assert zero3n.x == 0 and zero3n.y == 0 and zero3n.z == 0

var zero4 = vec4(0, 0, 0, 0)
var zero4n = zero4.normalize()
assert zero4n.x == 0 and zero4n.y == 0 and zero4n.z == 0 and zero4n.w == 0

var zero2 = vec2(0, 0)
var zero2n = zero2.normalize()
assert zero2n.x == 0 and zero2n.y == 0

# --- vec4 to_vec3 ---

# --- vector repr ---
assert repr(vec2(1, 2)) == "vec2(1, 2)"
assert repr(vec3(1, 2, 3)) == "vec3(1, 2, 3)"
assert repr(vec4(1, 2, 3, 0)) == "vec4(1.0, 2.0, 3.0, 0.0)"

print("ALL VECTOR ARITHMETIC TESTS PASSED")
