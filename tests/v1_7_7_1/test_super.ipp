class Shape {
    func init(color) {
        self.color = color
    }
    func describe() {
        return "a " + self.color + " shape"
    }
}

class Circle extends Shape {
    func init(color, radius) {
        super.init(color)
        self.radius = radius
    }
    func describe() {
        return super.describe() + " (circle r=" + str(self.radius) + ")"
    }
    func area() {
        return pi * self.radius * self.radius
    }
}

var c = Circle("red", 5)
assert c.color == "red"
assert c.radius == 5
assert c.describe() == "a red shape (circle r=5)"
assert c.area() > 78.0 and c.area() < 79.0