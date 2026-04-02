# Class example in Ipp

class Person {
    func init(name, age) {
        self.name = name
        self.age = age
    }
    
    func greet() {
        return "Hello, I am " + self.name
    }
}

var alice = Person("Alice", 25)
print(alice.name)
print(alice.age)
print(alice.greet())