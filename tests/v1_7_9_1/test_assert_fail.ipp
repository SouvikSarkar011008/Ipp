# Test assert still works

var x = 1 + 1
assert x == 2
print("Pass: 1+1 == 2")

# This should fail
var y = 2 + 2
assert y == 3
print("Should not print!")