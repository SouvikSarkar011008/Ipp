# Regression Test Issues Documentation

This document details the issues found when running the regression test suite that tests both the Interpreter and VM modes.

## Overview

The regression test suite (`tests/regression.py`) runs each test file in both:
- **Interpreter mode** - using `main.py run`
- **VM mode** - using direct VM execution

The test passes only if both modes produce the same output.

---

## Known Issues Summary

| Category | Count | Status |
|----------|-------|--------|
| Tests passing in both modes | ~60+ | ✅ Working |
| Output mismatch (different outputs) | ~10 | ⚠️ Known Difference |
| VM assertion failures | ~15 | ❌ Bug |
| Interpreter crashes, VM works | ~5 | ❌ Bug |
| Both crash differently | ~5 | ❌ Bug |

---

## Detailed Issues

### 1. Output Mismatch: v0.6.0 Enum Display

**Test:** `tests/v06/test_features.ipp`

**Issue:** Enums display differently between modes.

- **Interpreter:** `Enum UP: UP`, `Enum DOWN: DOWN`
- **VM:** `Enum UP: 0`, `Enum DOWN: 1`

**Root Cause:** The VM evaluates enums as their integer values while Interpreter preserves the symbolic name.

**Severity:** Low - Semantic equivalence, just display difference.

---

### 2. Output Mismatch: v0.10.0 Class `__str__`

**Test:** `tests/v10/test_features.ipp`

**Issue:** Class `__str__` method works in VM but not in Interpreter.

- **Interpreter:** Empty output (crashes silently)
- **VM:** `Person: Alice`

**Root Cause:** Unknown - likely issue with how Interpreter handles `__str__` vs VM.

**Severity:** Medium - Functionality regression.

---

### 3. VM Assertion Failures: v0.7.0, v0.8.0, v0.9.0

**Tests:**
- `tests/v07/test_features.ipp`
- `tests/v08/test_features.ipp`
- `tests/v09/test_features.ipp`

**Issue:** Tests pass in Interpreter but fail with "Assertion failed" in VM.

**Example (v0.7.0):**
```
INTERPRETER: Works fine
VM: Assertion failed
```

**Root Cause:** The assert statement was broken in the VM - it was parsing `assert 1 == 2` as two separate statements (`assert` and `1 == 2`).

**Status:** Previously fixed (AssertStmt added to AST, parser, compiler, and VM). The test files likely need their assertions verified.

**Severity:** High - Test framework issue.

---

### 4. Interpreter Crashes: v0.11.0

**Test:** `tests/v11/test_features.ipp`

**Issue:** Interpreter crashes with empty error. VM fails with "Undefined variable 'datetime'".

- **Interpreter:** Crashes (no output)
- **VM:** `Undefined variable 'datetime'`

**Root Cause:** The `datetime` module is referenced in the test but not available in the VM's builtins.

**Severity:** Medium - Missing builtin in VM.

---

### 5. List Comprehension Returns None in VM

**Test:** `tests/v1/test_features.ipp`

**Issue:** List comprehension `[x * 2 for x in nums]` returns `None` in VM.

- **Interpreter:** `[2, 4, 6]`
- **VM:** `None`

**Root Cause:** Bug in `compile_list_comprehension` in `ipp/vm/compiler.py`.

The compiler:
1. Creates locals but doesn't properly initialize them on stack
2. Has stack management issues at loop exit
3. The result list ends up not being on stack top when returned

**Code Location:** `ipp/vm/compiler.py` - `compile_list_comprehension` method (~line 1038-1150)

**Severity:** High - Core language feature broken.

---

### 6. Dict Comprehension Returns Empty in VM

**Test:** Related to list comprehensions

**Issue:** Similar to list comprehension - dict comprehensions don't work.

**Root Cause:** `compile_dict_comprehension` is a stub that only emits empty DICT.

**Code Location:** `ipp/vm/compiler.py` - `compile_dict_comprehension` method (line 1143-1145)

```python
def compile_dict_comprehension(self, node: DictComprehension):
    self.chunk.write(OpCode.DICT, self.current_line)
    self.chunk.write(0, self.current_line)
```

