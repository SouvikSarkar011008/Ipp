#!/usr/bin/env python3
"""
Setup for Ipp C Extension
v2.0.0 - C Extension VM for performance
"""

from setuptools import setup, Extension

setup(
    name="ippc",
    version="2.0.0",
    description="Ipp C Extension - High performance VM",
    author="Ipp Team",
    ext_modules=[
        Extension(
            "ippc",
            sources=["src/ippc/vm.c"],
            include_dirs=["src/ippc"],
        )
    ],
)