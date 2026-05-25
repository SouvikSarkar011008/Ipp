var nums = [1, 2, 3, 4, 5]

# map
var doubled = nums.map(func(x) { return x * 2 })
assert doubled == [2, 4, 6, 8, 10]

var strs = nums.map(func(x) { return str(x) })
assert strs == ["1", "2", "3", "4", "5"]

# filter
var evens = nums.filter(func(x) { return x % 2 == 0 })
assert evens == [2, 4]

var big = nums.filter(func(x) { return x > 3 })
assert big == [4, 5]

# reduce
var total = nums.reduce(func(acc, x) { return acc + x }, 0)
assert total == 15

var product = nums.reduce(func(acc, x) { return acc * x }, 1)
assert product == 120

# reduce without initial value
var sum_no_init = nums.reduce(func(acc, x) { return acc + x })
assert sum_no_init == 15

# Chaining (single line)
var result = [1,2,3,4,5,6].filter(func(x) { return x % 2 == 0 }).map(func(x) { return x * x })
assert result == [4, 16, 36]

print("OK")
