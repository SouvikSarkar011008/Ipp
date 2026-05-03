# Test try/catch catching nil property access

try {
    var n = nil
    var x = n.field
    print("Should not reach here")
} catch e {
    print("Caught: " + str(e))
    assert contains(e, "NoneType") == true
}

print("Test passed!")