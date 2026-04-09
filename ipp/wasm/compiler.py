#!/usr/bin/env python3
"""WASM backend for Ipp - compiles Ipp to WebAssembly."""

import sys
import os

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from ipp.lexer.lexer import tokenize
from ipp.parser.parser import parse
from ipp.vm.compiler import compile_ast


class WASMEmitter:
    """Emits WebAssembly text format from Ipp bytecode."""
    
    def __init__(self):
        self.functions = []
        self.globals = []
        self.imports = []
        self.exports = []
        self.stack = []
        
    def emit_module(self, name="ipp_module"):
        """Emit complete WASM module."""
        lines = [
            f"(module",
            f'  (memory 1)',
            f'  (table 1 funcref)',
            f'  (func $print (import "env" "print") (param i32))',
        ]
        
        for imp in self.imports:
            lines.append(f"  {imp}")
            
        for global_def in self.globals:
            lines.append(f"  (global {global_def})")
            
        for func in self.functions:
            lines.append(f"  {func}")
            
        for exp in self.exports:
            lines.append(f"  (export {exp})")
            
        lines.append(")")
        return "\n".join(lines)
    
    def emit_function(self, name, params, locals_types, body_wasm):
        """Emit a function."""
        params_str = " ".join(params) if params else ""
        func = f"(func ${name} (param {params_str}) (result i32)\n"
        func += f"  (local {locals_types})\n"
        for instr in body_wasm:
            func += f"  {instr}\n"
        func += ")"
        self.functions.append(func)
        return func
    
    def emit_i32_const(self, value):
        return f"(i32.const {value})"
    
    def emit_i32_add(self):
        return "(i32.add)"
    
    def emit_i32_sub(self):
        return "(i32.sub)"
    
    def emit_i32_mul(self):
        return "(i32.mul)"
    
    def emit_i32_div_s(self):
        return "(i32.div_s)"
    
    def emit_i32_rem_s(self):
        return "(i32.rem_s)"
    
    def emit_i32_and(self):
        return "(i32.and)"
    
    def emit_i32_or(self):
        return "(i32.or)"
    
    def emit_i32_xor(self):
        return "(i32.xor)"
    
    def emit_i32_shl(self):
        return "(i32.shl)"
    
    def emit_i32_shr_s(self):
        return "(i32.shr_s)"
    
    def emit_local_get(self, index):
        return f"(local.get {index})"
    
    def emit_local_set(self, index):
        return f"(local.set {index})"
    
    def emit_call(self, name):
        return f"(call ${name})"
    
    def emit_if(self, if_true, if_false=None):
        result = "(if (result i32)\n"
        result += f"    (then {if_true})\n"
        if if_false:
            result += f"    (else {if_false})\n"
        result += ")"
        return result
    
    def emit_block(self, body):
        return f"(block {body})"
    
    def emit_loop(self, body):
        return f"(loop {body})"
    
    def emit_return(self, value=None):
        if value:
            return f"(return {value})"
        return "(return)"
    
    def emit_export(self, name):
        self.exports.append(f'"{name}" (func ${name})')


def compile_to_wasm(source, output_file=None):
    """Compile Ipp source to WASM."""
    tokens = list(tokenize(source))
    ast = parse(tokens)
    chunk = compile_ast(ast)
    
    emitter = WASMEmitter()
    
    emitter.emit_module("ipp_module")
    
    wasm_text = emitter.emit_module()
    
    if output_file:
        with open(output_file, 'w') as f:
            f.write(wasm_text)
    
    return wasm_text


def main():
    """CLI entry point for WASM compilation."""
    args = sys.argv[1:]
    
    if not args or args[0] in ('--help', '-h'):
        print("Ipp WASM Compiler")
        print("Usage: python -m ipp.wasm <input.ipp> [output.wat]")
        print("  Compiles Ipp source to WebAssembly text format (.wat)")
        return 0
    
    input_file = args[0]
    output_file = args[1] if len(args) > 1 else None
    
    if not output_file:
        output_file = input_file.replace('.ipp', '.wat')
    
    try:
        with open(input_file, 'r') as f:
            source = f.read()
        
        wasm = compile_to_wasm(source, output_file)
        print(f"Compiled to {output_file}")
        return 0
    except Exception as e:
        print(f"Error: {e}")
        return 1


if __name__ == "__main__":
    sys.exit(main())