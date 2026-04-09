# Test v1.5.2b - Web Playground Features

print("=== Testing v1.5.2b Web Playground Interpreter ===")

# ====== Variables ======
print("\n--- Variables ---")
var x = 10
var y = 20
var name = "Ipp"
var isActive = true
print("x = " + str(x))
print("y = " + str(y))
print("name = " + name)
print("isActive = " + str(isActive))

# ====== Arithmetic ======
print("\n--- Arithmetic ---")
print("x + y = " + str(x + y))
print("x - y = " + str(x - y))
print("x * y = " + str(x * y))
print("x / y = " + str(x / y))
print("x % y = " + str(x % y))
print("x ** 2 = " + str(x ** 2))

# ====== Lists ======
print("\n--- Lists ---")
var nums = [1, 2, 3, 4, 5]
print("List: " + str(nums))
print("Length: " + str(len(nums)))
print("First: " + str(nums[0]))
print("Last: " + str(nums[4]))

# ====== For Loop ======
print("\n--- For Loop ---")
var sum = 0
for i in 0..5 {
    sum = sum + i
}
print("Sum 0..5 = " + str(sum))

# ====== Functions ======
print("\n--- Functions ---")
func add(a, b) {
    return a + b
}
print("add(3, 4) = " + str(add(3, 4)))

func multiply(a, b) {
    return a * b
}
print("multiply(5, 6) = " + str(multiply(5, 6)))

func factorial(n) {
    if n <= 1 {
        return 1
    }
    return n * factorial(n - 1)
}
print("factorial(5) = " + str(factorial(5)))

# ====== String Functions ======
print("\n--- String Functions ---")
var text = "Hello, World!"
print("text: " + text)
print("len(text) = " + str(len(text)))

# ====== Math Functions ======
print("\n--- Math Functions ---")
print("abs(-42) = " + str(abs(-42)))
# max/min/sum require proper array handling - tested separately

# ====== Boolean ======
print("\n--- Boolean ---")
var a = true
var b = false
print("a and b = " + str(a and b))
print("a or b = " + str(a or b))
print("not a = " + str(not a))

# ====== Comparison ======
print("\n--- Comparison ---")
print("10 == 10: " + str(10 == 10))
print("10 != 5: " + str(10 != 5))
print("5 < 10: " + str(5 < 10))
print("20 > 10: " + str(20 > 10))

# ====== Fibonacci ======
print("\n--- Fibonacci ---")
func fib(n) {
    if n <= 1 {
        return n
    }
    return fib(n - 1) + fib(n - 2)
}

print("fib(0) = " + str(fib(0)))
print("fib(1) = " + str(fib(1)))
print("fib(5) = " + str(fib(5)))
print("fib(10) = " + str(fib(10)))

# ====== Classes ======
print("\n--- Classes ---")
class Counter {
    func init() {
        this.count = 0
    }
    func increment() {
        this.count = this.count + 1
        return this.count
    }
    func get() {
        return this.count
    }
}

var c = Counter()
print("Counter start: " + str(c.get()))
print("After increment: " + str(c.increment()))
print("After increment: " + str(c.increment()))

print("\n=== v1.5.2b Web Playground tests complete! ===")