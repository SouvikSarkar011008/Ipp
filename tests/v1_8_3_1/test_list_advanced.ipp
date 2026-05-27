# flat_map
var sentences = ["hello world", "foo bar"]
var words = sentences.flat_map(func(s) { return s.split(" ") })
assert words == ["hello", "world", "foo", "bar"]

# sort_by
var words2 = ["banana", "apple", "cherry", "date"]
var sorted = words2.sort_by(func(w) { return len(w) })
assert sorted == ["date", "apple", "banana", "cherry"]

var by_last = words2.sort_by(func(w) { return w[-1] })
assert by_last[0] == "banana"

# group_by
var nums = [1, 2, 3, 4, 5, 6]
var grouped = nums.group_by(func(x) { return x % 2 == 0 ? "even" : "odd" })
assert grouped["even"] == [2, 4, 6]
assert grouped["odd"] == [1, 3, 5]

# group_by with objects
class Enemy { func init(t, hp) { self.type = t; self.hp = hp } }
var enemies = [Enemy("orc", 50), Enemy("goblin", 20), Enemy("orc", 80)]
var by_type = enemies.group_by(func(e) { return e.type })
assert len(by_type["orc"]) == 2
assert len(by_type["goblin"]) == 1

print("OK")
