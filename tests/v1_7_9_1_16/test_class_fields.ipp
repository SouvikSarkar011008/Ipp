# v1.7.9.1.16 — BUG-024 part B: Class-Level Field Declarations

print("Test 1: Basic class-level fields")
class Counter {
    var count = 0
    var name = "counter"

    func increment() {
        self.count = self.count + 1
    }
    func reset() { self.count = 0 }
}

var a = Counter()
var b = Counter()

assert a.count == 0
assert b.count == 0
assert a.name == "counter"

a.increment()
a.increment()
assert a.count == 2
assert b.count == 0    # independent instances
print("  PASS")

print("Test 2: Fields with custom init")
class Sized {
    var capacity = 10
    var items = []

    func init(cap) {
        self.capacity = cap   # overrides field default
    }
}

var s = Sized(20)
assert s.capacity == 20   # init override
assert s.items == []      # field default preserved
print("  PASS")

print("Test 3: let fields (immutable declaration)")
class Config {
    let version = "1.0"
    let max_fps = 60
}
var c = Config()
assert c.version == "1.0"
assert c.max_fps == 60
print("  PASS")

print("Test 4: Multiple classes don't share field values")
class Point {
    var x = 0
    var y = 0
}
var p1 = Point()
var p2 = Point()
p1.x = 10
assert p1.x == 10
assert p2.x == 0   # not shared
print("  PASS")

print("Test 5: Fields without default (nil)")
class HasNil {
    var a
    var b = 42
}
var h = HasNil()
assert h.a == nil
assert h.b == 42
print("  PASS")

print("Test 6: Class with no explicit init and no fields")
class Empty {}
var e = Empty()
print("  PASS")

print("Test 7: Inheritance - fields set in parent init, accessed from child")
class Animal {
    var species = "unknown"
    func init() { self.species = "mammal" }
    func get_species() { return self.species }
}
class Dog : Animal {
    func get_species() { return "dog" }
}
var animal = Animal()
assert animal.species == "mammal"
assert animal.get_species() == "mammal"

var dog = Dog()
# Dog's init is inherited from Animal (no fields on Dog, so no synthesized init)
assert dog.species == "mammal"
print("  PASS")

print("Test 8: Field with complex expression default")
class WithExpr {
    var sum = 1 + 2 + 3
    var msg = "hello " + "world"
}
var we = WithExpr()
assert we.sum == 6
assert we.msg == "hello world"
print("  PASS")

print("All class field tests passed!")
