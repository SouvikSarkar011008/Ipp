class Animal {
    func init(name) {
        self.name = name
    }
    func speak() {
        return "..."
    }
    func describe() {
        return "I am " + self.name
    }
}

class Cat extends Animal {
    func speak() {
        return self.name + " says meow"
    }
}

class Dog extends Animal {
    func speak() {
        return self.name + " says woof"
    }
}

var c = Cat("Whiskers")
var d = Dog("Rex")

assert c.speak() == "Whiskers says meow"
assert d.speak() == "Rex says woof"
assert c.describe() == "I am Whiskers"
assert d.describe() == "I am Rex"
assert c.name == "Whiskers"

# Old colon syntax must still work
class Fish : Animal {
    func speak() { return self.name + " blub" }
}
var f = Fish("Nemo")
assert f.speak() == "Nemo blub"