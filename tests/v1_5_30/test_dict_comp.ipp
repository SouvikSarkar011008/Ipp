# Test v1.5.30: Dict comprehension
# Works in interpreter mode

var doubled = {k: k * 2 for k in range(5)}
assert doubled[0] == 0
assert doubled[3] == 6
assert doubled[4] == 8

var filtered = {k: k for k in range(10) if k % 2 == 0}
assert len(filtered) == 5
assert filtered[6] == 6

print("v1.5.30: Dict comprehension tests PASSED")