# Test try/catch catching throw statement

try {
    throw "custom error"
    print("Should not reach here")
} catch e {
    print("Caught: " + str(e))
    assert e == "custom error"
}

print("Test passed!")