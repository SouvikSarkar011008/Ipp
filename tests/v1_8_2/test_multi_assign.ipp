var a, b = 1, 2
assert a == 1 and b == 2

var x, y, z = 10, 20, 30
assert x + y + z == 60

var first, last = "Alice", "Smith"
assert first == "Alice" and last == "Smith"

var n, s, b2 = 42, "hello", true
assert n == 42 and s == "hello" and b2 == true

func pair() { return 3, 4 }
var p, q = pair()
assert p == 3 and q == 4

var m = 1
var n2 = 2
var m, n2 = n2, m
assert m == 2 and n2 == 1
