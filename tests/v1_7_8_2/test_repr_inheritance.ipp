# Test 5: __repr__ with inheritance

class Animal {
    func init(name) { self.name = name }
    func __repr__() { return "Animal(" + self.name + ")" }
}

class Dog extends Animal {
    func init(name, breed) {
        self.name = name
        self.breed = breed
    }
    func __repr__() { return "Dog(" + self.name + ", " + self.breed + ")" }
}

var a = Animal("generic")
var d = Dog("Rex", "Labrador")

print("Animal repr: " + repr(a))
print("Dog repr: " + repr(d))

assert repr(a) == "Animal(generic)"
assert repr(d) == "Dog(Rex, Labrador)"

print("Inheritance test passed!")