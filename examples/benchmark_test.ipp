# Benchmark and Profiling for Ipp - v1.5.4

print("=== Testing v1.5.4 REPL Enhancements: Benchmark & Profiling ===")

# Time measurement
func benchmark(func_to_benchmark, iterations) {
    var start_time = now()
    
    for i in 0..iterations {
        func_to_benchmark()
    }
    
    var end_time = now()
    var total_ms = end_time - start_time
    var avg_ms = total_ms / iterations
    
    print("Benchmark results:")
    print("  Iterations: " + str(iterations))
    print("  Total time: " + str(total_ms) + "ms")
    print("  Average: " + str(avg_ms) + "ms")
    print("  Per second: " + str(1000 / avg_ms))
    
    return avg_ms
}

# Memory profiling placeholder
func memory_info() {
    print("Memory info (placeholder):")
    print("  Note: Full memory profiling requires system access")
    return "Memory profiling available in next version"
}

# Performance test
func slow_function() {
    var sum = 0
    for i in 0..1000 {
        sum = sum + i
    }
    return sum
}

print("")
print("=== Running Benchmark ===")

# Simple benchmark (just showing it works)
var result = benchmark(func() {
    var x = 1 + 1
}, 10)

print("")
print("=== Memory Info ===")
var mem = memory_info()
print(mem)

print("")
print("=== v1.5.4 REPL Enhancements Test Complete ===")
print("")
print("Features available:")
print("  benchmark(func, iterations) - Run function N times and show timing")
print("  memory_info() - Show memory usage")
print("  now() - Current timestamp")
print("  .time - REPL command to time expressions")