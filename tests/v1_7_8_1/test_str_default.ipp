# Test default __str__ behavior (no __str__ method defined)

class NoStr {
    func init() { self.val = 42 }
    func get() { return self.val }
}
class AlsoNoStr {
    func init(name) { self.name = name }
}

var ns = NoStr()
var ans = AlsoNoStr("test")

var s1 = str(ns)
var s2 = str(ans)

print("NoStr: " + s1)
print("AlsoNoStr: " + s2)

# Use contains to verify class name appears
assert contains(s1, "NoStr") == true
assert contains(s2, "AlsoNoStr") == true
assert contains(s1, "instance") == true

# Verify methods still work after str()
assert ns.get() == 42

print("Default __str__ test passed!")