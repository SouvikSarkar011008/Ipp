# Test v1.6.6: Signal/Event system
var clicked = signal("clicked")

func handler(x, y) {
    print("Clicked at " + str(x) + ", " + str(y))
}

connect(clicked, handler)
emit(clicked, 100, 200)

# Test that signal works
var test_sig = signal("test")
var received = false
func receiver() {
    received = true
}
connect(test_sig, receiver)
emit(test_sig)
assert received == true

print("v1.6.6: Signal/Event system tests PASSED")