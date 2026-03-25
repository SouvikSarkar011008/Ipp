# v0.5.0 Feature Tests

# Ternary operator
var t1 = true ? "yes" : "no"
print("Ternary: " + str(t1))

var t2 = false ? "yes" : "no"
print("Ternary false: " + str(t2))

# Match statement
var x = 2
var match_result = 0
match x {
    case 1 => match_result = 1
    case 2 => match_result = 2
    default => match_result = 0
}
print("Match: " + str(match_result))

# Bitwise operators
var and_result = 5 & 3
var or_result = 5 | 3
var xor_result = 5 ^ 3
var shl = 2 << 3
var shr = 8 >> 1
print("AND: " + str(and_result))
print("OR: " + str(or_result))
print("XOR: " + str(xor_result))
print("SHL: " + str(shl))
print("SHR: " + str(shr))

# Floor division
var floor = 7 // 2
print("Floor div: " + str(floor))

# Try/catch/finally
var try_result = "initial"
try {
    throw "error"
} catch e {
    try_result = "caught"
} finally {
    try_result = try_result + "_finally"
}
print("Try/catch: " + str(try_result))

print("v0.5.0 tests complete!")
