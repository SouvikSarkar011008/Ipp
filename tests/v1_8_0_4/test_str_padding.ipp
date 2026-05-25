# v1.8.0.4 — Enhancement: str.pad_left(), str.pad_right(), str.center(), str.zfill()
# Game UI: fixed-width score display, health bars, menu columns

print("Test 1: pad_left")
assert "42".pad_left(6) == "    42"
assert "42".pad_left(6, "0") == "000042"
print("  PASS")

print("Test 2: pad_right")
assert "HP".pad_right(10, ".") == "HP........"
assert "ok".pad_right(5) == "ok   "
print("  PASS")

print("Test 3: center")
assert "ok".center(8, "-") == "---ok---"
assert "a".center(3) == " a "
assert "abc".center(4, "-") == "abc-"
assert "abc".center(5, "-") == "-abc-"
print("  PASS")

print("Test 4: zfill")
assert "7".zfill(3) == "007"
assert "42".zfill(5) == "00042"
assert "-5".zfill(4) == "-005"
print("  PASS")

print("Test 5: game UI score display")
func score_display(score) {
    return "[" + str(score).pad_left(8) + "]"
}
assert score_display(100) == "[     100]"
assert score_display(99999) == "[   99999]"
print("  PASS")

print("Test 6: no padding when n <= len")
assert "hello".pad_left(3) == "hello"
assert "hello".pad_right(3) == "hello"
assert "hello".center(3) == "hello"
assert "hello".zfill(3) == "hello"
print("  PASS")

print("Test 7: empty string")
assert "".pad_left(3) == "   "
assert "".pad_right(3, "x") == "xxx"
assert "".center(3) == "   "
assert "".zfill(3) == "000"
print("  PASS")

print("All string padding tests passed!")
