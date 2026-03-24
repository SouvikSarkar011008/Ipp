# Test 6: Control Flow, Functions & Classes
print("=== Control Flow ===")
if 5 > 3 {
    print("5 > 3")
}

if false {
    print("false")
} else {
    print("else executed")
}

var x = 10
if x == 10 {
    print("x is 10")
} elif x == 20 {
    print("x is 20")
} else {
    print("x is something else")
}

print("\n=== Loops ===")
var i = 0
while i < 3 {
    print(i)
    i = i + 1
}

for j in [1, 2, 3] {
    print(j)
}

print("\n=== Functions ===")
func add(a, b) {
    return a + b
}
print(add(2, 3))

func greet(name) {
    return "Hello, " + name
}
print(greet("World"))

func factorial(n) {
    if n <= 1 {
        return 1
    }
    return n * factorial(n - 1)
}
print(factorial(5))

print("\n=== Classes ===")
class Dog {
    func init(name) {
        self.name = name
    }
    
    func bark() {
        return self.name + " says Woof!"
    }
    
    func get_age(age) {
        self.age = age
        return self.age
    }
}

var dog = Dog("Buddy")
print(dog.bark())
print(dog.get_age(3))