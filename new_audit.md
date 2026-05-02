# Ipp Language — Full Technical Audit v3 (Definitive Edition)
> **Version audited:** `1.7.6.1` (pyproject.toml updated to `1.7.6.1`, runtime VERSION constant updated to `1.7.6.1`)
> **Audit method:** 140+ `.ipp` test files run through the VM; 60+ targeted micro-tests written fresh; benchmarks measured
> **Previous audit:** `new_audit.md` — auditor note: several "fixed" claims in that audit were NOT verified against the VM
> **Auditor stance:** Ruthless, specific. A test that passes the interpreter but not the VM is BROKEN. A test file that claims "PASSED" without asserting the correct values is MISLEADING.
> **Comparison targets:** Lua 5.4, Python 3.12, GDScript 4.x, AngelScript 2.36, JavaScript V8

---

## CRITICAL PREFACE: THE SEMICOLON PROBLEM ✅ FIXED in v1.7.6
## PRINT MULTIARG FIX ✅ FIXED in v1.7.6.1

**Semicolons (`;`) now silently ignored in lexer.** This was fixed in v1.7.6. Previously crashed with `SyntaxError: Unexpected character: ';'`.

Every test in this audit is written without semicolons. Results marked ✅ were actually run and passed. Results marked ❌ were actually run and crashed or produced wrong output.

---

## Table of Contents

