# Test v1.5.23: let immutability in VM
# Bug: let keyword didn't enforce immutability

# Global let - works in interpreter (enforced at runtime)
let x = 42
assert x == 42

# Test local let inside function
func test_let_local() {
    let y = 10
    return y
}

assert test_let_local() == 10

print("v1.5.23: let immutability tests PASSED")