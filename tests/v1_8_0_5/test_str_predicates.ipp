# v1.8.0.5 — Enhancement: str.is_digit(), str.is_alpha(), str.is_alnum(), str.is_space()
# Input validation: game chat filters, username validators, config parsers

print("Test 1: is_digit")
assert "123".is_digit() == true
assert "12a".is_digit() == false
assert "".is_digit() == false
assert "0".is_digit() == true
print("  PASS")

print("Test 2: is_alpha")
assert "abc".is_alpha() == true
assert "ABC".is_alpha() == true
assert "abc123".is_alpha() == false
assert "".is_alpha() == false
print("  PASS")

print("Test 3: is_alnum")
assert "abc123".is_alnum() == true
assert "abc 123".is_alnum() == false
assert "a1".is_alnum() == true
assert "".is_alnum() == false
print("  PASS")

print("Test 4: is_space")
assert "   ".is_space() == true
assert "".is_space() == false
assert "a ".is_space() == false
assert "\t\n".is_space() == true
print("  PASS")

print("Test 5: is_upper")
assert "ABC".is_upper() == true
assert "Abc".is_upper() == false
assert "A".is_upper() == true
assert "".is_upper() == false
print("  PASS")

print("Test 6: is_lower")
assert "abc".is_lower() == true
assert "Abc".is_lower() == false
assert "a".is_lower() == true
assert "".is_lower() == false
print("  PASS")

print("Test 7: input validation use case")
func valid_username(name) {
    return len(name) >= 3 and len(name) <= 20 and name.is_alnum() == true
}
assert valid_username("alice123") == true
assert valid_username("al") == false
assert valid_username("bad name!") == false
assert valid_username("abcdefghijklmnopqrst") == true
assert valid_username("abcdefghijklmnopqrstu") == false
print("  PASS")

print("All string predicate tests passed!")
