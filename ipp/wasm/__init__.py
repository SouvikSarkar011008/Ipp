"""Ipp WASM Backend - compile Ipp to WebAssembly."""

from .compiler import compile_to_wasm, main

__all__ = ["compile_to_wasm", "main"]