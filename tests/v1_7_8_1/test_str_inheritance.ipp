# Test 3: __str__ with inheritance
class Shape {
    func init(name) { self.name = name }
    func __str__() { return "Shape: " + self.name }
}
class Circle extends Shape {
    func init(radius) {
        self.name = "circle"
        self.radius = radius
    }
    func __str__() { return "Circle r=" + str(self.radius) }
}
class Rectangle extends Shape {
    func init(w, h) {
        self.name = "rectangle"
        self.w = w
        self.h = h
    }
    func __str__() { return "Rectangle " + str(self.w) + "x" + str(self.h) }
}

var c = Circle(5)
var r = Rectangle(10, 20)

print("Circle: " + str(c))
print("Rectangle: " + str(r))

assert str(c) == "Circle r=5"
assert str(r) == "Rectangle 10x20"