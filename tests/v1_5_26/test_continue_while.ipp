# Test v1.5.26: continue in while loop
# Bug: continue acted as break, exiting the loop entirely

var r = 0
var i = 0
while i < 5 {
    i = i + 1
    if i == 3 { continue }
    r = r + i
}
assert r == 12

# Ensure loop completes to end (not early exit)
var iters = 0
var j = 0
while j < 10 {
    j = j + 1
    if j % 2 == 0 { continue }
    iters = iters + 1
}
assert iters == 5
assert j == 10

print("v1.5.26: continue in while tests PASSED")