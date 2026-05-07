# Regression Test Issues Documentation

This document details the issues found when running the regression test suite that tests both the Interpreter and VM modes.

## Overview

The regression test suite (`tests/regression.py`) runs each test file in both:
- **Interpreter mode** - using `main.py run`
- **VM mode** - using direct VM execution

The test passes only if both modes produce the same output.

---

## Test Summary (Updated May 2026)

| Category | Count |
|----------|-------|
| Total test versions | 111 |
| Passing in both modes | **41** |
| **Failing (any reason)** | **65** |

### Recent Fixes Applied

- Fixed `test_try_catch_div.ipp`: Changed `string.contains()` to `contains()` function
- Added all interpreter builtins to VM (110 missing builtins added)
- Fixed kwargs inference bug that broke string arguments to functions

### Failure Breakdown

| Failure Type | Count |
|--------------|-------|
| Outputs differ between modes | ~15 |
| Both fail with different errors | ~25 |
| VM passed but interpreter failed | ~20 |
| Interpreter passed but VM failed | ~5 |

---

## Failing Tests by Category

### 1. Output Mismatch (18 tests)
These tests run but produce different output between Interpreter and VM:

- v0.6.0 - Enum display (Interpreter: `Enum UP: UP`, VM: `Enum UP: 0`)
- v0.10.0 - Class `__str__` behavior
- v1.1.0 - Performance optimization output
- v1.5.2 - WASM Backend (function type name difference)
- v1.5.24 - Output difference
- v1.7.8.1-str-basic - String basics
- v1.7.8.1-str-concat - String concatenation
- v1.7.8.1-str-inherit - String inheritance
- v1.7.8.1-str-collections - String collections
- v1.7.8.2-repr-method - Repr method
- v1.7.8.2-repr-collections - Repr collections
- v1.7.8.2-repr-inheritance - Repr inheritance
- v1.7.8.2-repr-adv - Repr advanced
- v1.7.8.2-repr-collections-adv - Repr collections advanced
- v1.7.8.3-len-basic - Len basic
- v1.7.8.3-len-inheritance - Len inheritance
- v1.7.9-try-nil - Try with nil

### 2. Both Fail with Different Errors (26 tests)
Both Interpreter and VM fail, but with different error messages:

- v0.7.0 - Assertion failure (VM)
- v0.8.0 - Assertion failure (VM)
- v0.9.0 - Assertion failure (VM)
- v0.11.0 - datetime undefined (VM) vs crash (Interpreter)
- v1.0.1 - Different errors
- v1.3.4-dataformats - Data formats
- v1.3.7-repl - REPL features
- v1.3.8 - Various
- v1.3.9 - Error handling
- v1.4.0 - Various
- v1.5.0 - Various
- v1.5.4.3 - 3D math
- v1.5.4.4 - Matrix ops
- v1.5.4.5 - Quaternion
- v1.6.3 - Collections
- v1.6.4 - Various
- v1.6.6 - Various
- v1.6.8 - File I/O
- v1.6.10 - Various
- v1.6.13 - Various
- v1.7.8.2-repr-nested - Nested repr

### 3. VM Passed but Interpreter Failed (21 tests)
VM works but Interpreter crashes or fails:

- v1.3.2 - Core features
- v1.3.4-core - Core builtins
- v1.3.4-string - String functions
- v1.3.4-fileio - File I/O
- v1.3.4-math - Math library
- v1.3.4-collections - Collections
- v1.3.4-advanced - Advanced features
- v1.3.7-vm - VM features
- v1.5.0-async - Async/await
- v1.5.5.0 - 3D Math Basics
- v1.5.5.1 - Matrix Operations
- v1.5.5.2 - Quaternion
- v1.5.5.3 - Scene Graph Classes
- v1.5.5.4 - Basic Renderer
- v1.5.6 - 3D Primitives
- v1.6.9 - Various

### 4. Interpreter Passed but VM Failed (5 tests)
Interpreter works but VM crashes or fails:

- v0.12.0 - Module System
- v1.5.4.6 - Expert Features
- v1.6.7 - Collections
- v1.7.1 - Various
- v1.7.9-try-div - Try/catch division

---

## Root Causes (Common Issues)

### 1. Missing VM Builtins
Many tests fail because the VM is missing builtins that the Interpreter has:
- `datetime`
- `http_get`
- `websocket_connect`
- `deque`
- `seed`
- Various math functions (mat4_*, quat_*)
- Scene/mesh functions

### 2. List/Dict Comprehension Bug
The VM compiler's `compile_list_comprehension` and `compile_dict_comprehension` are broken:
- List comprehension returns `None` instead of the list
- Dict comprehension returns empty `{}`

### 3. Enum Representation
Enums are displayed as integers in VM (`Enum UP: 0`) but as symbols in Interpreter (`Enum UP: UP`)

### 4. Class `__str__` / `__repr__`
- `__str__` works in VM but may fail in Interpreter
- `__repr__` implementation differs between modes

### 5. Assert Statement
The assert statement was previously broken in VM (was parsing as two separate statements). Now fixed but tests may need re-verification.

---

## Not Yet Tested (PyPI Version Missing Features)

The following REPL commands work in local development but may not work in the PyPI-installed version (1.7.9.1):

- `.mem` - Memory usage
- `.tutorial` - Interactive tutorial with auto-advance
- `.tutorial next/prev/end` - Tutorial navigation
- `.alias` (without args) - List aliases
- `.macro` (without args) - List macros
- `.table` - Table display for list of dicts
- `.theme` - Color themes
- `.bg` / `.jobs` - Background jobs

These need to be published to PyPI to be available in the installed package.

---

## Last Updated
- Date: May 2026
- Version: 1.7.9.1
- Test Suite: 111 test versions
- Passing: 38
- Failing: 73