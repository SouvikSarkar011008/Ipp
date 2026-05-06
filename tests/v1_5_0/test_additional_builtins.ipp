# Test v1.5.0 - Additional Builtins

print("=== Testing v1.5.0 Additional Builtins ===")

# ====== Random ======
print("\n--- Random ---")
seed(42)
print("normal:", normal())
print("normal(5, 2):", normal(5, 2))

# ====== Time ======
print("\n--- Time ---")
print("now:", now())
print("delta:", delta())
print("format_duration(65):", format_duration(65))
print("format_duration(3665):", format_duration(3665))
assert format_duration(65) == "1m 5s"
assert format_duration(3665) == "1h 1m 5s"

# ====== Color ======
print("\n--- Color ---")
print("from_hex #FF0000:", from_hex("#FF0000"))
print("to_hex 255,0,0:", to_hex(255, 0, 0))
print("hsl 0,1,0.5:", hsl(0, 1, 0.5))
var hex_color = from_hex("#FF0000")
assert hex_color[0] == 255

# ====== Easing ======
print("\n--- Easing ---")
print("ease_in 0.5:", ease_in(0.5))
print("ease_out 0.5:", ease_out(0.5))
print("bounce 0.5:", bounce(0.5))
print("spring 0.5:", spring(0.5))
assert ease_in(0.5) > 0
assert ease_out(0.5) > 0

# ====== String ======
print("\n--- String ---")
print("words hello world:", words("hello world"))
print("truncate abcdefghijk 5:", truncate("abcdefghijk", 5))
print("pad_left 42 5 0:", pad_left("42", 5, "0"))
print("pad_right 42 5 0:", pad_right("42", 5, "0"))

# ====== List ======
print("\n--- List ---")
var nums = [3, 1, 4, 1, 5, 9]
reverse(nums)
print("reverse:", nums)
print("binary_search [1,3,5,7] 5:", binary_search([1, 3, 5, 7], 5))
print("binary_search [1,3,5,7] 4:", binary_search([1, 3, 5, 7], 4))

var lst1 = [1, 2, 3]
var lst2 = ["a", "b", "c"]
print("zip_with:", zip_with(lst1, lst2))

# ====== Regex ======
print("\n--- Regex ---")
print("find_all hello123world456 [0-9]+:", find_all("hello123world456", "[0-9]+"))
print("sub hello world world ipp:", sub("hello world", "world", "ipp"))
print("escape hello.world:", escape("hello.world"))

# ====== Path ======
print("\n--- Path ---")
print("glob *.ipp:", glob("*.ipp"))

# ====== Grid ======
print("\n--- Grid ---")
var grid = [
    [0, 0, 0, 0],
    [0, 1, 1, 0],
    [0, 0, 0, 0],
    [0, 0, 1, 0]
]
print("neighbors grid 1 1:", neighbors(grid, 1, 1))
print("flood_fill grid 0 0:", flood_fill(grid, 0, 0))
print("pathfind grid (0,0) (2,2):", pathfind(grid, [0, 0], [2, 2]))

# ====== Debug ======
print("\n--- Debug ---")
assert_eq(1, 1)
print("assert_eq passed")
print("inspect [1,2,3]:", inspect([1, 2, 3]))

print("\n=== v1.5.0 Additional Builtins tests complete! ===")
