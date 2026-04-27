# Test v1.6.6: Signal/Event system
var clicked = signal("clicked")

func handler(x, y) {
    print("Clicked at " + str(x) + ", " + str(y))
}

connect(clicked, handler)
emit(clicked, 100, 200)

print("v1.6.6: Signal/Event system tests PASSED")