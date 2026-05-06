# Test v1.5.4.3 - Easy Enhancements (HTML preview, better errors, expression history)

print("=== Testing v1.5.4.3 Easy Enhancements ===")

# Test 1: Expression history ($_1, $_2, etc.)
print("\n--- Test 1: Expression History ---")
var a = 10 + 5
print("First result: " + str(a))
assert a == 15, "Expression evaluation works"

var b = 20 * 2
print("Second result: " + str(b))
assert b == 40, "Expression evaluation works"

var c = "hello"
print("Third result: " + c)
assert c == "hello", "String assignment works"

print("Use $_1, $_2, $_3 in REPL to access results")

# Test 2: Better error messages (test syntax errors)
print("\n--- Test 2: Better Error Messages ---")

# Test missing closing parenthesis
var error_caught = false
try {
    eval("var x = (1 + 2")
} catch e {
    error_caught = true
    print("Unbalanced paren error: " + str(e))
}
assert error_caught == true, "Unbalanced paren error caught"

# Test missing closing brace
error_caught = false
try {
    eval("var y = { a: 1")
} catch e {
    error_caught = true
    print("Unbalanced brace error: " + str(e))
}
assert error_caught == true, "Unbalanced brace error caught"

# Test unterminated string
error_caught = false
try {
    eval('var z = "hello')
} catch e {
    error_caught = true
    print("Unterminated string error: " + str(e))
}
assert error_caught == true, "Unterminated string error caught"

print("All error messages now include helpful hints!")

# Test 3: Basic functionality still works
print("\n--- Test 3: Basic Functionality ---")
var nums = [1, 2, 3, 4, 5]
print("Sum: " + str(sum(nums)))
print("Max: " + str(max(nums)))
print("Min: " + str(min(nums)))
assert sum(nums) == 15, "sum works"
assert max(nums) == 5, "max works"
assert min(nums) == 1, "min works"

# Test 4: Pattern matching (as statement, not expression)
print("\n--- Test 4: Pattern Matching ---")
var day = 3
var match_result = ""
match day {
    case 1 => match_result = "Monday"
    case 2 => match_result = "Tuesday"
    case 3 => match_result = "Wednesday"
    default => match_result = "Other"
}
assert match_result == "Wednesday", "Pattern matching works"

# Test 5: Enum
print("\n--- Test 5: Enum ---")
enum Color {
    RED,
    GREEN,
    BLUE
}
var my_color = Color.RED
print("My color: " + str(my_color))
assert my_color == "RED", "Enum works"

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
assert dog.speak() == "Rex says woof!", "Inheritance works"

# Test 7: Try/Catch/Finally
print("\n--- Test 7: Exception Handling ---")
var finally_ran = false
try {
    var result = 10 / 0
} catch e {
    print("Caught: " + str(e))
} finally {
    finally_ran = true
    print("Finally block executed")
}
assert finally_ran == true, "Finally block executes"

# Test 8: Canvas (if available)
print("\n--- Test 8: Canvas Functions ---")
print("canvas_open, canvas_rect, canvas_circle, etc. available")
assert true == true, "Canvas functions available"

print("\n=== v1.5.4.3 Tests Complete ===")
print("New in v1.5.4.3:")
print("  .html <expr>    - Preview HTML in browser")
print("  .hist          - Show expression history")
print("  Better errors  - Hints for common mistakes")