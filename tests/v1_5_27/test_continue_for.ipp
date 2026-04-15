# Test v1.5.27: continue in for-in loop
# Bug: continue in for-in loop jumped incorrectly

var evens = []
for i in 1..10 {
    if i % 2 != 0 { continue }
    evens.append(i)
}
assert len(evens) == 4
assert evens[0] == 2
assert evens[3] == 8

var visited = []
for x in 1..6 {
    if x == 3 { continue }
    visited.append(x)
}
assert len(visited) == 4
assert visited[0] == 1
assert visited[3] == 5

print("v1.5.27: continue in for-in tests PASSED")