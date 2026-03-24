# Functions in Ipp
func add(a, b) {
    return a + b
}

func greet(name) {
    return "Hello, " + name + "!"
}

func factorial(n) {
    if n <= 1 {
        return 1
    }
    return n * factorial(n - 1)
}

print(add(5, 3))
print(greet("World"))
print(factorial(5))

# Closures
func make_counter() {
    var count = 0
    func increment() {
        count = count + 1
        return count
    }
    return increment
}

var counter = make_counter()
print(counter())
print(counter())
print(counter())