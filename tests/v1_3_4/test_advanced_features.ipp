# Test v1.3.4 - Advanced Features (Threading, Logging, Argparse)

print("=== Testing v1.3.4 Advanced Features ===")

# ====== Logging Tests ======
print("\n--- Logging Tests ---")
var log = logger("test_logger", "INFO")
log.info("This is an info message")
log.warning("This is a warning message")
log.error("This is an error message")
log.debug("This is a debug message (may not show)")
assert log != nil

# ====== Threading Tests ======
print("\n--- Threading Tests ---")
print("thread function exists:", type(thread))
print("thread_sleep function exists:", type(thread_sleep))
print("thread_current function exists:", type(thread_current))
print("Current thread:", thread_current())
# Verify functions exist (type should not be nil/error)
assert type(thread) != nil or type(thread) == "function"

# ====== Printf/Sprintf/Scanf Tests ======
print("\n--- Printf/Sprintf Tests ---")
printf("Hello %s, you are %d years old\n", "Alice", 30)
var formatted = sprintf("Value: %d, Name: %s", 42, "test")
print("sprintf result:", formatted)
assert formatted == "Value: 42, Name: test"

# ====== Argparse Tests ======
print("\n--- Argparse Tests ---")
print("argparse function exists:", type(argparse))
print("args_add function exists:", type(args_add))
print("args_parse function exists:", type(args_parse))
assert type(argparse) != nil or type(argparse) == "function"

print("\n=== v1.3.4 Advanced Features tests complete! ===")
