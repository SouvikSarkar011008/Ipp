# Ipp Language Roadmap

## 1. Vision & Philosophy

### Core Vision

Ipp is a beginner-friendly scripting language designed exclusively for high-performance game development that evolves from simplicity to world-class power through deliberate versioning.

### Design Philosophy

- **Simplicity First**: Every feature must be learnable by a beginner
- **Game-Dev Native**: Every decision prioritizes game development workflows
- **Progressive Power**: Complexity added only when users are ready
- **Playground to Production**: Start with a toy, end with a tool

### Language Positioning

| Language | Strengths | Ipp Advantage |
|----------|-----------|----------------|
| Lua | Fast, embeddable, simple | Python-like syntax, more features |
| Python | Easy, readable, versatile | Game-specific optimizations, better performance |
| C# | Powerful, tooling | Simpler, faster iteration, lighter runtime |

### Why Ipp for Game Scripting

- Embedded by design for game engines
- Minimal overhead (interpreter < 500KB)
- 60 FPS target from v1.0.0
- Clean integration with C/C++/Rust runtimes

---

## 2. Language Design

### v0.1.0 Design (Foundation)

**Syntax Style**: Python-like (indentation-based)

```ipp
# Comments start with #
var x = 10           # Variable declaration
let y = "hello"      # Immutable binding
func add(a, b) {     # Function definition
    return a + b
}

if x > 5 {           # Control flow
    print("big")
} else {
    print("small")
}

for i in 0..10 {     # Range-based loop
    print(i)
}
```

**Type System**: Dynamic typing initially

- Numbers (64-bit float)
- Strings
- Booleans
- Lists (dynamic arrays)
- Tables (dictionaries/maps)
- Functions (first-class)
- Nil

**Memory Model**: Simple GC (reference counting + mark-sweep)

**Error Handling**: Stack traces with line numbers

### Evolution Path

| Version | Typing | Memory | Syntax |
|---------|--------|--------|--------|
| v0.1.x | Dynamic | Simple GC | Minimal |
| v1.x | Dynamic + optional static | Optimized GC | Modules |
| v2.x | Gradual typing | Custom allocators | FFI syntax |
| v3.x | Full optional | Tracing GC | Advanced patterns |

---

## 3. Core Features by Version

### v0.1.0 - Foundation (MVP)

- Variable declaration (`var`, `let`)
- Basic types: number, string, bool, nil, list, table
- Arithmetic operators: `+`, `-`, `*`, `/`, `%`, `^`
- Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Logical: `and`, `or`, `not`
- Control flow: `if/elif/else`, `for`, `while`
- Functions: declaration, call, closures
- Basic standard library: `print()`, `len()`, `type()`
- Error handling with stack traces

### v0.2.0 - Polish

- Enhanced standard library
- Better error messages
- Module basics (import)
- String operations
- List/table built-in methods

### v0.3.0 - Stability

- Performance improvements
- Standard library expansion
- Basic profiling hooks
- Bug fixes and edge cases

### v1.0.0 - Stable Release

- Module system with proper imports
- Package management basics
- Game helper utilities (vectors, transforms)
- File I/O
- Improved debugging
- Stable API for embedding

### v1.1.0 - Ecosystem

- Standard library completeness
- Documentation tools
- CLI enhancements

### v2.0.0 - Performance Expansion

- C extension support (ffi)
- Rust runtime components
- Bytecode compilation
- Performance benchmarks
- Profiler integration

### v2.1.0 - Native Power

- FFI full feature set
- Native module loading
- Performance tuning

### v3.0.0 - World-Class

- JIT compilation (optional)
- AOT compilation options
- Advanced runtime optimizations
- Production tooling
- Full LSP support

---

## 4. Performance Strategy

### Execution Model Evolution

```
v0.1.x:  Pure Interpreter (RPython)
    ↓
v1.x:   Interpreter + Bytecode Cache
    ↓
v2.x:   Bytecode VM + Native Extensions
    ↓
v3.x:   Hybrid: Interpreter/JIT/AOT
```

### Performance Targets

| Version | Target | Method |
|---------|--------|--------|
| v0.1.x | Correctness | RPython interpreter |
| v1.0.x | 30+ FPS | Bytecode caching, basic optimization |
| v2.0.x | 60 FPS | Native extensions, bytecode VM |
| v3.0.x | 60+ FPS | JIT, advanced optimization |

### Optimization Roadmap

1. **v0.x**: Focus on correctness, not speed
2. **v1.0**: Bytecode generation, function call optimization
3. **v2.0**: Native extension overhead, inline caching
4. **v3.0**: JIT hot-path optimization, type inference

