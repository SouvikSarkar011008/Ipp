# v1.8.1.1 — Enhancement: list.extend(), insert(), clear(), copy()

print("Test 1: extend")
var lst = [1, 2, 3]
lst.extend([4, 5, 6])
assert lst == [1, 2, 3, 4, 5, 6]
print("  PASS")

print("Test 2: insert")
var lst2 = [1, 2, 3]
lst2.insert(0, 0)
assert lst2 == [0, 1, 2, 3]
assert len(lst2) == 4
lst2.insert(4, 4)
assert lst2 == [0, 1, 2, 3, 4]
print("  PASS")

print("Test 3: copy")
var original = [1, 2, 3]
var copy = original.copy()
assert copy == [1, 2, 3]
copy.append(4)
assert len(copy) == 4
assert len(original) == 3
print("  PASS")

print("Test 4: clear")
var lst4 = [1, 2, 3]
lst4.clear()
assert len(lst4) == 0
assert lst4 == []
print("  PASS")

print("Test 5: existing list methods still work")
var lst5 = [3, 1, 2]
lst5.sort()
assert lst5 == [1, 2, 3]
lst5.pop()
assert lst5 == [1, 2]
lst5.reverse()
assert lst5 == [2, 1]
print("  PASS")

print("All list mutation tests passed!")
