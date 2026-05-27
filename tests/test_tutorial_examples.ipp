# Tutorial Examples Test — Exercises every code snippet from REPL_TUTORIAL.md
# Tests keyword examples, builtin functions, and larger code examples.

print("=== Variables & Types ===")
var x = 10
let PI = 3.14159
var name = "World"
var nums = [1, 2, 3, 4, 5]
var person = {"name": "Alice", "age": 30}
var point = (10, 20)
assert x == 10
assert isclose(PI, 3.14159)
assert name == "World"
assert len(nums) == 5
assert person["name"] == "Alice"
assert len(point) == 2

print("=== Keywords ===")
# var, let, if/elif/else
var kv = 0
if kv == 0 { kv = 1 } elif kv == 1 { kv = 2 } else { kv = 3 }
assert kv == 1

# for loop
var fsum = 0
for i in 0..5 { fsum = fsum + i }
assert fsum == 10

# while loop
var ws = 0
while ws < 5 { ws = ws + 1 }
assert ws == 5

# repeat/until
var rv = 0
repeat { rv = rv + 1 } until rv >= 3
assert rv >= 3

# break/continue
var bc_sum = 0
for i in 0..10 {
    if i == 0 { continue }
    if i == 5 { break }
    bc_sum = bc_sum + i
}
assert bc_sum == 10  # 1+2+3+4

# func
func add_kw(a, b) { return a + b }
assert add_kw(2, 3) == 5

# not/and/or
assert not false == true
assert (true and true) == true
assert (false or true) == true

# self/this (in classes)
class ThisDemo {
    func init() { this.val = 42 }
    func get() { return this.val }
}
var td = ThisDemo()
assert td.get() == 42

print("=== Builtins: I/O ===")
print("Hello, World!")
printf("Value: %d\n", 42)
var sf = sprintf("Value: %d", 42)
assert sf == "Value: 42"

print("=== Builtins: Type Conversion ===")
assert type(42) == "number"
assert str(42) == "42"
assert int("42") == 42
assert isclose(float("3.14"), 3.14)
assert bool(1) == true
assert to_number("42") == 42
assert to_string(42) == "42"
assert to_int(3.14) == 3
assert isclose(to_float("3.14"), 3.14)

print("=== Builtins: Math Basic ===")
assert abs(-5) == 5
assert min(3, 7) == 3
assert max(3, 7) == 7
assert round(3.7) == 4
assert floor(3.7) == 3
assert ceil(3.2) == 4
assert sqrt(16) == 4
assert pow(2, 8) == 256

print("=== Builtins: Math Trig ===")
assert isclose(sin(0), 0)
assert isclose(cos(0), 1)
assert isclose(tan(0), 0)
assert isclose(asin(0), 0)
assert isclose(acos(1), 0)
assert isclose(atan(0), 0)
assert isclose(atan2(1, 1), 0.7853981633974483)
assert isclose(radians(180), 3.141592653589793)
assert isclose(degrees(3.141592653589793), 180)

print("=== Builtins: Math Constants ===")
assert isclose(pi, 3.141592653589793)
assert isclose(e, 2.718281828459045)

print("=== Builtins: Math Advanced ===")
assert isclose(log(2.718281828459045), 1)
assert isclose(log10(100), 2)
assert factorial(5) == 120
assert gcd(48, 18) == 6
assert lcm(4, 6) == 12
assert isclose(lerp(0, 10, 0.5), 5)
assert clamp(15, 0, 10) == 10
assert sign(-5) == -1
assert isclose(map_range(5, 0, 10, 0, 100), 50)

print("=== Builtins: Math Easing ===")
var ei = ease_in(0.5)
assert ipp_type(ei) == "number"
var eo = ease_out(0.5)
assert ipp_type(eo) == "number"
var bo = bounce(0.75)
assert ipp_type(bo) == "number"
var sp = spring(0.5, 0.5)
assert ipp_type(sp) == "number"
var ss2 = smoothstep(0, 1, 0.5)
assert ipp_type(ss2) == "number"

print("=== Builtins: Random ===")
var rnd = random()
assert rnd >= 0 and rnd <= 1
var ri = randint(1, 10)
assert ri >= 1 and ri <= 10
var rf = randfloat(0.0, 1.0)
assert rf >= 0.0 and rf <= 1.0
var ch = choice([1, 2, 3])
assert ch >= 1 and ch <= 3
var sh = shuffle([1, 2, 3])
assert len(sh) == 3

