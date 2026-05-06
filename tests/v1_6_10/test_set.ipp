# Test v1.6.10: IppSet fix
var s = set([1, 2, 3])
print("Created set:")
print(s)
assert len(s) == 3
assert s.has(1) == true
assert s.has(4) == false

print("v1.6.10: IppSet tests PASSED")