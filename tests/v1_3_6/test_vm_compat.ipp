# Test v1.3.6 - VM Compatibility Tests

print("=== Testing v1.3.6 VM Compatibility ===")

# ====== Math Tests ======
print("\n--- Math Tests ---")
print(2 ** 10)
print(15 // 4)
print(10 & 7)
print(5 | 3)
print(1 << 3)
print(8 >> 2)

# ====== List Tests ======
print("\n--- List Tests ---")
var nums = [1, 2, 3, 4, 5]
print(len(nums))
print(nums[0])

# ====== String Tests ======
print("\n--- String Tests ---")
print("hello")
print(upper("hello"))
print(lower("WORLD"))

# ====== Function Tests ======
print("\n--- Function Tests ---")
func add(a, b) {
    return a + b
}
print(add(5, 3))

func factorial(n) {
    if n <= 1 {
        return 1
    }
    return n * factorial(n - 1)
}
print(factorial(5))

# ====== Loop Tests ======
print("\n--- Loop Tests ---")
var sum = 0
var i = 0
while i < 5 {
    sum = sum + i
    i = i + 1
}
print(sum)

# ====== If/Else Tests ======
print("\n--- If/Else Tests ---")
func max(a, b) {
    if a > b {
        return a
    }
    return b
}
print(max(3, 7))
print(max(10, 5))

# ====== Dict Tests ======
print("\n--- Dict Tests ---")
var person = {"name": "Alice", "age": 30}
print(person["name"])

# ====== Ternary Tests ======
print("\n--- Ternary Tests ---")
var result = 5 > 3 ? "yes" : "no"
print(result)

# ====== Nullish Coalescing ======
print("\n--- Nullish Coalescing ---")
var val = nil ?? "default"
print(val)

# ====== Built-in Functions ======
print("\n--- Built-in Functions ---")
print(abs(-5))
print(min(3, 7))
print(max(3, 7))
print(floor(3.7))
print(ceil(3.2))
print(sqrt(16))

# ====== Range ======
print("\n--- Range ---")
print(range(5))
print(range(1, 6))

# ====== Try/Catch ======
print("\n--- Try/Catch ---")
try {
    var x = undefinedVar
} catch e {
    print("Caught error")
}

# ====== Match ======
print("\n--- Match ---")
var day = 2
match day {
    case 1 => print("Monday")
    case 2 => print("Tuesday")
    default => print("Other")
}

# ====== and/or Precedence ======
print("\n--- and/or Precedence ---")
print(1 == 1 and 2 == 2)
print(1 == 1 or 2 == 3)

print("\n=== v1.3.6 VM Compatibility tests complete! ===")
