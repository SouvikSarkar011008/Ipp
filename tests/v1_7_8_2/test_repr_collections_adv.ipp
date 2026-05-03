# Advanced __repr__ test 3: Objects with lists

class Team {
    func init(name) {
        self.name = name
        self.members = []
    }
    func add(member) {
        self.members = self.members + [member]
    }
    func __repr__() {
        return "Team(" + self.name + ", " + str(len(self.members)) + " members)"
    }
}

var t = Team("Developers")
t.add("Alice")
t.add("Bob")
t.add("Charlie")

print("Team repr: " + repr(t))
print("Test passed!")