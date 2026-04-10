# Test v1.5.12 - Documentation & Testing

print("=== Testing v1.5.12 Documentation & Testing ===")

# Test 1: doc function
print("\n--- Test 1: Doc Function ---")
var d = doc(print)
print("Doc for print: " + str(d))

# Test 2: API documentation
print("\n--- Test 2: API Documentation ---")
var api = apidoc()
print("API functions: " + str(api))

# Test 3: Test run
print("\n--- Test 3: Test Run ---")
var tr = test_run("tests/v05/hello.ipp")
print("Test run: " + str(tr))

# Test 4: Test report
print("\n--- Test 4: Test Report ---")
var report = test_report()
print("Report: " + str(report))

# Test 5: Benchmark full
print("\n--- Test 5: Full Benchmark ---")
var bench = benchmark_full()
print("Benchmark: " + str(bench))

# Test 6: Examples list
print("\n--- Test 6: Examples List ---")
var ex = examples_list()
print("Examples: " + str(ex))

print("\n=== v1.5.12 Tests Complete ===")
print("New in v1.5.12:")
print("  doc(fn)            - Get documentation for builtin")
print("  apidoc()          - Generate API documentation")
print("  test_run(path)    - Run test file")
print("  test_report()     - Generate test coverage report")
print("  benchmark_full()  - Run full benchmark suite")
print("  examples_list()   - List available examples")