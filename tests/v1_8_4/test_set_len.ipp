var s = set([1, 2, 3, 2, 1])
assert len(s) == 3

var empty = set([])
assert len(empty) == 0

var s2 = set([1, 1, 1, 1])
assert len(s2) == 1

s2.add(2)
assert len(s2) == 2
s2.remove(1)
assert len(s2) == 1
assert s2.contains(2) == true
assert s2.contains(1) == false

print("OK")
