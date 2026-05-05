#!/usr/bin/env python3
"""Test v1.7.9.1: VM error messages with line numbers in both modes"""
import subprocess
import sys
import os

script_dir = os.path.dirname(os.path.abspath(__file__))
root_dir = os.path.dirname(os.path.dirname(script_dir))
print(f"script_dir: {script_dir}")
print(f"root_dir: {root_dir}")
os.chdir(root_dir)
print(f"cwd: {os.getcwd()}")

source = """
# Test error messages include line numbers
var result = 10 / 0
"""

test_file = os.path.join(script_dir, "temp_test.ipp")
print(f"test_file: {test_file}")
with open(test_file, "w") as f:
    f.write(source)

print("=" * 50)
print("Testing INTERPRETER mode")
print("=" * 50)
result = subprocess.run(
    [sys.executable, "main.py", "run", "tests/v1_7_9_1/temp_test.ipp"],
    capture_output=True,
    text=True
)
print("STDOUT:", result.stdout)
print("STDERR:", result.stderr)
print("Return code:", result.returncode)
interpreter_has_line = "line" in (result.stdout + result.stderr).lower()

print("\n" + "=" * 50)
print("Testing VM mode")
print("=" * 50)

# For VM mode, we need to use the VM interpreter. Looking at main.py,
# the REPL has .vm command to switch to VM mode. For running files,
# we need to check if there's a way to run with VM.
# Let's check the ipp/main.py run_file function which has bytecode caching

# Actually, the simplest way is to use the REPL with .vm and load the file
# But for automated testing, let's create a simple Python test that uses the VM directly

# Create a Python test that imports local modules
vm_test_code = '''
import sys
import os

# Remove installed ipp package
for mod_name in list(sys.modules.keys()):
    if mod_name == "ipp" or mod_name.startswith("ipp."):
        del sys.modules[mod_name]

# Use local ipp
sys.path.insert(0, os.getcwd())

from ipp.lexer.lexer import tokenize
from ipp.parser.parser import parse
from ipp.vm.compiler import compile_ast
from ipp.vm.vm import VM

source = """
# Test error messages include line numbers
var result = 10 / 0
"""

tokens = tokenize(source)
ast = parse(tokens)

# Debug: Check line numbers in AST
print("=== AST Debug ===")
for stmt in ast.statements:
    print(f"Stmt type: {type(stmt).__name__}, line: {getattr(stmt, 'line', 0)}")
    if hasattr(stmt, 'initializer') and stmt.initializer:
        print(f"  initializer type: {type(stmt.initializer).__name__}, line: {getattr(stmt.initializer, 'line', 0)}")
        if hasattr(stmt.initializer, 'left'):
            print(f"    left type: {type(stmt.initializer.left).__name__}, line: {getattr(stmt.initializer.left, 'line', 0)}")
        if hasattr(stmt.initializer, 'right'):
            print(f"    right type: {type(stmt.initializer.right).__name__}, line: {getattr(stmt.initializer.right, 'line', 0)}")

chunk = compile_ast(ast)

print(f"DEBUG: chunk.lines = {chunk.lines}")

vm = VM()
try:
    vm.run(chunk)
    print("ERROR: Expected exception but got none")
except Exception as e:
    error_msg = str(e)
    print(f"VM Error: {error_msg}")
    if "line " in error_msg:  # Look for "line " specifically
        print("SUCCESS: VM has line info")
    else:
        print("FAIL: VM missing line info")
'''

vm_test_file = os.path.join(script_dir, "test_vm_direct.py")
with open(vm_test_file, "w") as f:
    f.write(vm_test_code)

result = subprocess.run(
    [sys.executable, vm_test_file],
    capture_output=True,
    text=True,
    cwd=root_dir
)
print("STDOUT:", result.stdout)
print("STDERR:", result.stderr)
print("Return code:", result.returncode)
vm_has_line = "SUCCESS" in result.stdout

# Clean up
try:
    os.remove(test_file)
    os.remove(vm_test_file)
except:
    pass

print("\n" + "=" * 50)
print("RESULTS")
print("=" * 50)
print(f"Interpreter has line info: {interpreter_has_line}")
print(f"VM has line info: {vm_has_line}")

if interpreter_has_line and vm_has_line:
    print("\nSUCCESS: Both modes have line info in error messages!")
    sys.exit(0)
else:
    print("\nFAIL: Missing line info")
    sys.exit(1)