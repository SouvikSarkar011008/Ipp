# Advanced __repr__ test 2: Nested objects - simplified

class Address {
    func init(street, city) {
        self.street = street
        self.city = city
    }
    func __repr__() {
        return self.street + ", " + self.city
    }
}

class Employee {
    func init(name, address) {
        self.name = name
        self.address = address
    }
    func __repr__() {
        return self.name + " lives at " + repr(self.address)
    }
}

var addr = Address("123 Main", "Boston")
var emp = Employee("Bob", addr)

print("Employee repr: " + repr(emp))
print("Address repr: " + repr(addr))
print("Test passed!")