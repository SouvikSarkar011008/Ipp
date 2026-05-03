# Test 1: Basic __str__ method returns correct string
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
var result = str(p)
print("str(Point(3, 4)) = " + result)
assert result == "(3, 4)"