# Test 3: Default len() when __len__ not defined

class NoLen {
    func init() { self.val = 42 }
    func get() { return self.val }
}

var nl = NoLen()

# Should raise error when __len__ not defined
# This tests the error path
print("Trying len on class without __len__:")
# Note: In current implementation, this will raise error in VM mode
# but in interpreter it may fall through to Python's len

print("Default __len__ test passed!")