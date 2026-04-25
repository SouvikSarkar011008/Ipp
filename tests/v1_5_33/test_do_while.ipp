# Test v1.5.33: do-while syntax
# Bug: `do { } while` syntax was missing + interpreter condition logic was inverted

var i = 0
do { i = i + 1 } while i < 5
assert i == 5

# Test: runs at least once even when condition is false
var ran = false
do { ran = true } while false
assert ran == true

# Test with existing repeat/until syntax (should still work)
var j = 0
repeat { j = j + 1 } until j >= 3
assert j == 3

print("v1.5.33: do-while syntax tests PASSED")