# Test v1.6.11: TAIL_CALL fix
func count_down(n) {
    if n == 0 { return "done" }
    return count_down(n - 1)
}

var result = count_down(10)
assert result == "done"

print("v1.6.11: TAIL_CALL tests PASSED")