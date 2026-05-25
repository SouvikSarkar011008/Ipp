var lst = [1, 2, 3, 4, 5, 6]

var first_even = lst.find(func(x) { return x % 2 == 0 })
assert first_even == 2

var first_big = lst.find(func(x) { return x > 10 })
assert first_big == nil

var idx = lst.find_index(func(x) { return x > 3 })
assert idx == 3

var not_found_idx = lst.find_index(func(x) { return x > 100 })
assert not_found_idx == -1

assert lst.contains(3) == true
assert lst.contains(99) == false

assert lst.count(func(x) { return x % 2 == 0 }) == 3

class Enemy { func init(hp) { self.hp = hp } }
var enemies = [Enemy(0), Enemy(50), Enemy(100), Enemy(0)]
var first_alive = enemies.find(func(e) { return e.hp > 0 })
assert first_alive.hp == 50
