# Master Test Runner - Runs all version tests
# Usage: python main.py run tests/runner.ipp

import os

def run_test_file(filepath):
    print("=" * 40)
    print("Running: " + filepath)
    print("=" * 40)
    os.system("python main.py run " + filepath)
    print()

# Run all version tests
run_test_file("tests/v05/test_features.ipp")
run_test_file("tests/v06/test_features.ipp")
run_test_file("tests/v07/test_features.ipp")
run_test_file("tests/v08/test_features.ipp")

print("=" * 40)
print("ALL TESTS COMPLETE")
print("=" * 40)