### Safety Rules

- Never optimize prematurely
- Benchmark before every optimization
- Maintain correctness over speed

---

## 5. Python 3.x Implementation Plan

**Note**: Using standard Python 3.x for the interpreter - easier to develop, debug, and learn. RPython can be considered later for performance translation.

### Architecture Overview

```
Source Code
    ↓
[Lexer] → Tokens
    ↓
[Parser] → AST
    ↓
[AST Transformer] → Optimized AST
    ↓
[Interpreter] → Execution
    ↓
[Runtime] → Native Operations
```

### Component Design

#### Lexer (Tokenization)

```
Input: "var x = 10"
Output: [VAR, IDENTIFIER("x"), EQUAL, NUMBER(10)]
```

- Single-pass scanning
- Line/column tracking for error messages
- Unicode support

#### Parser (AST Generation)

```
Input: Tokens
Output: AST nodes (program, statements, expressions)
```

- Recursive descent parser
- Operator precedence handling
- Error recovery

#### AST Node Types

```
Expression:
  - NumberLiteral
  - StringLiteral
  - BooleanLiteral
  - Identifier
  - BinaryExpr
  - UnaryExpr
  - CallExpr
  - IndexExpr

Statement:
  - VarDecl
  - LetDecl
  - FunctionDecl
  - IfStmt
  - ForStmt
  - WhileStmt
  - ReturnStmt
  - ExprStmt
```

#### Interpreter

- Tree-walk execution
- Environment-based scoping
- GC integration

### Directory Structure (Implementation)

```
ipp/
├── lexer/
│   ├── __init__.py
│   ├── token.py
│   └── lexer.py
├── parser/
│   ├── __init__.py
│   ├── ast.py
│   └── parser.py
├── interpreter/
│   ├── __init__.py
│   ├── evaluator.py
│   └── environment.py
├── runtime/
│   ├── __init__.py
│   ├── builtins.py
│   └── gc.py
├── vm/
│   └── bytecode.py      # v2.x addition
└── main.py
```

---

## 6. Compilation Strategy

### Bytecode Introduction (v2.x)

```
AST → Bytecode Compiler → Bytecode → VM → Execution
```

**Bytecode Design**:

- Stack-based (simple, fast)
- Fixed-width opcodes (1 byte)
- Immediate operands for constants

**Instruction Set**:

```
LOAD_CONST    # Load constant to stack
LOAD_VAR      # Load variable to stack
STORE_VAR     # Store stack top to variable
CALL          # Call function
RETURN        # Return from function
JUMP          # Unconditional jump
JUMP_IF_FALSE # Conditional jump
BINARY_OP     # Binary operation
```

### JIT/AOT Concepts (v3.x)

**JIT Strategy**:

- Trace hot paths
- Generate optimized machine code
- Deoptimization fallback

**AOT Strategy**:

- Compile to C intermediate
- Use existing C compilers
- Static binary output

---

## 7. Native Extensions (v2.0)

### C Extension Design

```c
// ipp_module.h
#include <ipp.h>

IPP_EXPORT int ipp_load_module(ipp_vm* vm) {
    ipp_register_function(vm, "hello", hello_func);
    return 0;
}
```

### Rust Integration

```rust
use ipp::vm::{VM, Value};

#[ipp_function]
fn rust_math(x: f64, y: f64) -> f64 {
    x * y + 42.0
}
```

### FFI Interface

```ipp
import "c:math" as math

var result = math.sin(3.14159)
```

---

## 8. Game Engine Integration

### Embedding API

```c
#include <ipp/ipp.h>

int main() {
    ipp_vm* vm = ipp_vm_new();
    
    // Register game functions
    ipp_register_func(vm, "print", game_print);
    ipp_register_func(vm, "update", game_update);
    
    // Load and run script
    ipp_load_file(vm, "game.ipp");
    ipp_run(vm);
    
    // Game loop integration
    while (running) {
        ipp_call(vm, "update", ipp_number(delta_time));
    }
    
    ipp_vm_free(vm);
}
```

### Game Loop Interaction

- Scripts run per-frame via callback
- Event system for input handling
- Entity/component access through builtins

### Event System Basics

```ipp
# Event handlers
on_key_press("space", func() {
    player.jump()
})

on_collision("player", "enemy", func() {
    game.over()
})
```

---

## 9. Tooling Evolution

### v0.x - Basic CLI

```
ipp run <file>      # Run script
ipp check <file>    # Syntax check
ipp --help          # Help
```

### v1.x - Debugging

