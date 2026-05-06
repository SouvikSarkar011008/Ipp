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
assert error_msg.contains("Division") == true or error_msg.contains("zero") == true

print("Test passed!")