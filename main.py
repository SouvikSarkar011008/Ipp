#!/usr/bin/env python3
"""
Ipp Language — Thin wrapper around ipp/main.py
All functionality lives in the ipp package.
"""

import sys
import os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from ipp.main import main

if __name__ == '__main__':
    sys.exit(main())
