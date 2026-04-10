# Test v1.5.9 - Error Handling & Debugging

print("=== Testing v1.5.9 Error Handling & Debugging ===")

# Test 1: Stack trace
print("\n--- Test 1: Stack Trace ---")
var stack = get_stack_trace()
print("Stack length: " + str(len(stack)))

# Test 2: Error info (no exception currently)
print("\n--- Test 2: Error Info ---")
var err = error_info()
print("Error info: " + str(err))

# Test 3: Breakpoints
print("\n--- Test 3: Breakpoints ---")
var bp = set_breakpoint(10)
print("Set breakpoint: " + str(bp))
var list = list_breakpoints()
print("List: " + str(list))
var clear = clear_breakpoints()
print("Clear: " + str(clear))

# Test 4: Eval context
print("\n--- Test 4: Eval Context ---")
var ctx = eval_context()
print("Context: " + str(ctx))

# Test 5: Trigger and catch error
print("\n--- Test 5: Error Handling ---")
try {
    var x = 1 / 0
} catch e {
    var err2 = error_info()
    print("Caught: " + str(err2))
}

print("\n=== v1.5.9 Tests Complete ===")
print("New in v1.5.9:")
print("  get_stack_trace()     - Get call stack trace")
print("  error_info()          - Get current exception info")
print("  set_breakpoint(n)     - Set breakpoint at line n")
print("  clear_breakpoints()   - Clear all breakpoints")
print("  list_breakpoints()    - List all breakpoints")
print("  eval_context()       - Get evaluation context")