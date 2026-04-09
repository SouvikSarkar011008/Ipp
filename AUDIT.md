# Ipp Language Audit

## Executive Summary
This document provides a comprehensive audit of Ipp v0.7.0 (Comprehensions Update), comparing it against world-class game scripting languages including Lua, Python, JavaScript, GDScript, and AngelScript. The audit covers language features, standard library, performance, tooling, and ecosystem.

## Overall Scores (0-10)

| Aspect | Ipp v0.7.0 | Lua | Python | JavaScript | GDScript |
|--------|------------|-----|--------|------------|----------|
| Syntax | 7.0 | 7.0 | 8.0 | 7.5 | 8.5 |
| Types | 5.0 | 4.5 | 8.0 | 7.0 | 7.5 |
| Control Flow | 8.0 | 8.0 | 8.5 | 8.0 | 8.5 |
| Functions | 6.5 | 8.0 | 9.0 | 8.5 | 8.0 |
| OOP | 5.5 | 5.0 | 8.5 | 8.0 | 9.0 |
| Standard Library | 5.0 | 6.0 | 9.5 | 8.5 | 7.0 |
| Game Features | 5.0 | 7.0 | 5.0 | 6.0 | 9.5 |
| Performance | 3.0 | 9.0 | 6.0 | 8.0 | 7.0 |
| Tooling | 2.0 | 6.0 | 9.0 | 8.5 | 8.0 |
| Ecosystem | 1.0 | 9.0 | 10.0 | 9.5 | 8.5 |
| **TOTAL** | **48.0** | **70.0** | **81.5** | **77.5** | **79.5** |

## Detailed Feature Analysis

### 1. Syntax & Language Design (Score: 7/10)

#### What's Implemented in Ipp (v0.7.0):
- Python-like syntax with braces `{}` for blocks
- Variable declaration: `var`, `let` (immutable)
- Comments with `#`
- Multi-line support (v0.4.0)
- ✅ Ternary operator `? :` (v0.5.0)
- ✅ Match/switch statement (v0.5.0)
- ✅ List comprehensions (v0.7.0)
- ✅ Dict comprehensions (v0.7.0)
- ✅ Try/catch/finally (v0.5.0)
- ✅ Bitwise operators & | ^ << >> ~ (v0.5.0)
- ✅ Floor division // (v0.5.0)
- ✅ Power operator ** (v0.6.1)

#### What's Missing:
- ❌ No destructuring assignment
- ❌ No walrus operator (`:=`)
- ❌ No decorators
- ❌ No docstrings
- ❌ No triple-quoted strings
- ❌ No raw strings
- ❌ No multi-line strings (heredoc)
- ❌ No f-strings or string interpolation
- ❌ No pattern matching beyond switch

#### Advantages Over Competitors:
- Simple, readable syntax inspired by Python
- Familiar to Python developers
- `var` and `let` distinction (immutability)
- Multi-line function parameters (v0.4.0)
- List/dict comprehensions like Python (v0.7.0)
- Game-focused built-ins (Vector2, Vector3, Color, Rect)

**Verdict: NOT PRODUCTION READY** - Syntax is too limited for modern game development workflows.

---

### 2. Type System (Score: 5/10)

#### What's Implemented in Ipp (v0.7.0):
- ✅ Numbers - 64-bit float AND integer (separate types!)
- ✅ Strings
- ✅ Booleans
- ✅ Nil
- ✅ Lists (IppList wrapper)
- ✅ Dicts (IppDict wrapper)
- ✅ Classes (user-defined)
- ✅ Functions (first-class)
- ✅ Vector2, Vector3, Color, Rect
- ✅ Type annotations (v0.6.0) - `var x: int = 5`
- ✅ Enums (v0.6.0) - `enum Direction { UP, DOWN }`
- ✅ Bitwise operators now work with integers (v0.5.0)
- ✅ Power operator ** (v0.6.1)

#### Critical Issues (Remaining):
- ❌ No generics
- ❌ No union types
- ❌ No structural typing
- ❌ No type guards
- ❌ No interfaces/protocols
- ❌ No tuples
- ❌ No runtime type checking

**Verdict: CRITICAL GAP** - Need at least integer types and optional type hints for production game development.

---

### 3. Operators (Score: 5/10)

#### What's Implemented:
- ✅ `+`, `-`, `*`, `/`, `%`, `^` (power)
- ✅ `==`, `!=`, `<`, `>`, `<=`, `>=`
- ✅ `and`, `or`, `not`
- ✅ `..` (range operator)
- ✅ Compound assignment `+=`, `-=` (partial)
- ✅ Unary `-`, `not`

#### Missing Operators:
- ❌ **No bitwise operators** - `&`, `|`, `^`, `<<`, `>>`, `~`
- ❌ **No floor division** - `//`
- ❌ **No integer division**
- ❌ **No augmented assignment** for all operators (`+=`, `-=` incomplete)
- ❌ **No ternary/conditional** - `a if condition else b`
- ❌ **No nullish coalescing** - `??`
- ❌ **No optional chaining** - `obj?.prop`
- ❌ **No spread operator** - `...arr`
- ❌ **No pipeline operator** - `|>` (modern but nice to have)

**Verdict: MAJOR GAP** - No ternary operator is a serious usability issue for game logic.

---

### 4. Control Flow (Score: 7/10)

#### What's Implemented:
- ✅ `if/elif/else`
- ✅ `for` loops (range-based, `for i in 0..10`)
- ✅ `while` loops
- ✅ `break` and `continue`
- ✅ Multi-line condition/parameter support (v0.4.0)

#### Missing:
- ❌ **No switch/match statement** - MUST ADD
- ❌ **No do-while loops** (repeat-until in Lua)
- ❌ **No labeled breaks** - can't break outer loop
- ❌ **No try-catch-finally** - no exception handling
- ❌ **No raise/throw** - no custom exceptions
- ❌ **No with statement** - context managers

**Verdict: CRITICAL** - No exception handling makes Ipp unsuitable for production games.

---

### 5. Functions (Score: 6.5/10)

#### What's Implemented:
- ✅ Function declaration with `func`
- ✅ Parameters with default values
- ✅ Return values
- ✅ First-class functions (can be passed around)
- ✅ Closures (work with for loops - closure captures)
- ✅ Lambda expressions (anonymous functions)
- ✅ Variadic functions (using lists)

#### Missing:
- ❌ **No named arguments** - `func(a=1, b=2)` syntax
- ❌ **No keyword-only arguments**
- ❌ **No *args, **kwargs equivalent**
- ❌ **No function overloading**
- ❌ **No default parameter validation** - can use wrong types
- ❌ **No generator functions** - `yield` keyword
- ❌ **No async/await**
- ❌ **No function annotations** - `@param type` docs
- ❌ **No decorators**
- ❌ **No partial application**
- ❌ **No function composition**

**Verdict: MEDIUM GAP** - Functional features are adequate but missing generators and async limit game dev use cases.

---

### 6. Object-Oriented Programming (Score: 5.5/10)

#### What's Implemented:
- ✅ Class declaration with `class`
- ✅ Methods with `self`
- ✅ `init()` constructor
- ✅ Inheritance (single)
- ✅ Property access via dot notation
- ✅ Instance attributes

#### Missing:
- ❌ **No inheritance chain visibility** - can't call parent methods easily
- ❌ **No private/public distinction** - all attributes public
- ❌ **No static methods/properties**
- ❌ **No class variables** - only instance variables
- ❌ **No abstract classes**
- ❌ **No interfaces/protocols**
- ❌ **No method overloading**
- ❌ **No property decorators** - `@property`
- ❌ **No metaclasses**
- ❌ **No operator overloading** - except Vector2/3, Color, Rect have it
- ❌ **No `super()` shorthand** - must use parent class name
- ❌ **No __str__, __repr__ support** - need custom methods

**Verdict: MEDIUM GAP** - Basic OOP works but lacks encapsulation critical for large game projects.

---

### 7. Standard Library (Score: 5/10)

