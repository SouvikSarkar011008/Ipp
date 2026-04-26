# Test v1.5.35: Variadic parameters

func sum_all(...nums) {
    var total = 0
    for n in nums { total = total + n }
    return total
}

assert sum_all(1, 2, 3) == 6
assert sum_all(10) == 10
assert sum_all() == 0

func head_tail(first, ...rest) {
    return [first, rest]
}
var r = head_tail(1, 2, 3, 4)
assert r[0] == 1
assert len(r[1]) == 3
assert r[1][0] == 2
assert r[1][1] == 3
assert r[1][2] == 4

func print_all(...args) {
    var result = ""
    for a in args {
        result = result + a
    }
    return result
}
assert print_all("a", "b", "c") == "abc"

func mixed(a, ...rest) {
    return [a, rest]
}
var m = mixed("first", "second", "third")
assert m[0] == "first"
assert m[1][0] == "second"
assert m[1][1] == "third"

print("v1.5.35: Variadic parameters tests PASSED")