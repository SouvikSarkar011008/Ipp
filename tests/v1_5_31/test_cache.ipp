# Test v1.5.31: Global cache hash collision fix

var alpha = 1
var beta = 2
var gamma = 3

alpha = 100
assert alpha == 100
assert beta == 2
assert gamma == 3

beta = 200
assert alpha == 100
assert beta == 200
assert gamma == 3

print("v1.5.31: Global cache tests PASSED")