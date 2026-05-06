# Test v0.10.0 features

# Test __str__ method
class Person {
    func init(name) {
        this.name = name
    }
    
    func __str__() {
        return "Person: " + this.name
    }
}

var p = Person("Alice")
var s = str(p)
print(s)
assert s == "Person: Alice"

print("v0.10.0 tests complete!")
