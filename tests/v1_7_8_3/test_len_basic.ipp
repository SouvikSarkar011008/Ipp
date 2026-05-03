# Simple __len__ test - with more debugging
class Bag {
    func init() { 
        self._count = 0 
    }
    func __len__() { 
        print("__len__ called")
        return self._count 
    }
}

var b = Bag()
print("Before len call")
var x = len(b)
print("After len call, result: " + str(x))
print("Test passed!")