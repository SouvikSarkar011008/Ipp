# Test v1.5.37: VM Import System

import "helpers.ipp"
assert add(3, 4) == 7
assert MAGIC_NUMBER == 42

# Test multiple imports (should use cache)
import "helpers.ipp"
assert add(10, 20) == 30

print("v1.5.37: VM import system tests PASSED")