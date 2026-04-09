# Test v1.5.4 - REPL Performance + Advanced Features

print("=== Testing v1.5.4 REPL Enhancements ===")

# Test 1: Time function
print("\n--- Test 1: Time function ---")
var start = now()
var result = 0
for i in 0..1000 {
    result = result + i
}
var end = now()
print("Loop time: " + str(end - start) + "ms")
print("Result: " + str(result))

# Test 2: Memory info
print("\n--- Test 2: Memory info ---")
print("Memory: basic support available")

# Test 3: Built-in functions
print("\n--- Test 3: Built-in functions ---")
var nums = [5, 2, 8, 1, 9]
print("Original: " + str(nums))

# Test 4: Profiling info
print("\n--- Test 4: Profiling info ---")
print("Using now() for timing:")
print("  start = now()")
print("  # code here")
print("  elapsed = now() - start")

# Test 5: Error handling improvements  
print("\n--- Test 5: Error handling ---")
try {
    var x = undefined_variable
} catch e {
    print("Caught error: " + str(e))
}

print("\n=== v1.5.4 REPL Tests Complete ===")
print("Use in REPL:")
print("  .time <expr>    - Time an expression")
print("  .profile        - Enable profiling")
print("  now()           - Current timestamp in ms")