#### Current Features in Ipp (86 functions):
- **Math**: abs, min, max, sum, round, floor, ceil, sqrt, pow, sin, cos, tan, log, log10, degrees, radians, asin, acos, atan, atan2, pi, e
- **Random**: random, randint, randfloat, choice, shuffle
- **Type Conversion**: to_number, to_string, to_int, to_float, to_bool, str, int, float, bool
- **String**: split, join, upper, lower, strip, replace, starts_with, ends_with, find, split_lines, count, contains, replace_all, substring, index_of, char_at, ascii, from_ascii
- **Data**: json_parse, json_stringify, regex_match, regex_search, regex_replace
- **File I/O**: read_file, write_file, append_file, file_exists, delete_file, list_dir, mkdir
- **Time**: time, sleep, clock
- **Game**: vec2, vec3, color, rect
- **Utility**: len, type, keys, values, items, has_key, input, exit, assert, range

#### Critical Missing:
- ❌ **No datetime/time utilities** - can't format timestamps
- ❌ **No hash functions** - md5, sha256
- ❌ **No base64 encoding/decoding**
- ❌ **No URL encoding/decoding**
- ❌ **No CSV parsing**
- ❌ **No XML/HTML parsing**
- ❌ **No threading/multi-threading**
- ❌ **No networking** - socket, http
- ❌ **No serialization** - only JSON
- ❌ **No compression** - gzip, zip
- ❌ **No cryptography**
- ❌ **No OS utilities** - environment variables, system info
- ❌ **No path utilities** - dirname, basename, join
- ❌ **No math constants** - except pi, e
- ❌ **No complex numbers**
- ❌ **No decimal precision**

#### Missing Game-Specific:
- ❌ No audio handling
- ❌ No image handling
- ❌ No input handling (keyboard/mouse)
- ❌ No game loop utilities
- ❌ No entity/component base classes
- ❌ No physics vector operations beyond basics
- ❌ No matrix operations
- ❌ No easing functions
- ❌ No tweening
- ❌ No collision helpers

**Verdict: INCOMPLETE** - Basic needs met but missing game dev essentials.

---

### 8. Performance (Score: 6/10)

#### Current Implementation (v1.1.1):
- ✅ Bytecode VM with 90+ opcodes (v1.0.0)
- ✅ Stack-based VM with fast opcode dispatch
- ✅ Inline caching for global lookups
- ✅ String interning
- ✅ Constant pooling
- ✅ Method dispatch caching
- ✅ Built-in profiler (v1.1.0)
- ⚠️ No JIT compilation (planned for future)

#### Performance Benchmarks (Expected):

| Operation | Ipp (VM) | Lua | Python | GDScript |
|-----------|-----------|-----|--------|----------|
| 1M loop iterations | ~0.1s | ~0.01s | ~0.1s | ~0.05s |
| 10K function calls | ~0.01s | ~0.001s | ~0.01s | ~0.005s |
| String concatenation | Medium | Fast | Medium | Medium |
| Table/List ops | Medium | Fast | Medium | Fast |

#### Implemented:
- ✅ Bytecode compilation
- ✅ VM execution
- ✅ Inline caching
- ✅ Profiler
- ❌ JIT compilation (future)
- ❌ AOT compilation (future)
- ❌ Type inference (future)
- ❌ Memory pooling (future)

**Verdict: ACCEPTABLE FOR GAMES** - Bytecode VM provides 10-50x speedup over interpreter.

---

### 9. Tooling & Developer Experience (Score: 4/10)

#### Current (v1.1.1):
- ✅ REPL with history (v0.13.0)
- ✅ Arrow key navigation
- ✅ Tab autocomplete
- ✅ File execution: `python main.py file.ipp`
- ✅ `ipp run <file>`, `ipp check <file>`, `ipp lint <file>`
- ✅ Professional UI with gradient logo
- ✅ Syntax highlighting in REPL
- ✅ Multi-line editing
- ✅ Built-in profiler (v1.1.0)

#### Missing:
- ❌ **No language server (LSP)**
- ❌ **No debugger**
- ❌ **No breakpoints**
- ❌ **No memory profiler**
- ❌ **No hot-reload**
- ❌ **No code formatter**
- ❌ **No type checker**
- ❌ **No VS Code extension**
- ❌ **No IDE integration**

**Verdict: IMPROVING** - Basic tooling in place, needs debugger and IDE integration.

---

### 10. Module System & Ecosystem (Score: 1/10)

#### Current:
- Basic `import "module"` support
- Relative path resolution
- Module caching (v0.4.0)
- Cyclic import detection (v0.4.0)

#### Missing:
- ❌ **No package manager** - no pip equivalent
- ❌ **No standard library modules**
- ❌ **No third-party ecosystem**
- ❌ **No module versioning**
- ❌ **No virtual environments**
- ❌ **No namespace packages**
- ❌ **No __init__.py equivalent**
- ❌ **No module aliasing properly** - import "mod" as m (syntax issue?)
- ❌ **No conditional imports**
- ❌ **No dynamic imports**

#### Ecosystem Reality:
- 0 packages available
- 0 contributors
- 0 community
- Only this repository
- No documentation site
- No examples beyond test files

**Verdict: NO ECOSYSTEM** - Language cannot grow without package ecosystem.

---

### 11. Unique Advantages of Ipp

Despite gaps, Ipp has some strengths:

1. **Python-like Simplicity**
   - Easy to learn for Python developers
   - Clean, readable syntax
   - Friendly error messages (improving)

2. **Game-Focused Built-ins**
   - Vector2, Vector3, Color, Rect built-in
   - Not in standard Lua or Python
   - Similar to GDScript but simpler

3. **Modern CLI**
   - `ipp run`, `ipp check`, `--help` (v0.4.0)
   - User-friendly interface

4. **Beginner-Friendly**
   - No complex setup
   - Single file to run
   - REPL included

5. **Clean Architecture**
   - Well-organized source
   - AST-based (ready for compiler)
   - VM/compiler exist but unused

6. **Open Source**
   - MIT licensed
   - Easy to contribute
   - Full control

---

### 12. Critical Gaps Summary (v0.7.0 COMPLETE)

| Priority | Feature | Impact | Status |
|----------|---------|--------|--------|
| P0 | Exception handling (try/catch) | Game crash on errors | ✅ DONE |
| P0 | Match/switch statement | Unreadable conditionals | ✅ DONE |
| P0 | Ternary operator | Verbose conditionals | ✅ DONE |
| P1 | Type annotations | Code reliability | ✅ DONE |
| P1 | Bitwise operators | Game dev essential | ✅ DONE |
| P1 | List comprehensions | Expressive code | ✅ DONE |
| P1 | Dict comprehensions | Expressive code | ✅ DONE |
| P1 | Enums | Type safety | ✅ DONE |
| P1 | Power operator (**) | Math essential | ✅ DONE |
| P1 | Tooling (debugger) | Usability | ❌ PENDING |
| P2 | Bytecode/VM | Performance | ✅ DONE (v1.0.0) |
| P2 | Package manager | Ecosystem | ❌ PENDING |
| P2 | Generators (yield) | Memory efficiency | ✅ DONE (v1.4.0) |

---

## Roadmap - Phased Implementation

See [ROADMAP_V2.md](ROADMAP_V2.md) for detailed version-by-version plan.

### Quick Overview

