# Test v1.3.4 - Core Builtins

print("=== Testing v1.3.4 Core Builtins ===")

# ====== Print Tests ======
print("\n--- Print Tests ---")
print("Hello, World!")
print(42)
print(true)
print(false)
print(nil)
print("Multiple", "args", 123)

# ====== Length Tests ======
print("\n--- Length Tests ---")
print(len([1, 2, 3]))
print(len("hello"))
print(len({"a": 1, "b": 2}))

# ====== Type Tests ======
print("\n--- Type Tests ---")
print(type(42))
print(type(3.14))
print(type("hello"))
print(type(true))
print(type(nil))
print(type([1, 2, 3]))
print(type({"a": 1}))

# ====== Type Conversion Tests ======
print("\n--- Type Conversion Tests ---")
print(to_int("42"))
print(to_float("3.14"))
print(to_string(42))
print(to_number("123"))
print(to_bool(1))
print(to_bool(0))
print(str(42))
print(to_int("100"))
print(to_float("3.14"))
print(to_bool(1))

# ====== Math Functions ======
print("\n--- Math Functions ---")
print(abs(-5))
print(min(3, 7, 1, 9))
print(max(3, 7, 1, 9))
print(sum([1, 2, 3, 4, 5]))
print(round(3.7))
print(floor(3.7))
print(ceil(3.2))
print(sqrt(16))
print(pow(2, 10))

# ====== Trigonometry ======
print("\n--- Trigonometry ---")
print(sin(0))
print(cos(0))
print(tan(0))
print(asin(0))
print(acos(1))
print(atan(0))
print(atan2(1, 1))
print(degrees(3.14159))
print(radians(180))

# ====== Logarithms ======
print("\n--- Logarithms ---")
print(log(2.718281828459045))
print(log10(100))

# ====== Constants ======
print("\n--- Constants ---")
print(pi())
print(e())

# ====== Random ======
print("\n--- Random ---")
print(random())
print(randint(1, 10))
print(randfloat(0.0, 1.0))
var lst = [1, 2, 3, 4, 5]
print(choice(lst))

# ====== Range ======
print("\n--- Range ---")
print(range(5))
print(range(1, 6))
print(range(0, 10, 2))

# ====== Assert ======
print("\n--- Assert ---")
assert(1 == 1)
print("Assert passed!")

# ====== Input (skip - requires user input) ======
print("\n--- Input (skipped) ---")
print("input() skipped - requires user interaction")

print("\n=== v1.3.4 Core Builtins tests complete! ===")
