# v1.7.9.1.14 — trunc() builtin + int() truncation documented (BUG-026)

# --- int() truncates toward zero ---
assert int(3.9) == 3
assert int(-3.9) == -3
assert int(0.0) == 0
assert int(100.999) == 100
assert int(-100.999) == -100

# --- floor() rounds toward negative infinity ---
assert floor(3.9) == 3.0
assert floor(-3.9) == -4.0
assert floor(0.0) == 0.0

# --- ceil() rounds toward positive infinity ---
assert ceil(3.1) == 4.0
assert ceil(-3.9) == -3.0
assert ceil(0.0) == 0.0

# --- trunc() is identical to int() (truncate toward zero) ---
assert trunc(3.9) == 3
assert trunc(-3.9) == -3
assert trunc(0.0) == 0
assert trunc(100.999) == 100

# --- int() and trunc() give same results for all inputs ---
assert int(3.9) == trunc(3.9)
assert int(-3.9) == trunc(-3.9)
assert int(0.0) == trunc(0.0)
assert int(42.0) == trunc(42.0)

# --- Game tile coordinate: int() gives WRONG tile for negative world ---
var tile_size = 32
var neg_world_x = -10.0
assert floor(neg_world_x / tile_size) == -1.0     # correct tile
assert int(neg_world_x / tile_size) == 0           # wrong tile (truncates toward zero)
assert trunc(neg_world_x / tile_size) == 0          # same as int()

# --- Positive world coordinates: int() and floor() agree ---
var pos_world_x = 70.0
assert int(pos_world_x / tile_size) == 2
assert floor(pos_world_x / tile_size) == 2.0

# --- String conversion still works ---
assert int("42") == 42
assert int("3") == 3

print("v1.7.9.1.14: trunc/floor tests PASSED")
