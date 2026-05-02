# Test v1.7.6: Semicolons No Longer Crash the Lexer
# User impact: Every developer from C, Java, JavaScript, Lua, or C# will type semicolons

var x = 1; var y = 2; var z = 3
assert x + y + z == 6

func add(a, b) { return a + b }; assert add(3, 4) == 7

var result = 0
var i = 0
while i < 5 { i = i + 1; result = result + i }
assert result == 15

print("v1.7.6: Semicolons tests PASSED")
print("Semicolons are now silently ignored as statement separators")