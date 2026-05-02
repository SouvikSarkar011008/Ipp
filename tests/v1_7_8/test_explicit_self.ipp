# Python-style: explicit self in every method (using init, not __init__)
class Counter {
    func init(self) {
        self.count = 0
    }
    func increment(self) {
        self.count = self.count + 1
    }
    func reset(self) {
        self.count = 0
    }
    func get(self) {
        return self.count
    }
}

var c = Counter()
assert c.get() == 0
c.increment()
c.increment()
c.increment()
assert c.get() == 3
c.reset()
assert c.get() == 0

# Also works with extends and explicit self
class LimitedCounter extends Counter {
    func init(self, limit) {
        self.count = 0
        self.limit = limit
    }
    func increment(self) {
        if self.count < self.limit {
            self.count = self.count + 1
        }
    }
}

var lc = LimitedCounter(3)
lc.increment()
lc.increment()
lc.increment()
lc.increment()   # should be ignored
assert lc.get() == 3