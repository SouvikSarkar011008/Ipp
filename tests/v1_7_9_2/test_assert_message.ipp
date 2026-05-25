# Test v1.7.9.2 - assert with Custom Error Message

print("=== Testing v1.7.9.2 assert with message ===")

# assert without message still works
assert 1 + 1 == 2
print("Basic assert: OK")

# assert with message: when true, no error
assert true, "this should not fire"
print("Assert true with message: OK")

# assert with message: when false, catch the message
var caught = ""
try {
    assert false, "custom failure message"
} catch e {
    caught = e
    print("Caught: " + str(e))
}
assert contains(caught, "custom failure message") == true

# Expression in message
var hp = -5
try {
    assert hp > 0, "hp is " + str(hp)
} catch e {
    assert contains(e, "-5") == true
    print("Dynamic message: " + str(e))
}

# assert with variable and message
var x = 10
try {
    assert x > 100, "x should be > 100, got " + str(x)
} catch e {
    assert contains(e, "10") == true
}

print("=== v1.7.9.2 assert message tests complete! ===")