| Release | Focus | Status |
|---------|-------|--------|
| v0.5.x | Syntax Fixes | ✅ DONE |
| v0.6.x | Type System | ✅ DONE |
| v0.7.x | Comprehensions | ✅ DONE |
| v0.8.0 | Advanced Operators + Tuples | ✅ DONE |
| v0.9.0 | Control Flow + Exceptions | ✅ DONE |
| v0.10.0 | Functions + OOP Enhancements | ✅ DONE |
| v0.11.0 | Standard Library Expansion | ✅ DONE |
| v0.12.0 | Module System + Tooling | ✅ DONE |
| v0.13.0 | Professional REPL UI | ✅ DONE |
| v1.0.0 | Bytecode VM Infrastructure | ✅ DONE |
| v1.0.1 | VM Stabilization & Bug Fixes | ✅ DONE |
| v1.1.0 | Performance Optimization & Profiler | ✅ DONE |
| v1.1.1 | Bug Fixes (Dict/List Assignment) | ✅ DONE |
| v1.2.0 | Benchmark Suite vs Other Languages | ✅ DONE |
| v1.2.4 | Full VM Class Support | ✅ DONE |
| v1.3.0 | REPL Enhancements | ✅ DONE |
| v1.3.1 | Critical + Major Bugs Fixed | ✅ DONE |
| v1.3.2 | VM Stabilization + Set type | ✅ DONE |
| v1.3.3 | Bug Fixes + Standard Library + Networking | ✅ DONE |
| v1.3.4 | Comprehensive stdlib testing | ✅ DONE |
| v1.3.5 | Regex fix + REPL color fix | ✅ DONE |
| v1.3.6 | VM compatibility tests + REPL warning | ✅ DONE |
| v1.3.7 | REPL enhancements (10 new commands) | ✅ DONE |
| v1.3.8 | HTTP Server, WebSocket, PriorityQueue, Tree, Graph | ✅ DONE |
| v1.3.9 | REPL error handling (smart suggestions) | ✅ DONE |
| v1.3.10 | REPL Intelligence (tab completion, debugger, themes) | ✅ DONE |
| v1.4.0 | Generators + all 7 VM bugs fixed | ✅ DONE |
| v1.5.0 | REPL Performance + Advanced Features | 📋 PLANNED |
| v1.6.0 | Language Server + IDE Integration | 📋 PLANNED |
| v2.0.0 | Package Manager + Ecosystem | 📋 PLANNED |

---

## Summary

**Current State**: v1.5.2a
- 70+/100 overall score
- Most critical features implemented
- VM infrastructure complete with v1.0.0
- All 7 VM bugs fixed by contributor
- Generator functions + Async/Await implemented
- 163+ built-in functions
- 39 passing regression tests
- World-class REPL with tab completion, debugging, themes, shell integration
- VSCode extension with LSP support, snippets, task runner (publish coming soon)
- WASM backend module (v1.5.2a - `ipp wasm` CLI)

**v1.5.2a Target State:**
- WASM backend module ✅ DONE
- `ipp wasm <file>` CLI command ✅ DONE

**v1.5.2b Target State:**
- Web playground with Monaco Editor

**v2.0.0 Production State:**
- 85+/100 overall score
- Full feature set
- Tooling complete
- Ecosystem exists
- Embeddable

---

*Audit completed: 2026-03-27*
*Version: 1.4*

---

# Ipp Language Audit — v1.3.0 Supplement
> **Date:** 2026-03-28 | **Auditor:** Ruthless, no-slack technical review
> **Previous audit covered:** v0.7.0 through v1.1.1
> **This section covers:** v1.2.0 through v1.3.0 (current state)
> **Methodology:** Every claim verified by directly running code against the interpreter and VM.

---

## Summary Table — All Fixed Issues

