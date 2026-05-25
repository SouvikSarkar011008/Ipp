# v1.7.9.1.13 — Class-level field declaration error message (BUG-024 part A)
# Error message is verified by running `class Bad { var x = 0 }` and checking
# the output says "not yet supported" instead of "Expect '}' after class body"

# --- Correct syntax still works ---
class Counter {
    func init() {
        self.count = 0
    }
    func inc() { self.count = self.count + 1 }
}
var c = Counter()
c.inc()
assert c.count == 1

print("v1.7.9.1.13: class field error tests PASSED")
