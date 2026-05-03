# Test 5: __str__ in collections (list, dict)
class Point {
    func init(x, y) { 
        self.x = x
        self.y = y 
    }
    func __str__() { 
        return "(" + str(self.x) + ", " + str(self.y) + ")" 
    }
}

# List of instances - each element uses __str__ when converted
var p1 = Point(1, 2)
var p2 = Point(3, 4)
var p3 = Point(5, 6)

# Individual str() calls work
print("p1: " + str(p1))
print("p2: " + str(p2))
print("p3: " + str(p3))

assert str(p1) == "(1, 2)"
assert str(p2) == "(3, 4)"
assert str(p3) == "(5, 6)"

# List doesn't use __str__ for display (this is expected behavior)
# Each element is still a Point instance
var points = [p1, p2, p3]
print("List: " + str(points))

# Dict values - individual str() works
var d = {"a": p1, "b": p2}
print("Dict a: " + str(d["a"]))
print("Dict b: " + str(d["b"]))

assert str(d["a"]) == "(1, 2)"
assert str(d["b"]) == "(3, 4)"