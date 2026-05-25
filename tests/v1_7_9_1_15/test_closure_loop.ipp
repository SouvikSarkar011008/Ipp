# v1.7.9.1.15 — BUG-023: Closures in loops capture correct value

# Test 1: for-in loop with closures
print("Test 1: Basic for-in closure capture")
var fns = []
for i in range(5) {
    fns = fns + [func() { return i }]
}
assert fns[0]() == 0
assert fns[1]() == 1
assert fns[2]() == 2
assert fns[3]() == 3
assert fns[4]() == 4
print("  PASS")

# Test 2: String loop variable
print("Test 2: String loop variable")
var handlers = []
var labels = ["alpha", "beta", "gamma"]
for label in labels {
    handlers = handlers + [func() { return label }]
}
assert handlers[0]() == "alpha"
assert handlers[1]() == "beta"
assert handlers[2]() == "gamma"
print("  PASS")

# Test 3: Multiple captured variables
print("Test 3: Multiple captured variables")
var adders = []
for i in range(3) {
    var base = i * 10
    adders = adders + [func(x) { return base + x }]
}
assert adders[0](5) == 5    # base=0
assert adders[1](5) == 15   # base=10
assert adders[2](5) == 25   # base=20
print("  PASS")

# Test 4: Explicit capture pattern (must not regress)
print("Test 4: Explicit capture pattern")
var efns = []
for m in range(3) {
    var captured = m
    efns = efns + [func() { return captured }]
}
assert efns[0]() == 0
assert efns[1]() == 1
assert efns[2]() == 2
print("  PASS")

# Test 5: Nested loop closures
print("Test 5: Nested loop closures")
var matrix = []
for x in range(3) {
    for y in range(3) {
        matrix = matrix + [func() { return [x, y] }]
    }
}
var p00 = matrix[0]()
assert p00[0] == 0
assert p00[1] == 0

var p12 = matrix[5]()  # row 1, col 2 → index 1*3+2 = 5
assert p12[0] == 1
assert p12[1] == 2

var p22 = matrix[8]()  # row 2, col 2
assert p22[0] == 2
assert p22[1] == 2
print("  PASS")

# Test 6: Loop with continue and closures
print("Test 6: Loop with continue and closures")
var even_fns = []
for i in range(5) {
    if i % 2 == 1 {
        continue
    }
    even_fns = even_fns + [func() { return i }]
}
assert even_fns[0]() == 0
assert even_fns[1]() == 2
assert even_fns[2]() == 4
print("  PASS")

# Test 7: Closure modifying captured variable
print("Test 7: Closure modifying captured variable")
var counters = []
for n in range(3) {
    counters = counters + [func() { return n }]
}
assert counters[0]() == 0
assert counters[1]() == 1
assert counters[2]() == 2
print("  PASS")

print("All closure loop tests passed!")
