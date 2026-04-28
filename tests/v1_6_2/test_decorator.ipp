# Test v1.6.2: Decorator execution
# Syntax: @decorator\nfunc f() {} compiles as func f() {}; f = decorator(f)

func memoize(f) {
    func wrapper(n) { return f(n) }
    return wrapper
}

@memoize
func fib(n) { return n }
assert fib(10) == 10

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