| ID | Component | Severity | Description | Status |
|---|---|---|---|---|
| BUG-C1 | VM | 🔴 Critical | `_opcode_size` wrong for JUMP_IF_FALSE_POP/TRUE_POP | ✅ FIXED |
| BUG-C2 | VM | 🔴 Critical | `GET_LOCAL` ignores `frame.stack_base` | ✅ FIXED |
| BUG-C3 | Compiler | 🔴 Critical | `exception_var` vs `catch_var` attribute name mismatch | ✅ FIXED |
| BUG-C4 | Compiler | 🔴 Critical | `node.expression` vs `node.subject` in MatchStmt | ✅ FIXED |
| BUG-C5 | Compiler | 🔴 Critical | `SuperExpr` referenced but not defined in AST | ✅ FIXED |
| BUG-C6 | VM | 🔴 Critical | LIST opcode double-deletes the stack | ✅ FIXED |
| BUG-C7 | VM/Bytecode | 🔴 Critical | `emit_loop` ignores `loop_start` parameter | ✅ FIXED |
| BUG-M1 | Parser | 🟠 Major | `&&`/`\|\|` have broken precedence relative to comparisons | ✅ FIXED |
| BUG-M2 | Compiler | 🟠 Major | `^` mapped to power, `**` emits no opcode | ✅ FIXED |
| BUG-M3 | Compiler | 🟠 Major | AND/OR short-circuit compiles both sides always | ✅ FIXED |
| BUG-M4 | Compiler | 🟠 Major | `compile_continue` patches its own jump immediately | ✅ FIXED |
| BUG-M5 | VM | 🟠 Major | `InlineCache` can't distinguish nil value from cache miss | ✅ FIXED |
| BUG-M6 | Parser/AST | 🟠 Major | `ClassDecl` has no superclass field; inheritance not parsed | ✅ FIXED |
| BUG-M7 | VM | 🟠 Major | CALL handler discards args before building local frame | ✅ FIXED |
| BUG-M8 | VM | 🟠 Major | `JUMP_IF_FALSE`/`JUMP_IF_TRUE` missing from `_opcode_size` | ✅ FIXED |
| **BUG-CL1** | VM/Compiler | 🔴 Critical | **Class property assignment bytecode wrong order** | ✅ FIXED |
| **BUG-CL2** | VM | 🔴 Critical | **BoundMethod return value not returned** | ✅ FIXED |
| **BUG-CL3** | VM | 🔴 Critical | **BoundMethod CALL args extracted wrong** | ✅ FIXED |
| **BUG-CL4** | VM/Bytecode | 🟠 Major | **Opcode size wrong for single-byte opcodes** | ✅ FIXED |
| **BUG-CL5** | Parser/Lexer | 🟠 Major | **super() keyword not parsed, init lexed as token** | ✅ FIXED |
| BUG-V1 | VM | 🟡 VM | `MATCH` opcode is a no-op stub | ✅ FIXED |
| BUG-V2 | VM | 🟡 VM | `BREAK`/`CONTINUE` opcodes are no-ops | ✅ FIXED |
| BUG-V3 | VM | 🟡 VM | `FINALLY`/`END_FINALLY` are no-ops; finally never runs | ✅ FIXED |
| BUG-V4 | VM | 🟡 VM | `WITH_ENTER`/`WITH_EXIT` don't implement context protocol | ✅ FIXED |
| BUG-V5 | VM | 🟡 VM | Single exception handler scalar — nested try/catch broken | ✅ FIXED |
| BUG-V6 | VM | 🟡 VM | `EXCEPTION` pushes hardcoded string not actual exception | ✅ FIXED |
| BUG-V7 | VM | 🟡 VM | `GET_CAPTURED` hardcoded to index 0 | ✅ FIXED |
| BUG-V8 | VM | 🟡 VM | Method dispatch returns raw IppFunction not bound method | ✅ FIXED |
| BUG-V9 | VM | 🟡 VM | `VM.SUSPEND` referenced before `VM` class is defined | ✅ FIXED |
| BUG-CP1 | Compiler | 🟡 Compiler | `resolve_local` uses wrong depth comparison | ✅ FIXED |
| BUG-CP2 | Compiler | 🟡 Compiler | `compile_var_decl` calls resolve before define | ✅ FIXED |
| BUG-CP3 | Compiler | 🟡 Compiler | `compile_match` iterates a single ASTNode as if it's a list | ✅ FIXED |
| BUG-CP4 | Compiler | 🟡 Compiler | `EnumDecl` compilation is a no-op `pass` | ✅ FIXED |
| BUG-CP5 | Compiler | 🟡 Compiler | `SelfExpr` compilation is a no-op `pass` | ✅ FIXED |
| BUG-CP6 | Compiler | 🟡 Compiler | `AssignExpr`/`IndexSetExpr` not in `compile_expr` dispatch | ✅ FIXED |
| BUG-P1 | Parser | 🟡 Parser | `statement()` method defined twice; first is dead code | ✅ FIXED |
| BUG-P2 | Parser | 🟡 Parser | `var_type` annotation parsed then immediately discarded | ✅ FIXED |
| BUG-P3 | Parser | 🟡 Parser | Function param/return type annotations silently not parsed | ✅ FIXED |
| BUG-P4 | Parser | 🟡 Parser | `LambdaExpr` defined in AST but never parsed | ✅ FIXED |
| BUG-P5 | Parser | 🟡 Parser | `UnpackExpr` in AST but no parser rule creates it | ✅ FIXED |
| BUG-L1 | Lexer | 🔵 Lexer | `\|` handling duplicated; second branch is dead code | ✅ FIXED |
| BUG-L2 | Lexer | 🔵 Lexer | `COLONCOLON` and `DOUBLE_COLON` are duplicate tokens | ✅ FIXED |
| BUG-L3 | Lexer | 🔵 Lexer | `ARROW2` defined but never lexed or used | ✅ FIXED |
| BUG-L4 | Lexer | 🔵 Lexer | Column tracking wrong after newline in `skip_whitespace` | ✅ FIXED |
| BUG-L5 | Lexer | 🔵 Lexer | String escape sequences (`\n`, `\t`, `\\`) not processed | ✅ FIXED |
| BUG-L6 | Lexer | 🔵 Lexer | No multi-line string support | ✅ FIXED |
| BUG-L7 | Lexer | 🔵 Lexer | Hex, octal, binary literals not lexed | ✅ FIXED |
| BUG-RE1 | REPL | 🟠 Major | `.vars` shows builtins instead of user vars | ✅ FIXED |
| BUG-RE2 | REPL | 🟠 Major | `.modules` command missing | ✅ FIXED |
| BUG-RE3 | REPL | 🟠 Major | No way to switch to VM in REPL | ✅ FIXED |
| BUG-RE4 | REPL | 🟠 Major | ANSI garbage in piped output | ✅ FIXED |
| BUG-RE5 | REPL | 🟡 Minor | No multiline `\` support in REPL | ✅ FIXED |
| BUG-RE6 | REPL | 🟡 Minor | No Ctrl+C interrupt handling | ✅ FIXED |
| DESIGN-1 | Language | 🟣 Design | No compound assignment `+=` `-=` `*=` `/=` `%=` | ✅ FIXED |
| DESIGN-3 | Language | 🟣 Design | `^` ambiguous between power and XOR | ✅ FIXED |
| DESIGN-13 | Language | 🟣 Design | No `super()` call mechanism | ✅ FIXED |
| DESIGN-14 | Language | 🟣 Design | Range `0..5` inclusive/exclusive undocumented | ✅ DOCUMENTED |
| DESIGN-15 | Language | 🟣 Design | Type annotations parsed then ignored end-to-end | ✅ FIXED |

---

## New Bugs Confirmed in v1.3.0

These are **new issues not listed in any previous audit** — either regressions, newly discovered, or arising from features added since v1.1.1.

---

### 🔴 CRITICAL — BUG-NEW-C1: VM `for` loop compiler is a non-functional stub

**File:** `ipp/vm/compiler.py`, `compile_for()`, lines 284–340
**Severity:** CRASH — every `for` loop on the VM/bytecode path crashes.
**Status:** ✅ FIXED in v1.3.1

The compiler comment *literally says* "For now emit a simplified for each using GET_INDEX pattern" but then emits a `JUMP_IF_FALSE_POP` directly on the list object. A non-empty list is truthy, so it jumps over the body entirely and never iterates. Then it emits an `emit_loop` back to a stale `loop_start` that doesn't re-check anything. Verified:

```
VM for loop FAIL: pop from empty list
```

**Fix applied:** Implemented proper iteration in `compile_for()`:
1. Push iterator list and get its length
2. Reserve local slot for index, initialize to 0
3. Each iteration: check if index < length, if not break
4. Get list[index], assign to loop variable
5. Increment index, loop back

---

### 🔴 CRITICAL — BUG-NEW-C2: Runtime error line numbers always report `line 0`

**File:** `ipp/interpreter/interpreter.py`, `run()`, line 276
**Status:** ✅ FIXED in v1.3.1

**Verified (before fix):**
```
Error at line 0 in main: Undefined variable: undefinedVar
```

**Fix applied:**
1. Updated `execute()` to set `self.current_line = getattr(stmt, 'line', 0)` before executing each statement
2. Updated `visit_identifier()` to set `self.current_line` when resolving identifiers
3. Updated parser to set `line` attribute on `Identifier` nodes

Now runtime errors correctly report the line number:
```
Error at line 1 in main: Undefined variable: undefinedVar
```

---

### 🔴 CRITICAL — BUG-NEW-C3: Operator overloading for user-defined classes is silently broken

**File:** `ipp/interpreter/interpreter.py`, `visit_binary_expr()`, lines 314–380
**Status:** ✅ FIXED in v1.3.1

**Verified (before fix):**
```
operator overload FAILS: Only instances have properties, got <class 'str'>
```

**Fix applied:**
1. Added `_ipp_has_method(obj, method_name)` helper to check if IppInstance has a method via `ipp_class.get_method()`
2. Added `_ipp_call_method(obj, method_name, arg)` helper to call Ipp methods via `BoundMethod`
3. Updated all operator checks to use `_ipp_has_method()` instead of Python's `hasattr()`
4. Implemented dispatch for: `__add__`, `__sub__`, `__mul__`, `__truediv__`, `__eq__`, `__ne__`, `__lt__`, `__gt__`, `__le__`, `__ge__`

Now operator overloading works correctly:
```ipp
class Vec2 {
    func init(x, y) { this.x = x this.y = y }
    func __add__(v) { return Vec2(this.x + v.x, this.y + v.y) }
}
var c = Vec2(1, 2) + Vec2(3, 4)  # c.x = 4, c.y = 6
```

---

### 🟠 MAJOR — BUG-NEW-M1: Closures do not capture mutable variables by reference

**File:** `ipp/interpreter/interpreter.py`, `call_function()`
**Status:** ⚠️ PARTIALLY FIXED - Interpreter works, VM broken

**Interpreter (✅ WORKS):**
```ipp
func make_counter() {
    var count = 0
    func increment() {
        count += 1
        return count
    }
    return increment
}
var c = make_counter()
print(c())  # 1 ✅
print(c())  # 2 ✅
print(c())  # 3 ✅
```

**VM (❌ BROKEN - BUG-NEW-M5):**
```ipp
# VM fails with: Undefined variable 'count'
```

**Fix required for VM:** Implement proper upvalue cells - create `Upvalue` objects that point to stack slots, move to heap on `CLOSE_UPVALUE`, read/write through upvalue pointer.

---

### 🟠 MAJOR — BUG-NEW-M2: No integer vs float type distinction at runtime

**Status:** ✅ FIXED in v1.3.1

**Verified (before fix):**
```
type(5)    → "number"
type(5.0)  → "number"
```

**Verified (after fix):**
```
type(5)    → "int" ✅
type(5.0)  → "float" ✅
type(7//2) → "int" ✅
```

**Fix applied:** Updated `ipp_type()` in `builtins.py` to return `"int"` for Python `int` and `"float"` for Python `float`.

---

### 🟠 MAJOR — BUG-NEW-M3: No default parameter values

**Status:** ✅ FIXED in v1.3.1

**Verified (before fix):**
```
func greet(name, greeting = "Hello") { }
→ Parse error at line 1, col 27: Expect ')' after parameters
```

**Verified (after fix):**
```ipp
func greet(name, greeting = "Hello") {
    print(greeting + " " + name)
}
greet("World")           # Hello World ✅
greet("Alice", "Hi")     # Hi Alice ✅

func add(x, y = 10) {
    return x + y
}
add(5)                   # 15 ✅
add(5, 3)                # 8 ✅
```

**Fix applied:**
1. Added `defaults` field to `FunctionDecl` and `LambdaExpr` AST nodes
2. Added `defaults` parameter to `IppFunction` class
3. Updated parser to parse `= expression` for default values
4. Updated `call_function()` to fill in defaults for missing args

---

### 🟠 MAJOR — BUG-NEW-M4: No named/keyword arguments

**Verified:**
```
func f(x, y) { return x - y }
f(y=1, x=10)
→ Error: Undefined variable: y
```
`y=1` is parsed as an assignment expression `y = 1`, which creates/assigns the global variable `y`. The value `10` is passed as first positional argument `x`. `y` in the function body reads the global `y` (which is `1`), not the argument. This is a silent wrong-result bug, not even a crash — arguably worse than a crash.

**Fix required:** Lex `NAME =` as a new token type (e.g., `NAMED_ARG`), parse it in `arguments()` to produce a list of `(name, expr)` pairs, and in `call_function()` match named args to parameters by name before filling positional args.

---

### 🟠 MAJOR — BUG-NEW-M5: Upvalues in the VM are captured by value, not by reference

**File:** `ipp/vm/vm.py`, `CLOSE_UPVALUE` handler, line 491
```python
elif opcode == OpCode.CLOSE_UPVALUE:
    pass  # for now upvalues are captured by value
```
The comment is the entire implementation. Upvalues in the VM are never actually closed over — the `Closure` object is created with an empty upvalue list and nothing is ever written into it from the enclosing scope. Every closure in the VM path that tries to read a variable from an outer function scope will either get `None` or crash. This means the VM cannot execute any meaningful closure-based code correctly.

**Fix required:** Implement proper upvalue cells: create `Upvalue` objects that point to stack slots in the enclosing frame, move them to the heap when the enclosing function returns (`CLOSE_UPVALUE`), and read/write through the upvalue pointer in both the inner and outer function's scope.

---

### 🟠 MAJOR — BUG-NEW-M6: No Set data type

There is no `Set` type in Ipp. Every language used in game development has sets: Lua uses tables as sets, Python has `set()`, GDScript has `Dictionary` with sentinel values. Sets are essential for: entity tag systems, visited-node tracking in pathfinding, deduplication, fast membership testing. The workaround — using a dict with dummy values — is verbose and error-prone. `type` and `isinstance` cannot distinguish it.

**Fix required:** Implement `IppSet` class with `add()`, `remove()`, `contains()`, `union()`, `intersection()`, `difference()`, and expose `set()` builtin function.

---

### 🟠 MAJOR — BUG-NEW-M7: No multiple assignment / tuple unpacking

**Verified:**
```
var a, b = 1, 2
→ Parse error at line 1, col 6: Unexpected token: Token(COMMA, ',', line=1)

func swap(a, b) { return b, a }
var x, y = swap(1, 2)
→ Parse error at line 1, col 27: Unexpected token: Token(COMMA, ',', line=1)
```
Cannot return multiple values from a function in a usable way. Cannot destructure a list into named variables. These are standard in Python, Lua (`return a, b`), and GDScript. For game development this matters constantly: `var pos_x, pos_y = get_position()`.

**Fix required:** Parse `var a, b = expr` as a special `MultiVarDecl` node. Compile it as: evaluate `expr`, assert result is a list/tuple with matching length, then store each element into its own local slot. For multiple return values, push all of them on the stack and unpack at the assignment site.

---

### 🟡 NOTABLE — BUG-NEW-N1: Private member convention has zero enforcement

**Verified:**
```ipp
class BankAccount {
    func init(balance) { self._balance = balance }
}
var acc = BankAccount(100)
acc._balance = -9999   # works perfectly, no error
```
Ipp has no access control whatsoever. The underscore prefix `_field` is a documentation convention with zero runtime enforcement. In a language targeting game development — where scripts from different systems interact — having no encapsulation means any script can corrupt any object's internal state silently.

**Fix required:** Add a naming convention check: fields prefixed with `__` (double underscore) are name-mangled to `_ClassName__field` at compile time, similar to Python's private attribute mangling.

---

### 🟡 NOTABLE — BUG-NEW-N2: No recursion depth limit with meaningful error message

**Verified:** Infinite recursion produces Python's raw `RecursionError: maximum recursion depth exceeded` wrapped as `Error at line 0 in main: maximum recursion depth exceeded`. The Python stack limit (1000 frames by default) fires before any Ipp-level check. There is no configurable Ipp-level recursion limit, no stack trace of Ipp call frames, and the error message gives no indication of where in the Ipp code the overflow occurred.

**Fix required:** Add `call_depth` tracking in the interpreter, increment before each `call_function()` and `visit_function_decl()`, check against a configurable `max_depth` (default 1000), and generate a proper Ipp stack trace showing Ipp function names and source locations.

---

### 🟡 NOTABLE — BUG-NEW-N3: No f-strings / string interpolation

**Verified:**
```
var name = "World"
var s = f"Hello {name}!"
→ Error: Undefined variable: f
```
`f"..."` is not lexed as a string prefix — the `f` is lexed as an identifier, then `"Hello {name}!"` is a string. The result is trying to call/access a variable named `f`. String interpolation is the single most commonly requested missing feature in scripting languages. Every single competing language has it: Python f-strings, JavaScript template literals, GDScript `%s % value`. Writing `"Hello, " + name + "!"` is adequate for a tutorial but unacceptable as the canonical API.

**Fix required:** Lex an `f"` or `F"` prefix as a new `FSTRING` token type. Parse the string contents to extract `{expr}` segments. Compile to: push the format string, evaluate each interpolation expression, and call a builtin `fstring(format, *values)` function at runtime.

---

### 🟡 NOTABLE — BUG-NEW-N4: No generator functions / `yield` keyword

**Verified:**
```
func gen() { yield 1 }
→ Error: Undefined variable: yield
```
`yield` is not a keyword — it is lexed as an identifier. Generators are essential for: lazy sequences, coroutines in game loops, state machines. Without generators, infinite sequences must be modelled as explicit state objects, making game AI and animation code dramatically more verbose.

**Fix required:** Lex `yield` as a new keyword token. Add `yield` to the expression grammar. Create a `Generator` object that wraps a `Function` and maintains a stack of saved execution states. When `yield` is encountered, serialize the current frame state to the generator object and return the yielded value. The next call to the generator resumes from the yield point.

---

### 🟡 NOTABLE — BUG-NEW-N5: Error messages lack column numbers at runtime

Parse errors correctly report line and column: `Parse error at line 3, col 12`. Runtime errors do not: `Error at line 0 in main: ...`. The `current_line` is tracked but never includes column information. The call stack shows only function names (`main -> myFunc`), not file:line:col. Compared to Python's traceback with exact file, line, column, and source snippet — Ipp's error output is nearly useless for debugging non-trivial programs.

**Fix required:** Extend the error reporting infrastructure to include column: store `current_column` alongside `current_line` during execution, pass both to `IppRuntimeError`, and format errors as `Error at line X, col Y in function: message`.

---

### 🟡 NOTABLE — BUG-NEW-N6: `__str__` method on user classes not called by `print()`

**Expected behavior:** `print(myObject)` should call `myObject.__str__()` if defined.
**Actual behavior:** `print()` receives an `IppInstance`, which has Python's `__repr__` returning `<ClassName instance>`. The `ipp_print` builtin does not check for a user-defined `__str__` method before calling Python's `str()`. So even if a user defines `func __str__()`, `print(obj)` ignores it entirely.

**Fix required:** In `ipp_print` (and all other builtins that stringify values), check if the object has a `__str__` method in its fields. If so, call it and use the result. Fall back to Python's `str()` only if no `__str__` is defined.

---

### 🟡 NOTABLE — BUG-NEW-N7: No `async`/`await` or coroutine support

Game development fundamentally requires non-blocking operations: loading assets, waiting for animations, network calls. Without `async/await`, all timing logic must be manually managed through update loops and state machines. GDScript has `await`, Lua has coroutines via `coroutine.yield`, JavaScript has async/await. Ipp has nothing.

**Fix required:** Implement async/await as a thin layer over generators: mark functions containing `await` as async, compile `await expr` as `yield wait(expr)`, and add an event loop that drives async functions by calling `.send()` repeatedly until the generator is exhausted or yields a `Wait` sentinel.

---

### 🟡 NOTABLE — BUG-NEW-N8: List/Dict methods only work on `IppList`/`IppDict` wrappers, not on native Python lists

The interpreter sometimes returns native Python `list` and `dict` objects (e.g., from builtins like `range()`, comprehension results, spread results). Calling `.append()`, `.push()`, `.contains()` on these native objects fails because those methods belong to the `IppList` wrapper class, not Python's native `list`. This creates inconsistent behavior where two lists that look identical have different available methods depending on how they were created.

**Fix required:** Wrap ALL list and dict return values from builtins in `IppList`/`IppDict`. Ensure comprehensions and spread operator results are also wrapped. Alternatively, add a duck-typed fallback: if the object lacks `.append`, try calling Python's `append` method directly.

---

### 🟡 NOTABLE — BUG-NEW-N9: `match` statement is pure equality matching — no structural or type patterns

```ipp
match x {
    case 1 => print("one")            # equality check
    case "hello" => print("string")   # equality check
}
```
Ipp's match is a glorified `if/elif` chain. It cannot:
- Destructure: `case [head, ...tail] =>`
- Match on type: `case int =>`
- Bind variables: `case Point(x: px, y: py) =>`
- Guard conditions: `case n if n > 0 =>`
- Match ranges: `case 1..10 =>`

Python 3.10's structural pattern matching, Rust's `match`, and even GDScript's `match` all support at least type-based and value-binding patterns. Ipp's implementation is the minimum viable version and should not be marketed as "pattern matching."

**Fix required:** Extend the `CaseClause` AST node to include: optional type guard (`case int =>`), optional guard expression (`case n if n > 0 =>`), optional destructuring pattern (`case [h, ...t] =>`). Compile each pattern type to the appropriate runtime check.

---

### 🟡 NOTABLE — BUG-NEW-N10: No `continue` with label / no labeled `break` in the VM

The parser supports `break label` and `continue label` syntax. The interpreter ignores the label field in `BreakStmt`/`ContinueStmt` — it just sets `break_flag = True` regardless. The VM compiler emits a plain `JUMP` with no label tracking. Breaking out of nested loops requires ugly workarounds like flag variables.

**Fix required:** Create a `LoopContext` stack in the compiler. When entering a labeled loop, push its context with the label name. When compiling `break label` or `continue label`, look up the label in the context stack to find the correct loop to jump to. Emit the appropriate jump offset for the VM.

---

## Updated Scores (v1.3.1)

| Aspect | v1.1.1 (prev) | v1.3.0 (prev) | v1.3.1 (now) | Change | Notes |
|---|---|---|---|---|---|
| Syntax | 6.5 | 6.5 | 6.5 | → | No f-strings, no default params yet |
| Types | 5.5 | 5.0 | 5.0 | → | int/float conflation remains |
| Control Flow | 7.5 | 7.0 | 8.0 | ↑ | VM for-loop now works! |
| Functions | 6.0 | 5.5 | 7.5 | ↑ | Defaults + operator overloading |
| OOP | 6.0 | 5.5 | 7.0 | ↑ | Operator overloading fixed |
| Standard Library | 6.5 | 6.5 | 6.5 | → | Stable |
| Game Features | 5.5 | 5.5 | 5.5 | → | No new game primitives |
| Performance | 5.0 | 4.5 | 6.0 | ↑ | VM for-loop works |
| Closures | 6.0 | 4.0 | 5.0 | ↑ | Interpreter works (VM still broken) |
| Error Messages | 3.0 | 3.0 | 7.0 | ↑ | Line numbers now correct! |
| Types | 5.5 | 5.0 | 7.0 | ↑ | int/float now distinguished |
| Tooling | 5.0 | 5.5 | 7.0 | ↑ | REPL improved |
| Ecosystem | 1.0 | 1.0 | 1.0 | → | Still zero packages |
| **TOTAL** | **63.0** | **59.5** | **69.5** | **↑** | Major bugs fixed! |

---

## Priority Fix List (v1.3.x)

Ordered by severity × frequency of impact:

| ID | Bug | Severity | Status | Fix Complexity |
|---|---|---|---|---|
| BUG-NEW-C1 | VM `for` loop is a stub | 🔴 Critical | ✅ FIXED v1.3.1 | High |
| BUG-NEW-C2 | Runtime errors always say `line 0` | 🔴 Critical | ✅ FIXED v1.3.1 | Medium |
| BUG-NEW-C3 | User-class operator overloading broken | 🔴 Critical | ✅ FIXED v1.3.1 | Medium |
| BUG-NEW-M1 | Closures (interpreter) | 🟠 Major | ✅ FIXED v1.3.1 | Low |
| BUG-NEW-M2 | int/float indistinguishable at runtime | 🟠 Major | ✅ FIXED v1.3.1 | Low |
| BUG-NEW-M3 | No default parameter values | 🟠 Major | ✅ FIXED v1.3.1 | Medium |
| BUG-NEW-M4 | Named args silently produce wrong results | 🟠 Major | ✅ FIXED v1.3.3 | High |
| BUG-NEW-M5 | VM upvalues captured by value | 🟠 Major | ✅ FIXED v1.3.2 | High |
| BUG-NEW-M6 | No Set type | 🟠 Major | ✅ FIXED v1.3.2 | Low |
| BUG-NEW-M7 | No tuple unpacking / multi-assignment | 🟠 Major | ✅ FIXED v1.3.3 | Medium |
| BUG-NEW-N1 | No access control enforcement | 🟡 Notable | ⏳ TODO | Low |
| BUG-NEW-N2 | No Ipp-level recursion limit | 🟡 Notable | ⏳ TODO | Low |
| BUG-NEW-N3 | No f-strings | 🟡 Notable | ⏳ TODO | Medium |
| BUG-NEW-N4 | No generators/yield | 🟡 Notable | ✅ FIXED v1.4.0 | High |
| BUG-NEW-N5 | Runtime errors lack column info | 🟡 Notable | ⏳ TODO | Low |
| BUG-NEW-N6 | `__str__` not called by print() | 🟡 Notable | ✅ FIXED v1.3.3 | Low |
| BUG-NEW-N7 | No async/await | 🟡 Notable | ⏳ TODO | Very High |
| BUG-NEW-N8 | IppList/native list method inconsistency | 🟡 Notable | ✅ FIXED v1.3.3 | Medium |
| BUG-NEW-N9 | Match is equality-only, not structural | 🟡 Notable | ⏳ TODO | High |
| BUG-NEW-N10 | Labeled break/continue silently ignored | 🟡 Notable | ⏳ TODO | Medium |

---

*Supplement audit completed: 2026-03-28 | v1.3.0*
*v1.3.1 completed: 2026-03-29 - Critical bugs fixed*
*v1.3.2 completed: 2026-03-30 - VM upvalues + Set type*
*v1.3.3 completed: 2026-04-02 - Bug fixes + Networking + Standard Library*
*v1.3.4 completed: 2026-04-02 - Comprehensive stdlib testing (130+ builtins)*
*v1.3.5 completed: 2026-04-02 - Regex fix + REPL color fix*
*v1.3.6 completed: 2026-04-02 - VM compatibility tests + REPL warning*
*v1.3.7 completed: 2026-04-02 - REPL enhancements (10 new commands)*
*v1.3.8 completed: 2026-04-02 - HTTP Server, WebSocket, PriorityQueue, Tree, Graph*
*v1.3.9 completed: 2026-04-02 - REPL error handling (smart suggestions)*
*v1.3.10 completed: 2026-04-02 - REPL Intelligence (tab completion, debugger, themes)*
*v1.4.0 completed: 2026-04-07 - Generators + all 7 VM bugs fixed (contributor)*
*v1.4.1 completed: 2026-04-07 - Error Documentation + Error Reference Guide (ERRORS.md, 20 error codes)*
*v1.4.2 completed: 2026-04-07 - Tutorial Documentation + Getting Started Guide (TUTORIAL.md, 25 verified examples)*
*v1.4.3 completed: 2026-04-07 - PyPI Publishing (pyproject.toml, GitHub Actions, ipp-lang package)*
*v1.5.0 completed: 2026-04-07 - Async/Await + Coroutines + Event Loop + Additional Builtins (31 new builtins)*
*v1.5.1 completed: 2026-04-08 - VSCode Extension + LSP (15 snippets, task runner, LSP server, hover, completion)*
*v1.5.2 planned: WASM Compilation + Web Playground*
*v1.5.3 planned: WebGL Integration + 2D Canvas Rendering*
*v1.5.4 planned: Repl Enhancement*
*v1.5.5 planned: 3D Rendering + Scene Graph*
*v1.6.0 planned: C++ Integration + Native Extensions*
*v1.6.1 planned: Cross-Platform (iOS, macOS, Linux, Windows)*
*v2.0.0 planned: Package Manager + Full Ecosystem + Game Engine*
*Total new issues found: 20 (3 critical, 7 major, 10 notable)*

---

## v1.3.2 Current Status

**Release:** https://github.com/authorss81/Ipp/releases/tag/v1.3.2-bugfix

### Fixed ✅
- VM upvalues by reference (BUG-NEW-M5)
- Set data type (BUG-NEW-M6)
- arg_idx calculation in interpreter
- Recursion depth tracking in VM
- Private field protection in VM (partial)
- __str__ method support in VM (partial)

### Needs Fix ⚠️
- **Class instantiation** - Property assignment pushes extra value on stack
- See `BUGFIX_INSTRUCTIONS.md` for details

---

## v1.3.3 Current Status

**Release:** https://github.com/authorss81/Ipp/releases/tag/v1.3.3

### Fixed ✅
- **and/or precedence bug** — `1 == 1 and 2 == 2` now correctly returns `true`
  - Root cause: `and`/`or` keywords mapped to `DOUBLE_AMP`/`DOUBLE_PIPE` tokens (shared with bitwise `&`/`||`)
  - Fix: Dedicated `TokenType.AND`/`TokenType.OR` tokens, parser updated, short-circuit before left evaluation
- **Nested `len(items(d))` IppList error** — `len(items(d))` now works directly
  - Root cause: Plain Python list with `__call__` in introspection confused `callable()` check
  - Fix: Explicit `IppList` guard in `visit_call_expr` with clear error message
- **Named arguments** (BUG-NEW-M4) — `f(name="Alice", greeting="Hi")` now works
- **Tuple unpacking** (BUG-NEW-M7) — `var a, b = [1, 2]` now works
- **Operator overloading** (BUG-NEW-C3) — `__add__`, `__sub__`, `__mul__`, `__eq__` now dispatch correctly
- **`__str__` method** (BUG-NEW-N6) — `print(obj)` now calls user-defined `__str__`
- **IppList consistency** (BUG-NEW-N8) — All list returns wrapped in `IppList`

### New Features ✅
- **HTTP Client** — `http_get()`, `http_post()`, `http_put()`, `http_delete()`, `http_request()`
- **FTP Client** — `ftp_connect()`, `ftp_disconnect()`, `ftp_list()`, `ftp_get()`, `ftp_put()`
- **SMTP Email** — `smtp_connect()`, `smtp_disconnect()`, `smtp_send()`
- **URL Utilities** — `url_encode()`, `url_decode()`, `url_query_build()`, `url_query_parse()`
- **Math Library** — `lerp`, `clamp`, `distance`, `normalize`, `dot`, `cross`, `sign`, `smoothstep`, `move_towards`, `angle`, `deg_to_rad`, `rad_to_deg`, `factorial`, `gcd`, `lcm`, `hypot`, `floor_div`
- **Collections** — `deque`, `ordict`, `set`
- **Data Formats** — `xml_parse`, `yaml_parse`, `toml_parse`, `csv_parse`, `csv_parse_dict`
- **Utilities** — `printf`, `sprintf`, `scanf`, `gzip_compress`, `gzip_decompress`, `zip_create`, `zip_extract`

### Regression Tests
- All 15 test suites pass (v0.5.0 through v1.3.3 including network tests)
- No regressions introduced

---

## v1.3.7 — REPL Enhancements ✅ DONE

### Implemented REPL Commands
- [x] `.load <file>` — Load and execute file in current session (keeps variables)
- [x] `.save <file>` — Save session history to file
- [x] `.doc <function>` — Show docstring/help for builtin function
- [x] `.time <expr>` — Benchmark expression execution time
- [x] `.which <name>` — Show if name is builtin, variable, or function
- [x] `.last` / `$_` — Reference the last result
- [x] `.undo` — Undo last command's effect on global env
- [x] `.edit` — Open last command in external editor
- [x] `.profile` — Profile last command with cProfile
- [x] `.alias <name> <cmd>` — Create custom REPL command aliases
- [x] Multi-line paste detection
- [x] Env snapshots for undo (up to 50)
- [x] Updated `.help` with REPL Tools section

---

## v1.3.8 — Networking + Collections ✅ DONE

### HTTP Server ✅ DONE
- [x] `http_serve(handler, host, port)` — Start HTTP server with GET/POST/PUT/DELETE support
- [x] Request handling with method, path, headers, body
- [x] Response with status code, headers, body

### PriorityQueue ✅ DONE
- [x] `PriorityQueue()` — Heap-based priority queue
- [x] `push(item, priority)` / `pop()` / `peek()` / `is_empty()` / `len()`

### Tree ✅ DONE
- [x] `Tree(value)` — Tree node with value and children
- [x] `add_child()`, `remove_child()`, `get_child()`, `len()`
- [x] `traverse_preorder()`, `traverse_postorder()`, `traverse_bfs()`
- [x] `find(value)`, `depth()`

### Graph ✅ DONE
- [x] `Graph(directed)` — Directed/undirected graph
- [x] `add_node()`, `add_edge()`, `remove_node()`, `remove_edge()`
- [x] `has_node()`, `has_edge()`, `get_neighbors()`, `node_count()`, `edge_count()`
- [x] `dfs(start)`, `bfs(start)`, `shortest_path(start, end)` (Dijkstra)

### WebSocket ⏳ TODO
- [ ] `websocket.server(handler, host, port)` — WebSocket server
- [ ] `websocket.connect(url)` — WebSocket client

---

## v1.3.9 — REPL Error Handling ✅ DONE

### Error Suggestions ✅ DONE
- [x] Smart suggestions — "Did you mean: ..." for typos using difflib fuzzy matching
- [x] Context-aware tips — different suggestions for different error types
- [x] Undefined variable → suggests similar builtin/variable names
- [x] Cannot call → suggests checking if variable is a function
- [x] TypeError → suggests checking operand types
- [x] Index out of range → suggests checking length first
- [x] Recursion depth → suggests checking base case
- [x] Syntax errors → suggests checking brackets/parentheses
- [x] Error regex matches both `Undefined variable 'x'` and `Undefined variable: x` formats
- [x] Deduplicated suggestions (no duplicate names)

### Bug Fixes ✅ DONE
- [x] `highlight()` corruption — checks for existing ANSI codes to prevent double-coloring
- [x] `.colors on` on Windows — enables virtual terminal processing
- [x] Moved all stray test files from root to `tests/misc/`

---

## v1.3.10 — REPL Intelligence + Debugging ✅ DONE

### Tab Completion ✅ DONE
- [x] Tab completion for keywords, builtins, variables
- [x] Tab completion for dict keys (`my_dict["<TAB>`)
- [x] Tab completion for file paths
- [x] Fuzzy matching for completions
- [x] REPL command completion (`.help`, `.load`, etc.)
- [x] Member completion (`obj.<TAB>`)
- [x] Enhanced IppCompleter with `_load_completions()`, `_get_all_candidates()`, `_dict_keys()`
- [x] Type hints on hover/tab (`.typehints`)
- [x] Signature help when typing `(` (`.sighelp`)

### Code Intelligence ✅ DONE
- [x] Auto-indentation after `{`, `(`, `[`
- [x] Bracket matching configuration
- [x] Pretty printing — `_pretty_print()` for nested structures
- [x] Expression history — `$_1`, `$_2`, etc. injected into interpreter
- [x] `.redo` — Redo after `.undo`
- [x] `.session save/load/clear` — Session persistence
- [x] `.pretty <expr>` — Pretty print complex data
- [x] `.stack` — Show call stack
- [x] `! <cmd>` — Execute shell commands
- [x] `.history $_` — Show expression history
- [x] Auto-formatting on Enter (`.format <expr>`)

### Debugging ✅ DONE
- [x] `.debug start/stop` — Step-through debugger
- [x] `.break <line>` — Set breakpoints by line number
- [x] `.watch <expr>` — Watch expressions
- [x] `.locals` — Show local variables

### Output Improvements ✅ DONE
- [x] `.table <var>` — Show list of dicts as formatted table
- [x] `.json <expr>` — JSON viewer with formatting
- [x] Custom formatters per type

### Shell Integration ✅ DONE
- [x] `! <cmd>` — Execute shell commands
- [x] `.pipe <cmd>` — Pipe Ipp output to shell commands
- [x] `.cd <dir>` — Change directory
- [x] `.ls [dir]` — List directory contents
- [x] `.pwd` — Print working directory

### Session Management ✅ DONE
- [x] Session persistence — auto-save/restore across restarts
- [x] Multiple named sessions (`.sessions`)
- [x] Session export as `.ipp` script (`.export`, `.session export`)
- [x] `.redo` — redo after `.undo`
- [x] Expression history — `$_1`, `$_2`, etc.

### Customization ✅ DONE
- [x] Custom themes — `.theme dark/light/solarized`
- [x] Prompt customization — `.prompt dir/time/full/ipp`
- [x] Key bindings — `.bind <key> <cmd>`
- [x] Plugin system — `.plugin load <file>`

### Documentation ✅ DONE
- [x] `.tutorial` — Interactive tutorial mode
- [x] `.plugin load <file>` — Load plugin files
- [x] `.search <keyword>` — Search builtin documentation
- [x] `.examples` — Show interactive code examples (10 examples)
- [x] Contextual help — show relevant help based on current error
- [x] Example browser (`.examples`)

---

## v1.4.0 — Generators + Async/Await + Engine Integration ✅ DONE

### Generator Functions ✅ DONE
- [x] Lex `yield` as keyword
- [x] Create `IppGenerator` object
- [x] Serialize/resume execution state via yield count tracking
- [x] `next(gen)` and `for x in gen` iteration
- [x] `is_generator(obj)` builtin function

### VM Bug Fixes ✅ DONE (by contributor)
- [x] VM-BUG-1: Function calls with arguments — `add(3, 4)` returns 7
- [x] VM-BUG-2: Dict index access — `d["key"]` works correctly
- [x] VM-BUG-3: Try/catch — catches undefined variables
- [x] VM-BUG-4: Class property access — `instance.field` works
- [x] VM-BUG-5: Named arguments — `f(y=1, x=10)` works
- [x] VM-BUG-6: Recursion — `fib(10)` returns 55
- [x] VM-BUG-7: For loops — `for i in 0..5` works

### Async/Await ⏳ TODO
- [ ] Implement async/await over generators
- [ ] Add event loop
- [ ] Handle `await expr` as `yield wait(expr)`

### Engine Bindings
- [ ] Pygame integration
- [ ] Godot GDScript alternative
- [ ] Raylib binding
- [ ] SFML binding
- [ ] Love2D integration

### Editor Integration
- [ ] VSCode extension
- [ ] Vim/Neovim plugin
- [ ] Emacs major mode
- [ ] LSP server (v1.6.0)

---

## v1.5.1 — VSCode Extension + LSP 📋 PLANNED

### Language Server Protocol
- [ ] LSP server for Ipp language
- [ ] Go-to-definition
- [ ] Find all references
- [ ] Rename symbol
- [ ] Code actions / quick fixes
- [ ] Diagnostics (linting)
- [ ] Hover information

### VSCode Extension
- [ ] Syntax highlighting (TMGrammar)
- [ ] Snippets (func, class, for, while, etc.)
- [ ] LSP integration (diagnostics, completion, hover)
- [ ] Run/Debug Ipp code from VSCode
- [ ] Integrated REPL panel
- [ ] Task runner for `ipp run`, `ipp check`

### Other IDE Extensions
- [ ] Vim/Neovim plugin
- [ ] Emacs major mode
- [ ] Sublime Text package

---

## v1.5.2 — WASM Compilation 📋 PLANNED

### WASM Backend
- [ ] Compile Ipp bytecode to WebAssembly
- [ ] JavaScript bridge for browser
- [ ] Web Playground with Monaco Editor

---

## v1.5.3 — WebGL Integration + 2D Rendering 📋 PLANNED

### 2D Canvas API
- [ ] `canvas(width, height)` — create canvas
- [ ] `canvas.draw_rect`, `canvas.draw_circle`, `canvas.draw_line`
- [ ] `canvas.draw_text`, `canvas.clear`, `canvas.render`

### WebGL Bindings
- [ ] `webgl.init`, `webgl.create_shader`, `webgl.create_program`
- [ ] `webgl.draw_triangles`, `webgl.set_uniform`

---

## v1.5.4 — REPL Performance + Advanced Features 📋 PLANNED
### Performance & Monitoring
- [ ] Real-time profiling — CPU/memory stats per command
- [ ] Benchmark mode — run command N times, show avg/min/max
- [ ] Hot reload — auto-reload imported modules when files change
- [ ] Async REPL — handle `async/await` natively in REPL
- [ ] Background tasks — run long tasks in background
### Advanced REPL Features
- [ ] Multi-line editor — full editor for multi-line input
- [ ] Code snippets — predefined templates
- [ ] Memory profiler — show memory usage per variable/object
- [ ] REPL server — connect to REPL remotely via network
- [ ] Code review mode — compare two expressions side-by-side
- [ ] Macro system — define REPL macros that expand to code
- [ ] Checkpoint/rollback — save checkpoint, rollback to any point
### Data Visualization
- [ ] Plot graphs/charts from data (matplotlib integration)
- [ ] HTML preview — render HTML strings in browser
---

## v1.5.5 — 3D Rendering + Scene Graph 📋 PLANNED
### 3D Math
- [ ] `mat4()` — 4x4 matrix operations
- [ ] `vec4()` — 4D vector
- [ ] `quat()` — quaternion operations (slerp, rotate)
- [ ] `perspective(fov, aspect, near, far)` — perspective matrix
- [ ] `look_at(eye, target, up)` — view matrix
### Scene Graph
- [ ] `Scene()` — scene container
- [ ] `Node()` — scene node with transform
- [ ] `Camera(fov, aspect)` — camera node
- [ ] `Mesh(vertices, indices)` — mesh node
- [ ] `Light(type, color, intensity)` — light node
- [ ] `scene.render()` — render scene
---

## v1.6.0 — C++ Integration 📋 PLANNED

### C++ API
- [ ] `#include "ipp.hpp"` — C++ header for embedding
- [ ] `ipp::Interpreter`, `ipp::VM` — C++ classes
- [ ] `ipp::register_function`, `ipp::register_class`
- [ ] Native extension loading

---

## v1.6.1 — Cross-Platform 📋 PLANNED

### Platform Support
- [ ] macOS: Homebrew formula
- [ ] Linux: APT/DEB package, Snap/Flatpak
- [ ] Windows: MSI installer, Scoop/Chocolatey
- [ ] iOS: Ipp runtime for iOS apps
- [ ] Android: Ipp runtime for Android apps

---

## v2.0.0 — Package Manager + Ecosystem 📋 PLANNED

### Package Manager
- [ ] `ippkg` CLI tool
- [ ] Package registry
- [ ] `ippkg install <package>`
- [ ] `ippkg publish <package>`
- [ ] Dependency resolution
- [ ] Version management

### Standard Library Expansion
- [ ] HTTP/2 support
- [ ] GraphQL client
- [ ] Database drivers (SQLite, PostgreSQL)
- [ ] WebSocket client/server
- [ ] Image processing
- [ ] Audio processing
