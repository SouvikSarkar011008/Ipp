# v1.3.2 Bug Fix Instructions

## Status: Class Instantiation is Broken

After investigating, there are **two related bugs** preventing class instantiation from working correctly.

---

## Bug #1: compile_set Emits Wrong Bytecode for Property Assignment

### Problem
When compiling `self.x = x`, the compiler emits:
```
object (self) -> value (x) -> DUP -> SET_PROPERTY
```

But it should emit:
```
object (self) -> value (x) -> SET_PROPERTY -> POP
```

### Current (Broken) Code
**File:** `ipp/vm/compiler.py`, lines 856-860:
```python
def compile_set(self, node: SetExpr):
    self.compile_expr(node.object)     # Push self
    self.compile_expr(node.value)      # Push x
    self.chunk.write(OpCode.DUP, self.current_line)  # Duplicate x
    self.compile_set_property(node.name)  # SET_PROPERTY pops value, keeps obj
```

### Expected Behavior
SET_PROPERTY should pop both `value` and `obj` from the stack, but currently it only pops `value` and uses `self.stack[-1]` as `obj`.

### Fix Options

**Option A: Fix the compiler (recommended)**
```python
def compile_set(self, node: SetExpr):
    self.compile_expr(node.object)
    self.compile_expr(node.value)
    self.compile_set_property(node.name)
    self.chunk.write(OpCode.POP, self.current_line)  # Remove value, keep result
```

But wait - this would still leave the wrong value on the stack. The issue is that `self.x = x` in expression context should return `x`, not the object.

**Option B: Fix the VM (if expression semantics need to change)**
Change SET_PROPERTY to pop 2 values instead of 1:
```python
elif opcode == OpCode.SET_PROPERTY:
    idx = code[ip + 1]
    name = constants[idx]
    value = self.stack.pop()
    obj = self.stack.pop()  # Pop the object, not just peek
    if isinstance(obj, IppInstance):
        obj.set(name, value)
    # No result pushed - property assignment returns nil
```

### Test Case
```ipp
class Vec2 {
    func init(x, y) {
        self.x = x
        self.y = y
    }
}

var a = Vec2(1, 2)
print(a.x)  # Should print 1
```

---

## Bug #2: Class Instantiation Stack Layout

### Problem
When calling `Vec2(1, 2)`, the stack layout is incorrect:

**Current (wrong):**
- Stack after `_call_method`: `[instance, 1, 2]` with `stack_base=0`
- `GET_LOCAL 0` correctly gets `instance`
- `GET_LOCAL 1` correctly gets `1`
- But then extra values get pushed onto the stack

**Expected:**
- `stack_base=0`: instance
- `stack_base+1=1`: first arg (1)
- `stack_base+2=2`: second arg (2)

### Investigation Notes
See the test file `test_vec2.ipp` for a reproduction case.

When running with debug output, you can see:
```
GET_LOCAL 0: stack=[<Vec2>, 1, 2, <Vec2>], slot=0
GET_LOCAL 1: stack=[<Vec2>, 1, 2, <Vec2>, <Vec2>], slot=1  # Extra Vec2 pushed!
```

The issue is that `compile_set` is pushing an extra value that shouldn't be there.

---

## How to Fix

### Step 1: Create a test file
Create `tests/test_class_instantiation.ipp`:
```ipp
# Test basic class instantiation
class Vec2 {
    func init(x, y) {
        self.x = x
        self.y = y
    }
}

# Test 1: Basic instantiation
var a = Vec2(1, 2)
assert(a.x == 1)
assert(a.y == 2)

# Test 2: Multiple instances
var b = Vec2(3, 4)
assert(b.x == 3)
assert(b.y == 4)

print("All class instantiation tests passed!")
```

### Step 2: Run the test
```bash
python main.py tests/test_class_instantiation.ipp
```

### Step 3: Fix the compiler
Change `compile_set` in `ipp/vm/compiler.py`:

**Current (lines 856-860):**
```python
def compile_set(self, node: SetExpr):
    self.compile_expr(node.object)
    self.compile_expr(node.value)
    self.chunk.write(OpCode.DUP, self.current_line)
    self.compile_set_property(node.name)
```

**Fixed version (Option A):**
```python
def compile_set(self, node: SetExpr):
    self.compile_expr(node.object)
    self.compile_expr(node.value)
    self.compile_set_property(node.name)
    self.chunk.write(OpCode.POP, self.current_line)
```

Or alternatively, fix the VM's SET_PROPERTY handler (Option B).

### Step 4: Run the test again
```bash
python main.py tests/test_class_instantiation.ipp
```

### Step 5: Add to regression tests
Add to `tests/regression.py`:
```python
def test_class_instantiation():
    # ... existing test code ...
    pass  # Add your assertions
```

---

## Files to Modify

1. **`ipp/vm/compiler.py`** - Fix `compile_set` method (lines 856-860)
2. **`tests/test_class_instantiation.ipp`** - Create test file
3. **`tests/regression.py`** - Add regression test

## DO NOT DELETE

- Any existing test files
- Any existing functionality in the interpreter or VM
- The partial fixes already made to `arg_idx`, `__str__`, and `METHOD` opcode order

## Verification

After fixing, ensure:
1. `python main.py test_vec2.ipp` outputs `(1, 2)` not an error
2. All existing regression tests still pass
3. New class instantiation test passes