- Better error messages with context
- REPL with history
- Basic profiler

### v2.x - Profiler

- Function timing
- Memory profiling
- Bytecode inspection

### v3.x - Full Ecosystem

- LSP server
- Package manager
- IDE plugins
- Debugger with breakpoints

---

## 10. Repository Structure

```
ipp/
├── LICENSE
├── README.md
├── roadmap.md
├── SPEC.md
├── docs/
│   ├── getting-started.md
│   ├── language-reference.md
│   └── api/
├── src/
│   ├── ipp/
│   │   ├── __init__.py
│   │   ├── lexer/
│   │   ├── parser/
│   │   ├── interpreter/
│   │   ├── runtime/
│   │   └── vm/
│   └── ippc/           # Compiler tools (v2.x)
├── tests/
│   ├── lexer/
│   ├── parser/
│   ├── interpreter/
│   └── integration/
├── examples/
│   ├── hello_world.ipp
│   ├── game_basic.ipp
│   └── ...
├── scripts/
│   ├── benchmark.py
│   └── ...
├── tools/
│   └── debug/
└── SPEC.md
```

---

## 11. Milestones & Timeline

### Phase 1: Foundation (v0.1.0)

**Goal**: Working interpreter with minimal feature set

**Timeline**: 4-6 weeks

**Deliverables**:

- [ ] Lexer implementation
- [ ] Parser implementation
- [ ] AST definitions
- [ ] Interpreter (basic)
- [ ] Core types: number, string, bool, nil
- [ ] Variables and bindings
- [ ] Basic arithmetic/logic
- [ ] Control flow (if, for, while)
- [ ] Functions with closures
- [ ] Basic standard library
- [ ] 10+ test cases
- [ ] README and documentation

**Success Criteria**: Can run simple game scripts at 10+ FPS

### Phase 2: Polish (v0.2.0 - v0.3.0)

**Goal**: Stable, usable interpreter

**Timeline**: 4-8 weeks

**Deliverables**:

- [ ] Enhanced standard library
- [ ] Module/import system
- [ ] Better error messages
- [ ] GC improvements
- [ ] Performance baseline
- [ ] More tests

**Success Criteria**: 20+ FPS for typical game scripts

### Phase 3: Stable (v1.0.0)

**Goal**: Production-ready for small games

**Timeline**: 6-10 weeks

**Deliverables**:

- [ ] Complete module system
- [ ] Package management
- [ ] Game helper libraries
- [ ] Embedding API stability
- [ ] Debugging tools
- [ ] Performance optimization
- [ ] Documentation

**Success Criteria**: 30+ FPS, suitable for indie games

### Phase 4: Performance (v2.0.0)

**Goal**: 60 FPS target achieved

**Timeline**: 8-12 weeks

**Deliverables**:

- [ ] Bytecode compiler
- [ ] VM implementation
- [ ] C extensions
- [ ] Rust runtime components
- [ ] FFI system
- [ ] Profiler

**Success Criteria**: 60 FPS for complex game scripts

### Phase 5: World-Class (v3.0.0)

**Goal**: Industry-grade language

**Timeline**: 12-16 weeks

**Deliverables**:

- [ ] JIT compiler
- [ ] AOT compilation
- [ ] Advanced optimizations
- [ ] Full LSP support
- [ ] Package ecosystem
- [ ] Production tooling

**Success Criteria**: Competitive with Lua for game scripting

---

## 12. Risks & Challenges

### Over-Engineering Early

**Risk**: Adding features too early that complicate the design

**Mitigation**:

- Strict version scope enforcement
- Feature freeze periods
- Simple-first code review

### Performance Bottlenecks

**Risk**: Interpreter too slow for game development

**Mitigation**:

- Plan bytecode early
- Profile continuously
- Accept lower FPS in early versions

### Complexity Creep

**Risk**: Language becomes too complex to learn

**Mitigation**:

- Always test on beginners
- Separate core from advanced features
- Clear deprecation path

### Scope Expansion

**Risk**: Trying to be too general (non-game uses)

**Mitigation**:

- Game-specific features prioritized
- Reject features that don't serve game dev

### Tooling Neglect

**Risk**: Focus on language, ignore developer experience

**Mitigation**:

- CLI first
- Early error message investment
- Plan tooling in each version

---

## Appendix: Version Compatibility Notes

- v0.1.x scripts should run on v1.x+ (backward compatibility goal)
- Syntax changes must be announced 2 versions ahead
- Breaking changes only in major version bumps
- Every version must pass existing test suite

---

*Last Updated: 2026-03-24*
*Version: 0.1.0-draft*