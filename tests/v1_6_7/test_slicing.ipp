# Test v1.6.7: List slicing via slice()
var lst = [0,1,2,3,4,5]

var r1 = slice(lst, 1, 4)
assert r1 == [1,2,3]

var r2 = slice(lst, 0, 3)
assert r2 == [0,1,2]

var r3 = slice(lst, 3)
assert r3 == [3,4,5]

print("v1.6.7: List slicing tests PASSED")