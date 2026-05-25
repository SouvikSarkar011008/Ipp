# v1.7.9.1.17 — assert with custom error message

print("Test 1: Assert without message — unchanged")
assert 1 + 1 == 2
assert true
print("  PASS")

print("Test 2: Assert with message — condition true, no error")
assert true, "this should never fire"
assert 2 + 2 == 4, "math is broken"
print("  PASS")

print("Test 3: Assert with message — catches custom message on failure")
var caught = ""
try {
    assert false, "custom failure message"
} catch e {
    caught = e
}
assert contains(caught, "custom failure message") == true
print("  PASS")

print("Test 4: Expression in message — evaluated only on failure")
var hp = -5
try {
    assert hp > 0, "hp must be positive, got: " + str(hp)
} catch e {
    assert contains(e, "-5") == true
    assert contains(e, "hp must be positive") == true
}
print("  PASS")

print("Test 5: Game invariant — positive assertion passes")
var player_speed = 5.0
try {
    assert player_speed > 0, "player_speed must be positive"
} catch e {
    assert false
}
print("  PASS")

print("Test 6: Works with isclose from v1.7.9.1.12")
var val = 0.1 + 0.2
assert isclose(val, 0.3), "expected 0.3, got: " + str(val)
print("  PASS")

print("All assert message tests passed!")
