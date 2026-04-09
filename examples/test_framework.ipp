# Test Framework for Ipp

print("=== Ipp Test Framework ===")
print("")
print("Usage:")
print("  test.assert(condition, message)")
print("  test.assert_eq(actual, expected)")
print("  test.assert_ne(a, b)")
print("  test.assert_raises(func, expected_error)")
print("")
print("Example:")
print('  test.assert_eq(1 + 1, 2, "1+1 should be 2")')
print('  test.assert(10 > 5, "10 should be greater than 5")')
print("")
print("Run tests with: python main.py test <file>")

# Test assertions
func assert(condition, message) {
    if not condition {
        print("FAIL: " + message)
        return false
    }
    print("PASS: " + message)
    return true
}

func assert_eq(actual, expected, message) {
    if actual == expected {
        print("PASS: " + message)
        return true
    }
    print("FAIL: " + message + " (expected " + str(expected) + ", got " + str(actual) + ")")
    return false
}

func assert_ne(a, b, message) {
    if a != b {
        print("PASS: " + message)
        return true
    }
    print("FAIL: " + message + " (" + str(a) + " should not equal " + str(b) + ")")
    return false
}

# Run basic tests
print("")
print("=== Running Built-in Tests ===")
assert_eq(1 + 1, 2, "Basic arithmetic")
assert_eq("hello" + " " + "world", "hello world", "String concatenation")
assert_eq(len([1, 2, 3]), 3, "List length")
assert(10 > 5, "Comparison")
assert_ne(5, 6, "Not equal")
assert_eq(abs(-5), 5, "Absolute value")

print("")
print("=== Test Framework Ready ===")