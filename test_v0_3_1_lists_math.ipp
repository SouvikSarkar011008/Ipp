# Test 3: Lists & Math & Random
print("=== Lists ===")
var lst = [1, 2, 3, 4, 5]
print(lst)
print(lst.len())

var d = {"a": 1, "b": 2}
print(d.len())
print(d.keys())
print(d.values())
print(d.get("a"))

print("\n=== Math ===")
print(abs(-5))
print(floor(3.7))
print(ceil(3.2))
print(sqrt(16))
print(pow(2, 3))
print(log(10))
print(sin(0))
print(cos(0))
print(min(1, 2, 3))
print(max(1, 2, 3))

print("\n=== Random ===")
print(random())
print(randint(1, 10))
print(randfloat(0, 1))
print(choice([1, 2, 3]))
print(shuffle([1, 2, 3]))