var a = [1, 2, 3]
var b = ["x", "y", "z"]
var zipped = a.zip(b)
assert zipped == [[1, "x"], [2, "y"], [3, "z"]]

var en = a.enumerate()
assert en == [[0, 1], [1, 2], [2, 3]]

var en1 = a.enumerate(1)
assert en1 == [[1, 1], [2, 2], [3, 3]]

var nested = [[1, 2], [3, 4], [5]]
assert nested.flatten() == [1, 2, 3, 4, 5]

assert [1, 2, 2, 3, 1, 3].unique() == [1, 2, 3]

assert [1, 2, 3, 4, 5].take(3) == [1, 2, 3]
assert [1, 2, 3, 4, 5].drop(2) == [3, 4, 5]

var empty = []
assert empty.zip([]) == []
assert empty.enumerate() == []
assert empty.take(0) == []
assert empty.drop(0) == []
assert empty.unique() == []
assert empty.flatten() == []
