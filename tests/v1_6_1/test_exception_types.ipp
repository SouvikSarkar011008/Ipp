# Test v1.6.1: Exception type hierarchy

# Test typed catch
var kind = ""
try { 
    throw "ValueError: bad thing"
} catch ValueError e { 
    kind = "ValueError"
} catch e { 
    kind = "other"
}
assert kind == "ValueError"

# Test unmatched type falls through to next catch
kind = ""
try { 
    throw "TypeError: wrong type"
} catch ValueError e { 
    kind = "ValueError"
} catch TypeError e { 
    kind = "TypeError"
} catch e { 
    kind = "other"
}
assert kind == "TypeError"

# Test untyped catch catches all
kind = ""
try { 
    throw "some error"
} catch ValueError e { 
    kind = "ValueError"
} catch e { 
    kind = "other"
}
assert kind == "other"

# Test finally still runs
var finally_ran = false
try {
    throw "Error: test"
} catch e {
    kind = "caught"
} finally {
    finally_ran = true
}
assert finally_ran == true

print("v1.6.1: Exception type hierarchy tests PASSED")