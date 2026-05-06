# Advanced __repr__ test - Simple version

class Person {
    func init(name, age) {
        self.name = name
        self.age = age
    }
    func __repr__() {
        return "Person(" + self.name + ", " + str(self.age) + ")"
    }
}

var p = Person("Alice", 30)
var r = repr(p)
print("Person repr: " + r)
assert r == "Person(Alice, 30)"
print("Test passed!")