# Test try/catch catching division by zero

try {
    var x = 10 / 0
    print("Should not reach here")
} catch e {
    print("Caught: " + str(e))
}

print("Test passed!")