# v0.7.0 Feature Tests

# List comprehension
var squares = [i*i for i in 1..5]
print("Squares: " + str(squares))

var evens = [x for x in 1..10 if x % 2 == 0]
print("Evens: " + str(evens))

# Dict comprehension
var d1 = {k: k*2 for k in [1, 2, 3, 4, 5]}
print("Dict doubled: " + str(d1))

# Note: dict-to-dict comprehension syntax differs
var d2 = {k: k*10 for k in [1, 2, 3]}
print("Dict: " + str(d2))

# Nested comprehension
var matrix = [[i*j for j in 1..4] for i in 1..4]
print("Matrix: " + str(matrix))

# From list
var nums = [1, 2, 3, 4, 5]
var doubled = [x*2 for x in nums]
print("Doubled: " + str(doubled))

# String iteration
var word = "hello"
var chars = [c for c in word]
print("Chars: " + str(chars))

print("v0.7.0 tests complete!")
