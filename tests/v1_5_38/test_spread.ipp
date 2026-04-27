# Test v1.5.38: Spread operator

var a = [1, 2, 3]
var b = [...a]
assert b == [1, 2, 3]

var c = [...a, 4, 5]
assert c == [1, 2, 3, 4, 5]

var d = [0, ...a, 4]
assert d == [0, 1, 2, 3, 4]

var e = [...[1, 2], ...[3, 4]]
assert e == [1, 2, 3, 4]

# Test with spread in function call
func foo(...args) {
    return args
}
assert foo(1, 2, 3) == [1, 2, 3]

print("v1.5.38: Spread operator tests PASSED")