**Severity:** Medium - Feature incomplete.

---

### 7. Class `__str__` Not Working in VM

**Test:** `tests/v1/test_features.ipp`

**Issue:** Class `__str__` method returns `None` in VM.

```ipp
class Point {
    func init(x, y) {
        this.x = x
        this.y = y
    }
    func __str__() {
        return "Point(" + str(this.x) + ", " + str(this.y) + ")"
    }
}
var p = Point(3, 4)
var pstr = str(p)  # Returns None in VM
```

- **Interpreter:** `Point(3, 4)`
- **VM:** `None`

**Root Cause:** The VM's `str()` builtin may not be checking for `__str__` method properly.

**Code Location:** Likely in `ipp/vm/vm.py` - `_builtin_str` method.

**Severity:** Medium - Common feature broken.

---

### 8. VM-only Tests: Some Tests Only Run in VM

Some tests like `tests/v1_0_0/test_features.ipp` fail in VM but not Interpreter.

**Root Cause:** Tests may have issues with how they use the assert statement or certain features.

**Severity:** Varies per test.

---

## Missing Builtins in VM

The following builtins referenced in tests are not available in VM:

1. `datetime` - v0.11.0 test
2. Potentially others as tests progress

**Code Location:** `ipp/vm/vm.py` - `_init_builtins` method

---

## Test Files Needing Attention

### Tests with Assertion Failures in VM:
- v0.7.0 - test_features.ipp
- v0.8.0 - test_features.ipp  
- v0.9.0 - test_features.ipp
- v1.0.0 - test_features.ipp
- v1.0.1 - test_features.ipp

### Tests with Output Mismatches:
- v0.6.0 - enum display difference
- v0.10.0 - class __str__ difference
- v1.0.0 - list comprehension returns None

### Tests That Crash in Interpreter:
- v0.11.0 - datetime module missing

---

## Compiler Issues to Fix

### Priority 1: List Comprehension (`compile_list_comprehension`)

**Location:** `ipp/vm/compiler.py`, line ~1038-1150

**Problems:**
1. Local variable initialization - values not on stack after `define_local`
2. Loop condition order - bounds check generates wrong comparison
3. Method call pattern for `.append()` - stack ordering issues
4. Return value - result not properly on stack at end

**Required Fixes:**
- After each `define_local`, add `SET_LOCAL` to properly initialize the local on stack
- Fix bounds check: should be `idx < len(src)` not `len(src) < idx`
- Fix method call: GET_PROPERTY needs proper constant index, not CONSTANT+GET_PROPERTY
- At end, clear extra stack items before returning result

### Priority 2: Dict Comprehension (`compile_dict_comprehension`)

**Location:** `ipp/vm/compiler.py`, line ~1143-1145

**Problem:** Stub implementation - just creates empty dict.

**Required Fix:** Implement full dict comprehension logic similar to list comprehension.

---

## Recommendations

1. **Fix List Comprehension First** - This is a critical bug affecting core language functionality.

2. **Add Missing Builtins** - Add `datetime` and other missing builtins to VM.

3. **Unify Enum Behavior** - Make VM and Interpreter handle enums consistently.

4. **Add Test for Assert** - Add a simple test to verify assert statement works in both modes.

5. **Consider Test Markers** - Add a way to mark tests as "expected to fail" or "known difference" so regression suite can skip them appropriately.

---

## Running the Tests

```bash
# Run all regression tests
python tests/regression.py

# Run specific version
python main.py run tests/v1/test_features.ipp

# Run in VM mode directly
python -c "
from ipp.lexer.lexer import tokenize
from ipp.parser.parser import parse
from ipp.vm.compiler import compile_ast
from ipp.vm.vm import VM

with open('tests/v1/test_features.ipp') as f:
    source = f.read()
tokens = tokenize(source)
ast = parse(tokens)
chunk = compile_ast(ast)
vm = VM()
vm.run(chunk)
"
```

---

*Last Updated: 2026-05-06*