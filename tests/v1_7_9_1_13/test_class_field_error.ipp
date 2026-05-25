# v1.7.9.1.13 — Class-level field declaration error message (BUG-024 part A)
# Parse errors for bad class bodies are tested in test_class_field_error_msg.py

# --- Basic class with methods still works ---
class Counter {
    func init() { self.count = 0 }
    func inc() { self.count = self.count + 1 }
    func get() { return self.count }
}
var c = Counter()
c.inc()
assert c.get() == 1
c.inc()
assert c.get() == 2

# --- Class with inheritance still works ---
class Animal {
    func init(n) { self.name = n }
    func speak() { return "..." }
}
class Dog : Animal {
    func speak() { return self.name + " woofs" }
}
var d = Dog("Rex")
assert d.speak() == "Rex woofs"
assert d.name == "Rex"

# --- Class with static methods still works ---
class Factory {
    static func create(v) { return v * 2 }
}
assert Factory.create(21) == 42

# --- Class with operator overloading ---
class Vec2 {
    func init(x, y) { self.x = x; self.y = y }
    func __add__(o) { return Vec2(self.x + o.x, self.y + o.y) }
    func __eq__(o) { return self.x == o.x and self.y == o.y }
    func __ne__(o) { return not (self == o) }
    func __lt__(o) { return self.x < o.x or (self.x == o.x and self.y < o.y) }
}
var v1 = Vec2(1, 2)
var v2 = Vec2(3, 4)
var sum = v1 + v2
assert sum == Vec2(4, 6)
assert v1 == Vec2(1, 2)
assert v1 != v2
assert v1 < v2

# --- Class with __str__ still works ---
class Point {
    func init(x, y) { self.x = x; self.y = y }
    func __str__() { return "(" + str(self.x) + "," + str(self.y) + ")" }
}
assert str(Point(5, 7)) == "(5,7)"

# --- Multiple instances are independent ---
var a = Counter()
var b = Counter()
a.inc()
a.inc()
b.inc()
assert a.get() == 2
assert b.get() == 1

print("v1.7.9.1.13: class field error tests PASSED")