print("=== Builtins: List Operations ===")
assert len([1, 2, 3]) == 3
assert sum([1, 2, 3]) == 6
var rg = range(5)
assert len(rg) == 5 and rg[0] == 0 and rg[4] == 4
var rg2 = range(1, 6, 2)
assert rg2 == [1, 3, 5]
var rv_list = reverse([1, 2, 3])
assert rv_list == [3, 2, 1]

print("=== Builtins: Dict ===")
var d = {"a": 1, "b": 2}
var dk = keys(d)
assert "a" in dk and "b" in dk
var dv = values(d)
assert 1 in dv and 2 in dv
assert has_key(d, "a") == true
var di = items(d)
assert len(di) == 2

print("=== Builtins: Set ===")
var s = set([1, 2, 2, 3])
assert ipp_type(s) == "set"

print("=== Builtins: String Basic ===")
assert len("hello") == 5
assert upper("hello") == "HELLO"
assert lower("HELLO") == "hello"
assert strip("  hello  ") == "hello"
assert replace("hello", "l", "r") == "herro"
assert replace_all("lol", "l", "w") == "wow"
assert starts_with("hello", "he") == true
assert ends_with("hello", "lo") == true
assert contains("hello", "ell") == true
assert split("a,b,c", ",") == ["a", "b", "c"]
assert join(["a", "b"], "-") == "a-b"
assert substring("hello", 1, 3) == "el"
assert char_at("hello", 0) == "h"
assert ascii("A") == 65
assert from_ascii(65) == "A"

print("=== Builtins: String Advanced ===")
assert pad_left("hi", 5, "0") == "000hi"
assert pad_right("hi", 5, "0") == "hi000"

print("=== Builtins: Regex ===")
assert regex_match("abc", "\\w+") == true
assert regex_search("abc123", "\\d+") == "123"
assert regex_replace("abc", "b", "X") == "aXc"

print("=== Builtins: Hashing ===")
var m = md5("hello")
assert len(m) == 32
var s1 = sha1("hello")
assert len(s1) == 40
var s256 = sha256("hello")
assert len(s256) == 64

print("=== Builtins: Base64 ===")
var b64 = base64_encode("hello")
assert b64 == "aGVsbG8="
assert base64_decode(b64) == "hello"

print("=== Builtins: URL ===")
var up = url_parse("http://example.com?x=1")
assert ipp_type(up) == "dict"
var ue = url_encode("hello world")
assert contains(ue, "hello")
var ud = url_decode("hello%20world")
assert ud == "hello world"

print("=== Builtins: Misc Utilities ===")
assert type(type) == "function"
assert uuid4() != uuid1()
var w = words("hello world")
assert len(w) == 2
var pb = path_basename("/a/b.txt")
assert pb == "b.txt"
var pd = path_dirname("/a/b.txt")
assert pd == "/a"

print("=== Functions Example ===")
func add_fn(a, b) { return a + b }
assert add_fn(3, 4) == 7
var multiply_fn = func(a, b) => a * b
assert multiply_fn(3, 4) == 12
func factorial_fn(n) {
    if n <= 1 { return 1 }
    return n * factorial_fn(n - 1)
}
assert factorial_fn(5) == 120

print("=== Classes Example ===")
class Animal {
    func init(name) { this.name = name }
    func speak() { return "Some sound" }
}
class Dog : Animal {
    func init(name, breed) {
        super.init(name)
        this.breed = breed
    }
    func speak() { return this.name + " says woof!" }
}
var dog = Dog("Rex", "German Shepherd")
assert dog.speak() == "Rex says woof!"

print("=== Loops Example ===")
var loop_sum = 0
for i in 0..10 { loop_sum = loop_sum + i }
assert loop_sum == 45

var wsum = 0
while wsum < 100 { wsum = wsum + 1 }
assert wsum == 100

print("=== Pattern Matching ===")
var day = 3
var result = match day {
    case 1 => "Monday"
    case 2 => "Tuesday"
    case 3 => "Wednesday"
    default => "Other day"
}
assert result == "Wednesday"

print("=== Error Handling ===")
try {
    throw("test error")
} catch e {
    assert contains(e, "test error")
} finally {
    print("Cleanup done")
}

print("=== Enums ===")
enum Color { RED, GREEN, BLUE }
var c = Color.RED
assert c == Color.RED

print("=== List Comprehensions ===")
var squares = [x * x for x in 1..6]
assert squares == [1, 4, 9, 16, 25]
var evens = [x for x in 1..11 if x % 2 == 0]
assert evens == [2, 4, 6, 8, 10]

print("ALL TUTORIAL EXAMPLES PASSED")
