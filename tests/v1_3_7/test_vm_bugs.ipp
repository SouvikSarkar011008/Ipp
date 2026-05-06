# v1.3.7 VM Bug Fix Tests
# Tests all 7 VM bugs that were preventing the VM from being a working backend

print("=== v1.3.7 VM Bug Fix Tests ===")

# ─── VM-BUG-1: Function calls with arguments ─────────────────────────────────
print("\n--- VM-BUG-1: Function calls ---")

func add(a, b) {
    return a + b
}
print(add(3, 4))          # 7
print(add(10, 20))        # 30
assert add(3, 4) == 7, "Function with args works"
assert add(10, 20) == 30, "Function with args works"

func greet(name) {
    return "Hello, " + name
}
print(greet("World"))     # Hello, World
assert greet("World") == "Hello, World", "String function works"

# ─── VM-BUG-2: Dict index access ─────────────────────────────────────────────
print("\n--- VM-BUG-2: Dict index ---")

var d = {"a": 1, "b": 2, "c": 3}
print(d["a"])             # 1
print(d["b"])             # 2
print(d["c"])             # 3
d["d"] = 4
print(d["d"])             # 4
assert d["a"] == 1, "Dict index access works"
assert d["d"] == 4, "Dict index assignment works"

var nums = [10, 20, 30]
print(nums[0])            # 10
print(nums[2])            # 30
assert nums[0] == 10, "List index access works"
assert nums[2] == 30, "List index access works"

# ─── VM-BUG-3: Try/catch ─────────────────────────────────────────────────────
print("\n--- VM-BUG-3: Try/catch ---")

var catch_works = false
try {
    var x = undefinedVar
} catch e {
    catch_works = true
}
print("caught")           # caught
assert catch_works == true, "Try/catch catches undefined variable"

var caught = false
try {
    throw "test error"
} catch e {
    caught = true
}
print(caught)             # true
assert caught == true, "Try/catch catches thrown error"

# ─── VM-BUG-4: Class property access ─────────────────────────────────────────
print("\n--- VM-BUG-4: Class properties ---")

class Dog {
    func init(name) {
        self.name = name
        self.sound = "Woof"
    }
    func speak() {
        return self.name + " says " + self.sound
    }
}

var d2 = Dog("Rex")
print(d2.name)            # Rex
print(d2.sound)           # Woof
print(d2.speak())         # Rex says Woof
assert d2.name == "Rex", "Class property access works"
assert d2.speak() == "Rex says Woof", "Class method works"

class Vec2 {
    func init(x, y) {
        self.x = x
        self.y = y
    }
    func __add__(other) {
        return Vec2(self.x + other.x, self.y + other.y)
    }
    func __str__() {
        return "(" + str(self.x) + ", " + str(self.y) + ")"
    }
}

var v1 = Vec2(1, 2)
var v2 = Vec2(3, 4)
print(v1.x)               # 1
print(v2.y)               # 4
var v3 = v1 + v2
print(v3.x)               # 4
print(v3.y)               # 6
assert v1.x == 1, "Class property x works"
assert v2.y == 4, "Class property y works"
assert v3.x == 4, "Operator overload works"
assert v3.y == 6, "Operator overload works"

# ─── VM-BUG-5: Named arguments ────────────────────────────────────────────────
print("\n--- VM-BUG-5: Named args ---")

func connect(host, port) {
    return host + ":" + str(port)
}
print(connect("localhost", 8080))    # localhost:8080
print(connect(port=9090, host="db")) # db:9090
assert connect("localhost", 8080) == "localhost:8080", "Positional args work"
assert connect(port=9090, host="db") == "db:9090", "Named args work"

# ─── VM-BUG-6: Recursion ─────────────────────────────────────────────────────
print("\n--- VM-BUG-6: Recursion ---")

func fib(n) {
    if n <= 1 { return n }
    return fib(n - 1) + fib(n - 2)
}
print(fib(10))            # 55
assert fib(10) == 55, "Fibonacci recursion works"

func factorial(n) {
    if n <= 1 { return 1 }
    return n * factorial(n - 1)
}
print(factorial(7))       # 5040
assert factorial(7) == 5040, "Factorial recursion works"

# ─── VM-BUG-7: For loops ─────────────────────────────────────────────────────
print("\n--- VM-BUG-7: For loops ---")

var total = 0
for i in 0..5 {
    total = total + i
}
print(total)              # 10
assert total == 10, "Range for loop works"

var items = [1, 2, 3, 4, 5]
var sum = 0
for x in items {
    sum = sum + x
}
print(sum)                # 15
assert sum == 15, "List for loop works"

var result = ""
for c in "abc" {
    result = result + c + "-"
}
print(result)             # a-b-c-
assert result == "a-b-c-", "String for loop works"

print("\n=== All v1.3.7 VM tests passed! ===")
