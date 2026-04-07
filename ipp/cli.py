#!/usr/bin/env python3
"""CLI entry point for ipp-lang package."""

import sys
import os

def main():
    """Main CLI entry point."""
    # The main.py is at the project root level
    project_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if project_root not in sys.path:
        sys.path.insert(0, project_root)
    
    # Import and run the CLI
    from main import cli as ipp_cli
    ipp_cli()

if __name__ == "__main__":
    main()
