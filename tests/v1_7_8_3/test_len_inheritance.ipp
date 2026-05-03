# Test 2: __len__ with inheritance

class Container {
    func init() { self.items = [] }
    func add(it) { self.items = self.items + [it] }
    func __len__() { return len(self.items) }
}

class Stack extends Container {
    func init() {
        self.items = []
    }
    func push(item) {
        self.items = self.items + [item]
    }
    func __len__() {
        return len(self.items)
    }
}

var s = Stack()
print("Empty stack: " + str(len(s)))
assert len(s) == 0

s.push(1)
s.push(2)
s.push(3)
print("Stack with 3: " + str(len(s)))
assert len(s) == 3

print("Inheritance __len__ test passed!")