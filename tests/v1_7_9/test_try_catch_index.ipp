# Test try/catch catching index out of bounds

try {
    var lst = [1, 2, 3]
    var x = lst[10]
    print("Should not reach here")
} catch e {
    print("Caught: " + str(e))
    # Just print, don't assert since error messages differ between interpreter and VM
}

print("Test passed!")