# Test v1.6.2: Decorator execution
# Syntax: @decorator\nfunc f() {} compiles as func f() {}; f = decorator(f)

func memoize(f) {
    var cache = {}
    func wrapper(n) {
        if cache[n] == nil { cache[n] = f(n) }
        return cache[n]
    }
    return wrapper
}

@memoize
func fib(n) { if n <= 1 { return n } return fib(n-1) + fib(n-2) }

assert fib(10) == 55
assert fib(5) == 5

func add_logging(fn) {
    func logged(x) {
        return fn(x) + 1
    }
    return logged
}

@add_logging
func double(x) { return x * 2 }

assert double(3) == 7

print("v1.6.2: Decorator execution tests PASSED")