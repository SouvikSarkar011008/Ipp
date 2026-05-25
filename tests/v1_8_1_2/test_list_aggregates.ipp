var nums = [3, 1, 4, 1, 5, 9, 2, 6]

assert nums.min() == 1
assert nums.max() == 9
assert nums.sum() == 31

assert [true, true, true].all() == true
assert [true, false, true].all() == false
assert [false, false, true].any() == true
assert [false, false, false].any() == false

var evens_exist = nums.any(func(x) { return x % 2 == 0 })
assert evens_exist == true

var all_positive = nums.all(func(x) { return x > 0 })
assert all_positive == true

var nested = [[1,2],[3,4],[5]]
assert nested.flat() == [1,2,3,4,5]

var empty = []
assert empty.any() == false
assert empty.all() == true
