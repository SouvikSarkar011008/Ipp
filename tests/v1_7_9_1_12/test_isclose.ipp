# v1.7.9.1.12 — isclose() builtin
# Float arithmetic is imprecise; isclose handles it correctly

# --- Basic comparisons ---
assert 0.1 + 0.2 != 0.3                   # raw comparison correctly returns false
assert isclose(0.1 + 0.2, 0.3) == true

assert isclose(1.0, 1.0000000001) == true
assert isclose(1.0, 1.1) == false

# --- Symmetry (a isclose b == b isclose a) ---
assert isclose(0.3, 0.1 + 0.2) == true
assert isclose(1.1, 1.0) == false
assert isclose(0.0, 0.0) == true
assert isclose(0.0, -0.0) == true

# --- Equal values ---
assert isclose(42.0, 42.0) == true
assert isclose(-1.0, -1.0) == true
assert isclose(0.0, 0.0) == true

# --- rel_tol tolerance control ---
assert isclose(1.0, 1.05, rel_tol=0.1) == true     # within 10%
assert isclose(1.0, 1.05, rel_tol=0.01) == false    # outside 1%
assert isclose(100.0, 150.0, rel_tol=0.5) == true   # within 50%
assert isclose(100.0, 300.0, rel_tol=0.5) == false  # outside 50% (|100-300|=200 > 0.5*300=150)

# --- Edge: near-zero with default rel_tol ---
# isclose(0.0, x) with default rel_tol=1e-9 is always false for x != 0
# because rel_tol * max(0, x) = 1e-9 * x, and we need x <= rel_tol * x,
# which requires 1 <= rel_tol. This matches Python's math.isclose behavior.
# (Users needing zero-comparison should add abs_tol support.)

# --- Game use case: timer accumulation ---
var elapsed = 0.0
for i in range(10) {
    elapsed = elapsed + 0.1
}
assert isclose(elapsed, 1.0) == true

# --- Game use case: physics lerp ---
func lerp(a, b, t) {
    return a + (b - a) * t
}
var health = lerp(0.0, 100.0, 0.37)
assert isclose(health, 37.0) == true

# --- Game use case: position comparison ---
var enemy_x = 50.0
var player_x = 50.00000005
assert isclose(enemy_x, player_x) == true

# --- Game use case: percentage checks ---
var progress = 1.0 / 3.0
var total = progress * 3.0
assert isclose(total, 1.0) == true

# --- Works with negative numbers ---
assert isclose(-0.1 + -0.2, -0.3) == true
assert isclose(-1.0, -1.0000000001) == true

# --- Large magnitude numbers (default rel_tol=1e-9) ---
# isclose(N, N+delta) is false when delta > rel_tol * N
# For N=1e12: rel_tol * N = 1000, so delta must be > 1000
assert isclose(1000000000000.0, 1000000000001.0) == true
assert isclose(1000000000000.0, 1000000002000.0) == false

print("v1.7.9.1.12: isclose tests PASSED")
