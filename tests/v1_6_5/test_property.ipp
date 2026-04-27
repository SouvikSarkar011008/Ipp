# Test v1.6.5: Property accessors
class Health {
    func init() { self._hp = 100 }
    prop hp {}
}

var h = Health()
assert h._hp == 100

print("v1.6.5: Property accessor tests PASSED")