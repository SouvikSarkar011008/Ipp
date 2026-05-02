class Point {
    func init(x, y) { self.x = x; self.y = y }
    func __str__() { return "(" + str(self.x) + ", " + str(self.y) + ")" }
}
class NoStr {
    func init() { self.val = 42 }
}

var p = Point(3, 4)
assert str(p) == "(3, 4)"

var joined = "point is: " + str(p)
assert joined == "point is: (3, 4)"

print(p)

var ns = NoStr()
var s = str(ns)
assert s.contains("NoStr") == true