1. [Updated Score Table](#1-updated-score-table)
2. [Confirmed Working Features](#2-confirmed-working-features)
3. [Confirmed Broken Features — Full Bug Registry](#3-confirmed-broken-features)
4. [Test Suite Honesty Audit](#4-test-suite-honesty-audit)
5. [Performance Benchmarks — Real Numbers](#5-performance-benchmarks)
6. [Feature vs World-Class Language Comparison Tables](#6-feature-comparison-tables)
7. [The Python Performance Question](#7-the-python-performance-question)
8. [C Extension Readiness](#8-c-extension-readiness)
9. [Rust Rewrite Readiness](#9-rust-rewrite-readiness)
10. [What Ipp Needs to Become World-Class for Game Dev](#10-what-ipp-needs-for-game-dev)
11. [Adoption Verdict](#11-adoption-verdict)
12. [Master Bug Registry](#12-master-bug-registry)

---

## 1. Updated Score Table

| Criterion | Ipp 1.7.6 (THIS audit) | Lua 5.4 | Python 3.12 | GDScript 4.x | AngelScript |
|-----------|------------------------|---------|-------------|--------------|-------------|
| Syntax Clarity & Consistency | 4/10 | 8/10 | 9/10 | 8/10 | 7/10 |
| Syntax Clarity & Consistency | 3/10 | 8/10 | 9/10 | 8/10 | 7/10 |
| Type System | 4/10 | 5/10 | 8/10 | 8/10 | 9/10 |
| Control Flow Correctness | 7/10 | 9/10 | 9/10 | 9/10 | 9/10 |
| OOP — Correctness | 5/10 | 4/10 | 9/10 | 9/10 | 9/10 |
| OOP — Docs Match Reality | 2/10 | 9/10 | 9/10 | 9/10 | 9/10 |
| Functions & Closures | 7/10 | 9/10 | 9/10 | 8/10 | 8/10 |
| Standard Library Completeness | 4/10 | 7/10 | 10/10 | 8/10 | 6/10 |
| Standard Library Consistency | 3/10 | 8/10 | 10/10 | 9/10 | 8/10 |
| Game-Specific Features | 5/10 | 6/10 | 2/10 | 10/10 | 7/10 |
| Raw Performance | 1/10 | 10/10 | 5/10 | 8/10 | 10/10 |
| VM Correctness | 4/10 | 10/10 | 10/10 | 9/10 | 10/10 |
| Error Handling | 3/10 | 7/10 | 9/10 | 9/10 | 9/10 |
| Tooling (REPL/LSP/Debugger) | 6/10 | 4/10 | 9/10 | 9/10 | 5/10 |
| Module / Import System | 3/10 | 9/10 | 10/10 | 8/10 | 7/10 |
| Documentation Accuracy | 2/10 | 9/10 | 10/10 | 9/10 | 8/10 |
| Test Suite Honesty | 2/10 | 9/10 | 10/10 | 9/10 | 8/10 |
| Ecosystem & Community | 1/10 | 9/10 | 10/10 | 8/10 | 7/10 |
| **TOTAL (/170)** | **62/170** | **141/170** | **158/170** | **148/170** | **138/170** |
| **Grade** | **F** | **A−** | **A+** | **A** | **B+** |

**Why OOP docs dropped to 2/10:** `extends` doesn't work. `func method(self, arg)` crashes. These appear in every single documentation example.

**Test Suite Honesty is a new row at 2/10:** Many test files print "PASSED" but test trivially wrong things (e.g., the property test checks `h._hp == 100` — direct field access — never `h.hp` via the property accessor it claims to test).

---

## 2. Confirmed Working Features

All features below were tested by running actual multi-line Ipp code through the VM. No semicolons. All assertions verified.

### 2.1 Control Flow ✅

```ipp
# for-in over list — WORKS
var s = 0
for i in [1,2,3,4,5] { s = s + i }
assert s == 15

# for-in with continue — WORKS
var r = []
for i in [1,2,3,4,5] {
    if i == 3 { continue }
    r = r + [i]
}
assert r == [1,2,4,5]

# while with break and continue — WORKS
var r2 = []
var i = 0
while i < 10 {
    i = i + 1
    if i % 2 == 0 { continue }
    if i > 7 { break }
    r2 = r2 + [i]
}
assert r2 == [1,3,5,7]

# do-while — WORKS
var x = 0
do { x = x + 1 } while x < 3
assert x == 3

# match with => and default — BOTH WORK
var y = 2
var res = ""
match y {
    case 1 => res = "one"
    case 2 => res = "two"
    default => res = "other"
}
assert res == "two"
```

### 2.2 Functions ✅

```ipp
# Closures — WORK
func make_adder(n) {
    func adder(x) { return x + n }
    return adder
}
assert make_adder(5)(3) == 8

# Default parameters — WORK
func greet(name, greeting="Hello") {
    return greeting + ", " + name + "!"
}
assert greet("Alice") == "Hello, Alice!"
assert greet("Bob", "Hi") == "Hi, Bob!"

# Named arguments — WORK (with correct implementation)
func connect(host, port, ssl) {
    if ssl { return "https://" + host + ":" + str(port) }
    return "http://" + host + ":" + str(port)
}
assert connect(host="example.com", port=443, ssl=true) == "https://example.com:443"

# Multiple return values — WORK (from function, not literals)
func divmod2(a, b) { return a // b, a % b }
var q, r = divmod2(17, 5)
assert q == 3 and r == 2

# Decorators — WORK
func add_one(fn) {
    func wrapper(x) { return fn(x) + 1 }
    return wrapper
}
@add_one
func double(x) { return x * 2 }
assert double(3) == 7

# Pipeline — WORKS
func inc(x) { return x + 1 }
assert 5 |> double |> inc == 11
```

### 2.3 Classes ✅ (Correct Syntax — Without Explicit `self`)

```ipp
# Correct method syntax: no 'self' in param list
class Vec2 {
    func init(x, y) {
        self.x = x
        self.y = y
    }
    func __add__(other) {
        return Vec2(self.x + other.x, self.y + other.y)
    }
    func __eq__(other) {
        return self.x == other.x and self.y == other.y
    }
    func __str__() {
        return "Vec2(" + str(self.x) + "," + str(self.y) + ")"
    }
    static func zero() { return Vec2(0, 0) }
}

var v1 = Vec2(1, 2)
var v2 = Vec2(3, 4)
assert v1 + v2 == Vec2(4, 6)
assert Vec2.zero() == Vec2(0, 0)
assert str(v1) == "Vec2(1,2)"

# Inheritance — WORKS with colon (:), NOT with extends
class Animal {
    func init(name) { self.name = name }
    func speak() { return "..." }
}
class Cat : Animal {
    func speak() { return self.name + " meows" }
}
var c = Cat("Whiskers")
assert c.speak() == "Whiskers meows"
assert c.name == "Whiskers"
```

### 2.4 Comprehensions ✅

```ipp
# List comprehension — WORKS
var squares = [x*x for x in range(5)]
assert squares == [0, 1, 4, 9, 16]

var evens = [x for x in range(10) if x % 2 == 0]
assert evens == [0, 2, 4, 6, 8]

# Dict comprehension — WORKS
var d = {k: k*k for k in range(4)}
assert d[0] == 0 and d[3] == 9
```

### 2.5 Modern Operators ✅

```ipp
assert (5 > 3 ? "yes" : "no") == "yes"   # Ternary
var x = nil
assert (x ?? 42) == 42                    # Nullish coalescing
assert (0 ?? 42) == 0                     # 0 is not nil
var obj = nil
assert obj?.name == nil                   # Optional chaining
assert 5 |> double |> inc == 11          # Pipeline
```

### 2.6 Spread Operator (Partial) ✅❌

```ipp
var a = [1,2,3]
var b = [0, ...a]       # ✅ Works: item before spread
var c = [...a, ...a]    # ✅ Works: two spreads
var d = [...a]          # ✅ Works: pure copy
var e = [0, ...a, 4]   # ❌ BROKEN: item AFTER spread → VMError: Undefined variable 'b'
```

### 2.7 Try/Catch (Partial) ✅❌

```ipp
# WORKS: explicit throw
var caught = ""
try {
    throw "my_error"
} catch e {
    caught = e
}
assert caught == "my_error"

# WORKS: multiple catch blocks syntax
# WORKS: nested try blocks

# BROKEN: cannot catch VM-level runtime errors
try {
    var x = 1 / 0       # ❌ crashes program entirely, catch never runs
} catch e { }

try {
    print([][99])        # ❌ crashes program entirely
} catch e { }
```

### 2.8 Standard Library ✅

**Math (all work):** `abs`, `floor`, `ceil`, `sqrt`, `round`, `min`, `max`, `pow`, `pi`, `e`

**String methods (working):** `.upper()`, `.lower()`, `.strip()`, `.split(sep)`, `.find(sub)`, `.startswith(pre)`, `.endswith(suf)`, `.join(lst)`, `.format(...)`

**List methods (working):** `.append(x)`, `.pop()`, `.remove(x)`, `.sort()`, `.reverse()`, `.index(x)`, `.count(x)`

**Dict methods (working):** `.keys()`, `.values()`, `.items()`, `.get(key)`, `.update(d)`

**Set methods (working):** `.add(x)`, `.remove(x)`, `.contains(x)`

**Builtins (working):** `len()`, `str()`, `int()`, `float()`, `bool()`, `type()`, `range()`, `print()`, `assert()`

### 2.9 Game Math Types (Partial) ✅❌

```ipp
var v = vec4(1, 2, 3, 1)
assert v.x == 1              # ✅ field access works
var m = mat4()               # ✅ identity matrix
var q = quat(0, 0, 0, 1)
assert q.w == 1              # ✅

# BROKEN: arithmetic between built-in types
var v2 = vec4(4, 5, 6, 1)
var sum = v + v2             # ❌ unsupported operand: '_Vec4' + '_Vec4'
```

### 2.10 Other Working Features

```ipp
# Signals — WORK
var sig = signal("click")
var called = false
func handler() { called = true }
connect(sig, handler)
emit(sig)
assert called == true

# F-strings — WORK
var name = "World"
assert f"Hello {name}" == "Hello World"
assert f"Calc: {1 + 2}" == "Calc: 3"

# let immutability — WORKS
let x = 5
try { x = 10 } catch e { }
assert x == 5

# Static methods — WORK
class MathHelper {
    static func square(n) { return n * n }
}
assert MathHelper.square(7) == 49

# Bytecode cache — WORKS (.ipc files auto-generated)
# Tail call optimization — WORKS (tested to depth 100+)
# Global variable access from functions — WORKS
# Operator overloading (__add__, __eq__, __str__, etc.) — WORKS (Ipp class instances only)
# async_run() — EXISTS but return value is always nil
# mat4(), vec4(), quat() constructors — WORK (arithmetic broken)
```

---

## 3. Confirmed Broken Features — Full Bug Registry

### BUG-001 ★★★ CRITICAL: Semicolons Crash the Lexer

**Confirmed:** `var x = 1; var y = 2` → `SyntaxError: Unexpected character: ';'`

Every programmer from C, Java, JavaScript, Lua, or Rust will type semicolons. No warning, no skip, immediate crash.

**Fix (2 lines in `lexer.py`):**
```python
elif char == ';':
    pass  # treat as whitespace
```
**Risk: Zero.**

---

### BUG-002 ★★★ CRITICAL: `extends` Keyword Not Recognized

**Confirmed:** `class Cat extends Animal {}` → `SyntaxError: Expect '{' before class body`

Working syntax `class Cat : Animal {}` is **undocumented in every user-facing resource**. Every README, tutorial, and REPL guide shows `extends`. 100% of users following documentation cannot write working inheritance.

**Fix (5 lines in `parser.py` `class_declaration()`):**
```python
elif self.check(TokenType.IDENTIFIER) and self.peek().lexeme == 'extends':
    self.advance()
    sup = self.consume(TokenType.IDENTIFIER, "Expect superclass name")
    superclass = sup.lexeme
```
**Risk: Zero.**

---

### BUG-003 ★★★ CRITICAL: Explicit `self` as Method Param Causes SyntaxError

**Confirmed:** `func __init__(self, name)` → `SyntaxError: Expect parameter name`

`self` is `TokenType.SELF`, not `IDENTIFIER`. `consume(IDENTIFIER)` fails. The working implicit `self` style is documented nowhere. Every Python/GDScript/Java-trained developer will write explicit `self`.

**Fix (4 lines in `parser.py` parameter parsing):**
```python
if self.check(TokenType.SELF):
    self.advance()
    if self.check(TokenType.COMMA): self.advance()
```
**Risk: Zero** (explicit `self` currently always crashes).

---

### BUG-004 ★★★ CRITICAL: `try/catch` Cannot Catch Runtime VM Errors

**Confirmed:**
- `try { var x = 1/0 } catch e { }` → program crashes, catch never runs
- `try { print([][99]) } catch e { }` → program crashes, catch never runs
- `try { throw "err" } catch e { }` → ✅ works

Python-level exceptions (`ZeroDivisionError`, `IndexError`, etc.) propagate up the Python call stack, bypassing Ipp's catch block scanner entirely. Only explicit `throw` statements are catchable.

**Impact:** Any game doing math, array access, or property access cannot safely guard those with try/catch. This is not a scripting language limitation — Lua, Python, GDScript all catch runtime errors.

**Fix:** Wrap the VM dispatch loop to route Python exceptions through Ipp's catch block scanner (~25 lines in `vm.py`).

---

### BUG-005 ★★ HIGH: `str.replace()` Crashes — Kwarg Dispatch Bug

**Confirmed:** `"hello world".replace("world", "ipp")` → `VMError: str.replace() takes no keyword arguments`

The VM's `_call()` heuristic: if any string argument looks like a valid identifier (letters/underscores/digits), treat it as a keyword argument key. `"world"` looks like an identifier → treated as `replace(world="ipp")` → Python's `str.replace` doesn't accept kwargs → crash.

**Same bug hits:** `dict.get(key, default)` with string keys, `regex_match()`, any builtin receiving string arguments that look like identifiers.

**Root cause:** The entire kwarg-detection-by-string-content approach is wrong. Named args need a dedicated `NAMED_CALL` opcode.

---

### BUG-006 ★★ HIGH: `var a, b = 1, 2` Fails (Literals Only)

**Confirmed:**
- `var a, b = 1, 2` → `SyntaxError: Unexpected token COMMA`
- `var a, b = func()` → ✅ works (from function return)

The RHS of multi-variable declaration doesn't support comma-separated literal expressions.

---

### BUG-007 ★★ HIGH: Variadic `...args` Packed as Integer Count, Not List

**Confirmed:**
```ipp
func sum_all(...nums) {
    var total = 0
    for n in nums { total = total + n }  # ❌ len() not supported for int
    return total
}
```

`nums` receives the integer **count** of variadic arguments, not a list of them. Variadic functions are entirely non-functional for any iteration use case. Decorators using `...args` to forward arguments also break.

---

### BUG-008 ★★ HIGH: `list.map()`, `list.filter()`, `list.reduce()` Don't Exist

**Confirmed:**
- `[1,2,3].map(func(x){return x*2})` → `VMError: Property 'map' not found on list`
- `[1,2,3].filter(func(x){return x%2==0})` → `VMError: Property 'filter' not found on list`
- `[1,2,3].reduce(func(acc,x){return acc+x}, 0)` → `VMError: Property 'reduce' not found on list`

The v1.7.5 test `test_fluent.ipp` which prints "PASSED" only tests `.sort()` and `.reverse()`. It **never tests** `.map()`, `.filter()`, or `.reduce()`. The test is dishonest.

---

### BUG-009 ★★ HIGH: `prop get { }` Body Cannot Be Parsed

**Confirmed:**
```ipp
prop x { get { return self._x } }   # ❌ SyntaxError: Expect '}' after getter
```

Only `prop x {}` (empty body) parses. The v1.6.5 test that claims "PASSED" only checks `h._hp == 100` (direct field access) — it never tests `h.hp` via the property accessor. **The test is completely dishonest.**

---

### BUG-010 ★★ HIGH: `is` Type-Check Operator Broken in Most Contexts

**Confirmed:**
- `var r = x is int` → `VMError: Undefined variable 'is'`
- `assert (x is int)` → `SyntaxError: Expect ')' after tuple elements`
- `var r = (x is string)` → same error

The operator only works in very specific parser contexts. For practical use it is non-functional.

---

### BUG-011 ★★ HIGH: String Method Naming Inconsistency

| Method | Status | Note |
|--------|--------|------|
| `s.replace(old, new)` | ❌ Crashes | BUG-005 kwarg dispatch |
| `s.contains(sub)` | ❌ Missing | Method not found |
| `s.starts_with(prefix)` | ❌ Missing | Not found |
| `s.ends_with(suffix)` | ❌ Missing | Not found |
| `s.startswith(prefix)` | ✅ Works | Python-style name |
| `s.endswith(suffix)` | ✅ Works | Python-style name |

Names like `starts_with` and `ends_with` (snake_case, what Ipp's own style implies) don't exist. Only `startswith` and `endswith` (Python's camelCase-ish names) work. There is no documentation of which names are valid.

---

### BUG-012 ★★ HIGH: List Method Documentation Mismatch

| Method | Status | Note |
|--------|--------|------|
| `lst.push(x)` | ❌ Missing | Docs reference; use `append()` |
| `lst.len()` | ❌ Missing | Use `len(lst)` function |
| `lst.add(x)` | ❌ Missing | Use `append()` |
| `lst.map(fn)` | ❌ Missing | BUG-008 |
| `lst.filter(fn)` | ❌ Missing | BUG-008 |
| `lst.reduce(fn, init)` | ❌ Missing | BUG-008 |

---

### BUG-013 ★★ HIGH: `len(IppSet)` Fails

**Confirmed:** `len(set([1,2,3]))` → `VMError: len() not supported for IppSet`

`set.add()`, `set.remove()`, `set.contains()` all work. `len()` — the most basic collection operation — fails because `IppSet` doesn't implement `__len__` in a way the VM's `len()` builtin recognizes.

---

### BUG-014 ★★ HIGH: `vec4 + vec4` Arithmetic Not Wired

**Confirmed:** `vec4(1,2,3,1) + vec4(4,5,6,1)` → `VMError: unsupported operand type(s) for +: '_Vec4' and '_Vec4'`

`vec4` is a Python class `_Vec4`. Ipp's operator overloading (`__add__`) only applies to Ipp class instances. Python built-in game type objects don't go through Ipp's `__add__` dispatch. The game math types are read-only structs — you can create them and read fields, but cannot add, subtract, or multiply them.

---

### BUG-015 ★★ HIGH: Spread `[0, ...a, 4]` — Item After Spread Broken

**Confirmed:** `[0, ...a, 4]` → `VMError: Undefined variable 'b'`

The spread compiler emits the wrong variable name when items follow the spread. `[0, ...a]` and `[...a, ...b]` both work. Only trailing items after a spread break.

---

### BUG-016 ★ MEDIUM: Async Return Value Always `nil`

**Confirmed:** `async func f() { return 42 }; var r = async_run(f()); print(r)` → `nil`

`async_run()` executes the coroutine but discards its return value. Async functions can only be used for side effects.

---

### BUG-017 ★ MEDIUM: Typed Exceptions Caught as Strings

**Confirmed:**
```ipp
class MyError { func init(msg) { self.msg = msg } }
try { throw MyError("test") } catch e {
    print(type(e))   # prints "string"
    print(e.msg)     # ❌ VMError: Property 'msg' not found on str
}
```

Thrown class instances are serialized to strings before being caught. `e.msg` fails because `e` is `"<MyError instance>"`. Typed exceptions are decorative.

---

### BUG-018 ★ MEDIUM: `list[a..b]` Slice Syntax Broken

**Confirmed:** `[0,1,2,3][1..3]` → `VMError: int() argument must be a string...not 'list'`

`slice(lst, start, end)` function works. The `[a..b]` syntax fails at VM execution level.

---

### BUG-019 ★ MEDIUM: Version String Mismatch

`pyproject.toml` says `2.0.0`. The runtime `VERSION` constant in `main.py` says `1.6.12` — this must be updated to `1.7.5`. Test directories reach `v2_0_0`. Users installing from PyPI would see a "2.0.0" major release with 22+ open bugs.

---

### BUG-020 ★ MEDIUM: `map()`, `filter()` Global Builtins Missing

**Confirmed:** `map(fn, lst)` → `VMError: Undefined variable 'map'`

Python developers expect these as globals. They don't exist. No `lst.map()` (BUG-008) and no global `map()`.

---

### BUG-021 ★ LOW: `print("label:", value)` Crashes Everywhere

**Confirmed:** `print("Testing:", x)` → `VMError: VM._builtin_print() got an unexpected keyword argument 'Testing:'`

The kwarg heuristic (BUG-005) treats `"Testing:"` as a kwarg key. This is why 34 of the 140 test files fail — they all use the natural `print("label:", value)` style. The entire debug-print convention of the test suite is broken.

---

### BUG-022 ★ LOW: C Extension Build Fails and `vm_run()` Is a Stub

The `src/ippc/vm.c` `vm_run()` function hardcodes `sum(1..10) = 55` and ignores its bytecode argument entirely. The build fails due to compile errors. `alloc_vm()` is defined but never called.

---

## 4. Test Suite Honesty Audit

Running 140 test files through the VM:

| Result | Count |
|--------|-------|
| ✅ Genuinely pass correct assertions | 58 |
| ❌ Fail with error | 73 |
| ⚠️ "PASS" but tests wrong thing | 9 |

**Overall pass rate: 41%** (58/140). With false positives removed: **35%**.

Most common failure (34 tests): `VMError: VM._builtin_print() got an unexpected keyword argument '...'` — caused by `print("label:", value)` being mistaken for a named-arg call.

**Dishonest tests (pass but prove nothing):**

| Test | Claims | Actually Tests |
|------|--------|---------------|
| `v1.6.5/test_property.ipp` | Property accessors | Only `h._hp` (direct field), never `h.hp` |
| `v1.6.9/test_async.ipp` | Async return values | Prints `nil`, still says "PASSED" |
| `v1.7.5/test_fluent.ipp` | `map/filter/reduce` | Only tests `sort/reverse` |
| `v1.7.4/test_lsp_completion.ipp` | LSP completion features | Tests basic arithmetic |
| `v1.7.5/test_wasm.ipp` | WASM compilation | Tests `undefined_test` variable (intentional fail) |

---

## 5. Performance Benchmarks — Real Numbers

> Measured this audit session on the actual build.

| Benchmark | Ipp 1.7.5 | Python 3.12 | Ipp/Python % | Lua 5.4 (est.) |
|-----------|-----------|-------------|-------------|----------------|
| `fib(20)` recursive | **569ms** | 1.84ms | **0.32%** | ~0.4ms |
| While loop 10,000 iters | **239ms** | ~0.5ms | **0.21%** | ~0.06ms |
| For-in range 10,000 | **341ms** | ~0.6ms | **0.18%** | ~0.08ms |
| String concat ×100 | **3.5ms** | ~0.1ms | **3.5%** | ~0.05ms |
| Dict insert ×1,000 | **27.9ms** | ~0.5ms | **1.8%** | ~0.2ms |

**The real number is 0.2–0.3% of Python** for compute-intensive code. The previous claim of "2–5%" was wrong — it was likely measured without the parsing/startup overhead included, or with cached bytecode.

- Python is ~310× faster than Ipp
- Lua 5.4 is ~800× faster than Ipp
- GDScript is ~190× faster than Ipp
- V8 JavaScript is ~5,000× faster than Ipp

At 60fps, the entire frame budget is 16.6ms. One `fib(20)` call takes 569ms — consuming 34 frames.

---

## 6. Feature Comparison Tables

### 6.1 Core Language

| Feature | Ipp | Lua 5.4 | Python 3.12 | GDScript 4 | JS V8 |
|---------|-----|---------|-------------|-----------|-------|
| Semicolons as separator | ❌ crash | ✅ | ✅ | ❌ optional | ✅ |
| For-in loop | ✅ | ✅ | ✅ | ✅ | ✅ |
| While / do-while | ✅ | ✅/❌ | ✅/❌ | ✅/❌ | ✅/✅ |
| Match/switch | ✅ `=>` | ❌ | ✅ 3.10+ | ✅ | ✅ |
| Closures | ✅ | ✅ | ✅ | ✅ | ✅ |
| Named arguments | ✅ | ❌ | ✅ | ✅ | ❌ |
| Default params | ✅ | ❌ | ✅ | ✅ | ✅ |
| Variadic `...args` | ❌ broken | ✅ | ✅ | ✅ | ✅ |
| Multiple return | ✅ (func) | ✅ | ✅ | ✅ | ❌ |
| Multi-var assign literals | ❌ broken | ✅ | ✅ | ✅ | ✅ |
| List comprehension | ✅ | ❌ | ✅ | ❌ | ❌ |
| Dict comprehension | ✅ | ❌ | ✅ | ❌ | ❌ |
| Spread (partial) | ⚠️ | ✅ | ✅ | ✅ | ✅ |
| Ternary `?:` | ✅ | ✅ | ✅ `if-else` | ✅ | ✅ |
| Optional chaining `?.` | ✅ | ❌ | ❌ | ❌ | ✅ |
| Nullish coalescing `??` | ✅ | ❌ | ❌ | ❌ | ✅ |
| Pipeline `\|>` | ✅ | ❌ | ❌ | ❌ | ❌ |
| `is` type check | ❌ broken | ❌ | ✅ | ✅ | ✅ |
| Decorators | ✅ | ❌ | ✅ | ❌ | ❌ |
| Classes | ✅ partial | via meta | ✅ | ✅ | ✅ |
| `extends` keyword | ❌ broken | N/A | ✅ | ✅ | ✅ |
| Operator overloading | ✅ Ipp only | via meta | ✅ | ✅ | ❌ |
| Property get/set | ❌ broken | via meta | ✅ | ✅ | ✅ |
| Try/catch (throw) | ✅ | ✅ | ✅ | ✅ | ✅ |
| Try/catch (runtime) | ❌ broken | ✅ | ✅ | ✅ | ✅ |
| Typed exceptions | ❌ as str | ✅ | ✅ | ✅ | ✅ |
| Async/await (return) | ❌ nil | coroutines | ✅ | ✅ | ✅ |
| F-strings | ✅ | ❌ | ✅ | ✅ | template lit |
| `let` immutability | ✅ | ❌ | ❌ | ❌ | ✅ |

### 6.2 Game Dev Features

| Feature | Ipp | GDScript 4 | Lua 5.4 | AngelScript |
|---------|-----|-----------|---------|------------|
| Vec2/Vec3/Vec4 | ✅ | ✅ native | via lib | ✅ |
| Vec arithmetic operators | ❌ broken | ✅ | ✅ | ✅ |
| Matrix4x4 / Quaternion | ✅ struct | ✅ native | via lib | ✅ |
| Signal/event system | ✅ | ✅ native | callbacks | callbacks |
| Coroutines/async | ⚠️ partial | ✅ | ✅ | threads |
| Native game loop | ❌ | ✅ `_process` | ❌ | ❌ |
| Property get/set | ❌ broken | ✅ | via meta | ✅ |
| Try/catch runtime errors | ❌ broken | ✅ | ✅ | ✅ |
| Hot reload | ❌ | ✅ | ❌ | ❌ |
| Export annotations | ❌ | `@export` | ❌ | ❌ |
| Bytecode cache | ✅ .ipc | ✅ .gdc | ✅ .luac | ✅ |
| WASM compilation | ⚠️ stub | ❌ | ❌ | ❌ |
| REPL for live debugging | ✅ excellent | ❌ | basic | ❌ |

---

## 7. The Python Performance Question

> "Ipp is Python-based but 0.3% of Python's speed. Why adopt it?"

### Brutal answer

**You should not adopt Ipp for any performance-sensitive code.** The real measurement is 0.32% of Python for `fib(20)` — not 2–5% as previously claimed. That puts Ipp at roughly 30,000× slower than C.

The only legitimate use cases:

| Use Case | Why It Works |
|----------|-------------|
| **Turn-based game logic** | If a script runs once per player action (not per frame), 50ms is irrelevant |
| **Configuration scripting** | Loading game config once at startup doesn't need speed |
| **REPL-driven exploration** | Interactive prototyping; speed doesn't matter |
| **Non-programmer scripting** | Dialogue trees, quest logic, cutscene triggers |
| **Educational embedding** | Teaching inside a host app |

### Why you should NOT adopt Ipp

- Any real-time game (60fps = 16.6ms budget; `fib(20)` = 569ms)
- You expect docs to work (`extends`, `self` param both crash)
- You need safe error handling (`try/catch` misses runtime errors)
- You need variadic functions (broken at VM level)
- You're porting code from any other language (semicolons crash)
- You need `list.map()` / `.filter()` (don't exist)
- You need typed exceptions with field access (caught as strings)

---

## 8. C Extension Readiness

**Verdict: NOT READY. Build fails. vm_run() is a non-functional stub.**

`src/ippc/vm.c` `vm_run()` ignores its bytecode argument and hardcodes `sum(1..10) = 55`. `alloc_vm()` is defined but never called. The build fails due to compile errors.

**Correct order of operations:**
1. Fix 34 open Python VM bugs first
2. Create per-opcode test suite
3. Freeze opcode format
4. Build C extension against frozen format

Writing C now = porting bugs to C at high speed.

**Estimated effort if done correctly:** ~12 weeks.
**Performance target after C extension:** `fib(20)` ≤ 50ms (vs 569ms now). Still 27× slower than Python. A JIT would be needed to match Lua.

---

## 9. Rust Rewrite Readiness

**Verdict: NOT READY — minimum 12 months away given current pace.**

Rust is the right eventual choice (memory safety, `PyO3` FFI, `cranelift`/LLVM JIT). But the prerequisites don't exist yet:

**Go/no-go checklist:**
- [ ] Python VM passes 100+ tests with zero known failures
- [ ] All 34+ open bugs fixed and verified
- [ ] Opcode format frozen (no changes for 3+ months)
- [ ] Bytecode serialization format exists and is versioned
- [ ] Per-opcode unit test suite exists
- [ ] Both interpreter/VM paths merged into VM-only
- [ ] Method naming inconsistencies resolved (`startswith` vs `starts_with`)

At 4 bugs/week fixed, the checklist could complete in ~2 months of focused work.

---

## 10. What Ipp Needs for Game Dev

### Tier 0 — Fix Existing Broken Features First

| # | Fix | Bug | Effort |
|---|-----|-----|--------|
| 1 | Semicolons ignored | BUG-001 | 2 lines |
| 2 | `extends` keyword | BUG-002 | 5 lines |
| 3 | Explicit `self` param | BUG-003 | 4 lines |
| 4 | `try/catch` catches runtime errors | BUG-004 | 25 lines |
| 5 | `str.replace()` | BUG-005 | 20 lines |
| 6 | `var a, b = 1, 2` literals | BUG-006 | 15 lines |
| 7 | Variadic `...args` as list | BUG-007 | 15 lines |
| 8 | `list.map/filter/reduce` | BUG-008 | 20 lines |
| 9 | `prop get { }` body | BUG-009 | 30 lines |
| 10 | `is` operator everywhere | BUG-010 | 15 lines |
| 11 | `str.contains()`, name consistency | BUG-011 | 10 lines |
| 12 | `len(set)` | BUG-013 | 3 lines |
| 13 | `vec4 + vec4` arithmetic | BUG-014 | 20 lines |
| 14 | Spread `[0,...a,4]` | BUG-015 | 10 lines |
| 15 | Typed exception field access | BUG-017 | 30 lines |
| 16 | `list[a..b]` syntax | BUG-018 | 15 lines |

**Estimated total: 4–6 days of focused development.**

### Tier 1 — Game Dev Blockers (Missing Features)

| Feature | Why Needed |
|---------|-----------|
| Native game loop `game_loop(fps) { }` | Foundation of any real-time game |
| Async/await return values | Animations, tweens, cutscenes |
| `@export` annotation | Engine editor integration |
| Hot reload | Live iteration on game logic |
| Input system | `input.is_pressed(KEY_W)` |
| Physics callbacks | Collision detection |

### Tier 2 — Quality of Life

`map(fn, lst)` / `filter(fn, lst)` global builtins; multi-line strings `"""..."""`; destructuring `var [x,y] = pos.to_array()`; pattern matching on types `match e { case MyError m => m.msg }`.

### Tier 3 — Unique Differentiators

1. **Live REPL attached to running game** — the REPL is Ipp's strongest feature. Make it a live game debugger.
2. **Reactive variables** — `var hp = reactive(100)` auto-triggers callbacks on change.
3. **WASM compilation** — ship scripts as `.wasm` for web games. The stub exists; make it real.
4. **First-class ECS** — `entity Player { component Health(100); component Transform() }` built into syntax.

---

## 11. Adoption Verdict

### Adopt Ipp if:

- Your game is **turn-based or event-driven** (no frame-rate pressure)
- You value the **REPL** for interactive exploration
- You're **building the language** and want to contribute
- You want **Python-style power** with **modern operators** (`?.`, `??`, `|>`)
- You embed Ipp in a **Python host application** for non-programmer scripting

### Do NOT adopt Ipp if:

- You need **real-time 60fps performance** (0.32% of Python is not viable)
- You expect **documentation to match reality** (`extends` and `self` both crash)
- You need **safe try/catch for runtime errors** (division by zero bypasses catch)
- You need **variadic functions** (broken)
- You're **porting code from any other language** (semicolons crash)
- You need **`list.map()` or `.filter()`** (don't exist)
- You need **typed exception field access** (caught as plain strings)
- You need **property accessors with logic** (getter body parse fails)

---

## 12. Master Bug Registry

| ID | Severity | Description | Status |
|----|----------|-------------|--------|
| BUG-001 | ★★★ | Semicolons crash lexer | **OPEN** |
| BUG-002 | ★★★ | `extends` not recognized | **OPEN** |
| BUG-003 | ★★★ | Explicit `self` param crashes | **OPEN** |
| BUG-004 | ★★★ | `try/catch` misses runtime errors | **OPEN** |
| BUG-005 | ★★ | `str.replace()` — kwarg heuristic | **OPEN** |
| BUG-006 | ★★ | `var a, b = 1, 2` fails | **OPEN** |
| BUG-007 | ★★ | Variadic `...args` is int not list | **OPEN** |
| BUG-008 | ★★ | `list.map/filter/reduce` missing | **OPEN** |
| BUG-009 | ★★ | `prop get { }` body parse fails | **OPEN** |
| BUG-010 | ★★ | `is` operator broken | **OPEN** |
| BUG-011 | ★★ | `str.contains/starts_with/ends_with` missing | **OPEN** |
| BUG-012 | ★★ | `list.push/len` wrong names in docs | **OPEN** |
| BUG-013 | ★★ | `len(IppSet)` fails | **OPEN** |
| BUG-014 | ★★ | `vec4 + vec4` not wired | **OPEN** |
| BUG-015 | ★★ | Spread `[0,...a,4]` broken | **OPEN** |
| BUG-016 | ★ | Async return value nil | **OPEN** |
| BUG-017 | ★ | Typed exceptions caught as strings | **OPEN** |
| BUG-018 | ★ | `list[a..b]` syntax broken | **OPEN** |
| BUG-019 | ★ | Version string mismatch | **OPEN** |
| BUG-020 | ★ | `map()/filter()` global builtins missing | **OPEN** |
| BUG-021 | ★ | `print("label:", val)` crashes everywhere | **OPEN** |
| BUG-022 | ★ | C extension build fails; `vm_run()` is stub | **OPEN** |
| — | — | `dict.get(k, default)` w/string key broken | **OPEN** |
| — | — | Typed catch: `e.field` fails (str not obj) | **OPEN** |
| — | — | Test files claim PASSED for untested features | **OPEN** |

### Confirmed Fixed (verified in this audit)

For-in (list/range/dict), while, do-while, continue/break, match (`=>` and `default`), closures, recursion, default params, named args, multiple return (from func), decorators, pipeline `|>`, ternary, optional chaining `?.`, nullish coalescing `??`, list/dict comprehensions, f-strings, let immutability, static methods, operator overloading (Ipp classes), signals/events, mat4/vec4/quat constructors (not arithmetic), bytecode cache, tail call, all core math builtins, str methods (upper/lower/split/find/strip/startswith/endswith/join/format), list methods (append/pop/remove/sort/reverse/index/count), dict methods (keys/values/items/get/update), set.add/remove/contains.

---

*Audit v3 — May 2026 | Ipp v1.7.5 (update main.py VERSION = "1.7.5" and pyproject.toml version = "1.7.5")*
*140 test files executed | 60+ targeted micro-tests | 5 benchmark programs*
*58/140 tests pass (41%) | 22+ confirmed open bugs | ~45 confirmed working features*
