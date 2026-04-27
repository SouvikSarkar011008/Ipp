# Test v1.6.0: Operator overloading

class Vec2 {
    func init(x, y) { 
        self.x = x
        self.y = y 
    }
    func __add__(v) { 
        return Vec2(self.x + v.x, self.y + v.y) 
    }
    func __mul__(s) { 
        return Vec2(self.x * s, self.y * s) 
    }
    func __eq__(v) { 
        return self.x == v.x and self.y == v.y 
    }
}

var a = Vec2(1, 2)
var b = Vec2(3, 4)
var c = a + b
assert c.x == 4 and c.y == 6

var d = a * 3
assert d.x == 3 and d.y == 6

print("v1.6.0: Operator overloading tests PASSED")