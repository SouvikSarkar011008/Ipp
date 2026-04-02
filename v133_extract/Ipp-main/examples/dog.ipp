# Simpler class example
class Dog {
    func init(name) {
        self.name = name
    }
    
    func bark() {
        return "Woof!"
    }
}

var dog = Dog("Buddy")
print(dog.name)