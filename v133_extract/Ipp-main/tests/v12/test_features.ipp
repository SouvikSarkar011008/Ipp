# Test v0.12.0 - Module System

print("=== Testing v0.12.0 Module System ===")

# ====== Basic Import Test ======
print("\n--- Basic Import Test ---")

import "utils"

print(greet("World"))
print(add(10, 20))
print(CONSTANT)

# ====== Alias Import Test ======
print("\n--- Alias Import Test ---")

import "utils" as u

print(u.greet("Alice"))
print(u.add(5, 15))
print(u.MODULE_NAME)
print(u.VERSION)

# ====== Selective Import Test ======
print("\n--- Selective Import Test ---")

import "utils" as { greet, CONSTANT }

print(greet("Bob"))
print(CONSTANT)

print("\nv0.12.0 tests complete!")
