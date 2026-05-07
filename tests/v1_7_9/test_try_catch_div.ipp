# Test try/catch catching division by zero

var caught = false
var error_msg = ""
try {
    var x = 10 / 0
    print("Should not reach here")
} catch e {
    caught = true
    error_msg = str(e)
    print("Caught: " + str(e))
}

assert caught == true
assert contains(error_msg, "Division") == true or contains(error_msg, "zero") == true

print("Test passed!")