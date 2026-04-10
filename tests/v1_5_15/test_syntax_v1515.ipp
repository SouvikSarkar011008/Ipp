# Test v1.5.15 - Syntax Additions

print("=== Testing v1.5.15 Syntax Additions ===")

# Test 1: Lambda with func keyword
var add = func(x, y) => x + y
print(add(2, 3))

# Test 2: Single param lambda
var square = func(x) => x * x
print(square(5))

# Test 3: Lambda with string
var greet = func(name) => "Hello, " + name
print(greet("World"))

# Test 4: Lambda with default
var greet2 = func(name, greeting = "Hi") => greeting + ", " + name
print(greet2("Bob"))
print(greet2("Bob", "Hello"))

# Test 5: Lambda with multiple statements
var mul = func(a, b) {
    var result = a * b
    return result
}
print(mul(3, 4))

# Test 6: Enum declaration
enum Color {
    RED,
    GREEN,
    BLUE
}
print(Color.RED)

# Test 7: Match statement
var n = 2
var msg = match n {
    case 1 => "one"
    case 2 => "two"
    case 3 => "three"
    else => "other"
}
print(msg)

# Test 8: Match with multiple cases
var day = 3
var day_name = match day {
    case 1 => "Monday"
    case 2 => "Tuesday"
    case 3 => "Wednesday"
    case 4 => "Thursday"
    case 5 => "Friday"
    case 6 => "Saturday"
    case 7 => "Sunday"
    else => "Invalid"
}
print(day_name)

print("=== All v1.5.15 Tests Passed ===")