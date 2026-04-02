# Test file for .load command testing
# This file should be loadable via .load in REPL

var loaded_value = 100
print("File loaded successfully!")
print("loaded_value:", loaded_value)

func loaded_func(x) {
    return x * 2
}
print("loaded_func(5):", loaded_func(5))
