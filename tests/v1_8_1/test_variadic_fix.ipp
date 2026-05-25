# v1.8.1 — Fix: Variadic ...args packs a list, not a count (BUG-007)

print("Test 1: basic variadic")
func sum_all(...nums) {
    var total = 0
    for n in nums { total = total + n }
    return total
}
assert sum_all(1, 2, 3, 4, 5) == 15
assert sum_all(10) == 10
assert sum_all() == 0
print("  PASS")

print("Test 2: mixed required + variadic")
func first_and_rest(first, ...rest) {
    return str(first) + " then " + str(len(rest)) + " more"
}
assert first_and_rest(1, 2, 3, 4) == "1 then 3 more"
assert first_and_rest("only") == "only then 0 more"
print("  PASS")

print("Test 3: variadic in for loop")
func collect(...items) {
    var result = []
    for item in items {
        result = result + [item]
    }
    return result
}
assert collect(10, 20, 30) == [10, 20, 30]
print("  PASS")

print("Test 4: variadic forwarding — wrapper passes through")
func call_twice(fn, ...args) {
    return fn(args[0], args[1])
}
func add(a, b) { return a + b }
assert call_twice(add, 3, 4) == 7
print("  PASS")

print("All variadic fix tests passed!")
