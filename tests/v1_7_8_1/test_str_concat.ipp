# Test 2: __str__ works in string concatenation
class Point {
    func init(x, y) { 
        self.x = x
        self.y = y 
    }
    func __str__() { 
        return "(" + str(self.x) + ", " + str(self.y) + ")" 
    }
}
var p = Point(3, 4)

# String + instance
var s1 = "point is: " + str(p)
print("'point is: ' + str(p) = " + s1)
assert s1 == "point is: (3, 4)"

# Instance + string  
var s2 = str(p) + " is a point"
print("str(p) + ' is a point' = " + s2)
assert s2 == "(3, 4) is a point"

# Multiple concatenations
var s3 = str(p) + " -> " + str(p)
print("str(p) + ' -> ' + str(p) = " + s3)
assert s3 == "(3, 4) -> (3, 4)"