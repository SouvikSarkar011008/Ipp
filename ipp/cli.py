#!/usr/bin/env python3
"""CLI entry point for ipp-lang package."""

import sys
import os

def main():
    """Main CLI entry point."""
    # Add the package directory to path
    ipp_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if ipp_dir not in sys.path:
        sys.path.insert(0, ipp_dir)
    
    # Import and run main
    from ipp.main import cli
    cli()

if __name__ == "__main__":
    main()
