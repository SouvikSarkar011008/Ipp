var a = [1, 2, 3]

var b1 = [0, ...a]
assert b1 == [0, 1, 2, 3]

var b2 = [...a, ...a]
assert b2 == [1, 2, 3, 1, 2, 3]

var b3 = [0, ...a, 4]
assert b3 == [0, 1, 2, 3, 4]

var b4 = [...a, 4, 5]
assert b4 == [1, 2, 3, 4, 5]

var b5 = [10, 20, ...a, 30, 40]
assert b5 == [10, 20, 1, 2, 3, 30, 40]

var c = [1, 2]
var d = [3, 4]
var e = [0, ...c, 99, ...d, 100]
assert e == [0, 1, 2, 99, 3, 4, 100]
