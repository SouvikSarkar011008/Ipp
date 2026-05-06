# Test v0.9.0 features

# Test do-while
var count = 0
repeat {
    count = count + 1
} until count > 5
print("Do-while: " + str(count))
assert count == 6

# Test throw
var caught = false
try {
    throw "test error"
} catch e {
    caught = true
    print("Caught: " + str(e))
}
assert caught == true

# Test throw with value
var caught_num = nil
try {
    throw 42
} catch err {
    caught_num = err
    print("Caught number: " + str(err))
}
assert caught_num == 42

print("v0.9.0 tests complete!")
