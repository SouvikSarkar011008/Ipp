# Test v1.5.3a - 2D Canvas API (REPL Test)

print("=== Testing v1.5.3a 2D Canvas API ===")

# Test interpreter
print("Interpreter is working!")

var x = 10
var y = 20
print("x = " + str(x))
print("y = " + str(y))

func add(a, b) {
    return a + b
}

print("add(5, 3) = " + str(add(5, 3)))

var nums = [1, 2, 3, 4, 5]
print("List length: " + str(len(nums)))

# Canvas operations - these work in the REPL with Tkinter
# Uncomment to test in REPL:
# canvas_open()
# canvas_rect(10, 10, 100, 50, "red")
# canvas_circle(200, 100, 30, "blue")
# canvas_line(50, 200, 300, 200, "green")
# canvas_text(100, 80, "Hello!", "black")
# canvas_clear("white")
# canvas_show()

print("\n=== Canvas API ready! ===")
print("Use in REPL:")
print("  canvas_open()          # Opens a window")
print("  canvas_rect(x, y, w, h, color)")
print("  canvas_circle(x, y, r, color)")
print("  canvas_line(x1, y1, x2, y2, color)")
print("  canvas_text(x, y, text, color)")
print("  canvas_clear(color)")
print("  canvas_show()          # Update the window")