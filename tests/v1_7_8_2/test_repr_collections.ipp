# Test 4: repr with lists and dicts

class Point {
    func init(x, y) {
        self.x = x
        self.y = y
    }
    func __repr__() {
        return "P(" + str(self.x) + "," + str(self.y) + ")"
    }
}

# List
var lst = [1, 2, 3]
var r1 = repr(lst)
print("repr([1,2,3]) = " + r1)
assert r1 == "[1, 2, 3]"

# List with instances
var p1 = Point(1, 2)
var p2 = Point(3, 4)
var lst2 = [p1, p2]
var r2 = repr(lst2)
print("repr([Point, Point]) = " + r2)

# Dict
var d = {"a": 1, "b": 2}
var r3 = repr(d)
print("repr(dict) = " + r3)

print("Collections repr test passed!")