var x = 1
var y = 2
var x, y = y, x
assert x == 2
assert y == 1

var a = "first"
var b = "second"
var c = "third"
var a, b, c = b, c, a
assert a == "second"
assert b == "third"
assert c == "first"

var m = 3
var n = 7
var m, n = n + 1, m - 1
assert m == 8
assert n == 2
