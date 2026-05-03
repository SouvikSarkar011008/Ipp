# Test __str__ with contains() function

class Person {
    func init(name, age) {
        self.name = name
        self.age = age
    }
    func __str__() {
        return self.name + " is " + str(self.age) + " years old"
    }
}

var p = Person("Alice", 30)
var s = str(p)

print("String: " + s)

# Use contains to verify
assert contains(s, "Alice") == true
assert contains(s, "30") == true
assert contains(s, "years old") == true
assert contains(s, "unknown") == false

print("All contains assertions passed!")