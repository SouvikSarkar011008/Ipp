# Test v1.0.0 - Bytecode VM

print("=== Testing v1.0.0 Bytecode VM ===")

# ====== Simple Math Test ======
print("\n--- Simple Math Test ---")

var result = 2 ** 10
print("2 ** 10 = " + str(result))
assert result == 1024

result = 15 // 4
print("15 // 4 = " + str(result))
assert result == 3

result = 10 & 7
print("10 & 7 = " + str(result))
assert result == 2

# ====== List Operations ======
print("\n--- List Operations ---")

var nums = [1, 2, 3, 4, 5]
print("Sum: " + str(sum(nums)))
assert sum(nums) == 15

var doubled = [x * 2 for x in nums]
print("Doubled: " + str(doubled))
assert doubled[0] == 2
assert doubled[4] == 10

# ====== String Operations ======
print("\n--- String Operations ---")

var name = "Ipp"
var greeting = "Hello, " + name + "!"
print(greeting)
assert greeting == "Hello, Ipp!"

var upper = greeting.upper()
print("Upper: " + upper)
assert upper == "HELLO, IPP!"

# ====== Function Call ======
print("\n--- Function Call ---")

func factorial(n) {
    if n <= 1 {
        return 1
    }
    return n * factorial(n - 1)
}

var fact5 = factorial(5)
print("5! = " + str(fact5))
assert fact5 == 120

# ====== Class Test ======
print("\n--- Class Test ---")

class Point {
    func init(x, y) {
        this.x = x
        this.y = y
    }
    
    func __str__() {
        return "Point(" + str(this.x) + ", " + str(this.y) + ")"
    }
}

var p = Point(3, 4)
var pstr = str(p)
print(pstr)
assert pstr == "Point(3, 4)"

print("\nv1.0.0 tests complete!")
