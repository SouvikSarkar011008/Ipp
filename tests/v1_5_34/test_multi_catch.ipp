# Test v1.5.34: Multiple catch blocks

# Test basic multiple catches
var log = []
try {
    throw "error one"
} catch e {
    log.append("caught: " + e)
} catch e2 {
    log.append("second catch")
}
assert len(log) == 1
assert log[0] == "caught: error one"

# Test try without error - catches should not run
var log2 = []
try {
    log2.append("try body")
} catch e {
    log2.append("first catch")
} catch e {
    log2.append("second catch")
}
assert log2[0] == "try body"
assert len(log2) == 1

# Test catch with no error - should not run
var log3 = []
try {
    log3.append("ok")
} catch e {
    log3.append("catch")
}
assert log3[0] == "ok"

# Test with finally
var log4 = []
try {
    log4.append("try")
} catch e {
    log4.append("catch")
} finally {
    log4.append("finally")
}
assert log4[0] == "try"
assert log4[1] == "finally"

# Test catch with finally
var log5 = []
try {
    throw "err"
} catch e {
    log5.append("caught")
} finally {
    log5.append("finally")
}
assert log5[0] == "caught"
assert log5[1] == "finally"

print("v1.5.34: Multiple catch blocks tests PASSED")