# Test v1.5.10 - Standard Library Additions

print("=== Testing v1.5.10 Standard Library ===")

# Test 1: Math functions
print("\n--- Test 1: Math Functions ---")
print("math_degrees(3.14): " + str(math_degrees(3.14)))
print("math_radians(180): " + str(math_radians(180)))
print("math_factorial(5): " + str(math_factorial(5)))
print("math_gcd(12, 18): " + str(math_gcd(12, 18)))
print("math_lcm(4, 6): " + str(math_lcm(4, 6)))
print("math_hypot(3, 4): " + str(math_hypot(3, 4)))
print("math_isclose(0.1 + 0.2, 0.3): " + str(math_isclose(0.1 + 0.2, 0.3)))

# Test 2: File system functions
print("\n--- Test 2: File System Functions ---")
print("fs_exists('main.py'): " + str(fs_exists("main.py")))
print("fs_isfile('main.py'): " + str(fs_isfile("main.py")))
print("fs_isdir('ipp'): " + str(fs_isdir("ipp")))
print("fs_size('main.py'): " + str(fs_size("main.py")) + " bytes")

# Test 3: Date/Time functions
print("\n--- Test 3: Date/Time Functions ---")
print("date_timestamp: " + str(date_timestamp()))
var dt = datetime_create(2026, 4, 10, 12, 0, 0)
print("datetime_create: " + str(dt))
print("date_format: " + str(date_format(dt, "%Y-%m-%d")))

print("\n=== v1.5.10 Tests Complete ===")
print("New in v1.5.10:")
print("  Math: math_degrees, math_radians, math_factorial, math_gcd, math_lcm, math_hypot, math_isclose")
print("  File System: fs_exists, fs_isfile, fs_isdir, fs_size, fs_mtime, fs_copy, fs_move, fs_mkdir, fs_list_dir")
print("  Date/Time: date_timestamp, date_from_timestamp, date_format")