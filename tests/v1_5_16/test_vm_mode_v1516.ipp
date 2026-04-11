# Test v1.5.16 - VM Mode

print("=== Testing v1.5.16 VM Mode ===")

# Test for loop in VM mode
var sum = 0
for i in 0..5 {
    sum = sum + i
}
print("for loop sum: " + str(sum))

# Test function in VM mode
func add(a, b) {
    return a + b
}
var result = add(2, 3)
print("function return: " + str(result))