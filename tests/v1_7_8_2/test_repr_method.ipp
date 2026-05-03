# Test 2: __repr__ method in custom classes

class Vec {
    func init(x, y) {
        self.x = x
        self.y = y
    }
    func __repr__() {
        return "Vec(" + str(self.x) + ", " + str(self.y) + ")"
    }
}

class Person {
    func init(name, age) {
        self.name = name
        self.age = age
    }
    func __repr__() {
        return "Person{name='" + self.name + "', age=" + str(self.age) + "}"
    }
}

var v = Vec(1, 2)
var rv = repr(v)
print("repr(Vec(1,2)) = " + rv)
assert rv == "Vec(1, 2)"

var p = Person("Alice", 30)
var rp = repr(p)
print("repr(Person) = " + rp)
assert rp == "Person{name='Alice', age=30}"

print("Custom __repr__ test passed!")