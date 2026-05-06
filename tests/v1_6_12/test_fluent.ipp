# Test v1.6.12: Fluent list methods
var lst = [3, 1, 4, 1, 5, 9]
lst.sort()
print("Sorted:")
print(lst)
assert lst[0] == 1
assert lst[5] == 9

lst.reverse()
print("Reversed:")
print(lst)
assert lst[0] == 9
assert lst[5] == 1

print("v1.6.12: Fluent list methods tests PASSED")