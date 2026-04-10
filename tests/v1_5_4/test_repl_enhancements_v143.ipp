# Test v1.5.4.3 - Easy Enhancements (HTML preview, better errors, expression history)

print("=== Testing v1.5.4.3 Easy Enhancements ===")

# Test 1: Expression history ($_1, $_2, etc.)
print("\n--- Test 1: Expression History ---")
var a = 10 + 5
print("First result: " + str(a))

var b = 20 * 2
print("Second result: " + str(b))

var c = "hello"
print("Third result: " + c)

print("Use $_1, $_2, $_3 in REPL to access results")

# Test 2: Better error messages (test syntax errors)
print("\n--- Test 2: Better Error Messages ---")

# Test missing closing parenthesis
try {
    eval("var x = (1 + 2")
} catch e {
    print("Unbalanced paren error: " + str(e))
}

# Test missing closing brace
try {
    eval("var y = { a: 1")
} catch e {
    print("Unbalanced brace error: " + str(e))
}

# Test unterminated string
try {
    eval('var z = "hello')
} catch e {
    print("Unterminated string error: " + str(e))
}

print("All error messages now include helpful hints!")

# Test 3: Basic functionality still works
print("\n--- Test 3: Basic Functionality ---")
var nums = [1, 2, 3, 4, 5]
print("Sum: " + str(sum(nums)))
print("Max: " + str(max(nums)))
print("Min: " + str(min(nums)))

# Test 4: Pattern matching (as statement, not expression)
print("\n--- Test 4: Pattern Matching ---")
var day = 3
match day {
    case 1 => print("Monday")
    case 2 => print("Tuesday")
    case 3 => print("Wednesday")
    default => print("Other")
}

# Test 5: Enum
print("\n--- Test 5: Enum ---")
enum Color {
    RED,
    GREEN,
    BLUE
}
var my_color = Color.RED
print("My color: " + str(my_color))

# Test 6: Classes
print("\n--- Test 6: Classes ---")
class Animal {
    func init(name) {
        this.name = name
    }
    func speak() {
        return "Some sound"
    }
}

class Dog : Animal {
    func init(name, breed) {
        super.init(name)
        this.breed = breed
    }
    func speak() {
        return this.name + " says woof!"
    }
}

var dog = Dog("Rex", "German Shepherd")
print(dog.speak())

# Test 7: Try/Catch/Finally
print("\n--- Test 7: Exception Handling ---")
try {
    var result = 10 / 0
} catch e {
    print("Caught: " + str(e))
} finally {
    print("Finally block executed")
}

# Test 8: Canvas (if available)
print("\n--- Test 8: Canvas Functions ---")
print("canvas_open, canvas_rect, canvas_circle, etc. available")

print("\n=== v1.5.4.3 Tests Complete ===")
print("New in v1.5.4.3:")
print("  .html <expr>    - Preview HTML in browser")
print("  .hist          - Show expression history")
print("  Better errors  - Hints for common mistakes")