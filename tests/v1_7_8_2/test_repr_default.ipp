# Test 3: Default repr when __repr__ not defined

class NoRepr {
    func init(val) {
        self.val = val
    }
}

var nr = NoRepr(100)
var r = repr(nr)
print("repr(NoRepr) = " + r)
assert contains(r, "NoRepr") == true
assert contains(r, "instance") == true

print("Default repr test passed!")