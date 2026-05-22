# v1.7.9.1.9 — Web playground bundle verification
import os, pathlib

root = pathlib.Path(__file__).parent.parent.parent  # repo root
bundle = root / "web-playground" / "ipp-bundle.js"
index  = root / "web-playground" / "index.html"

# Bundle file must exist
assert bundle.exists(), f"ipp-bundle.js not found at {bundle}"

# Bundle must contain base64 for key Ipp modules
text = bundle.read_text(encoding='utf-8')
assert "ipp/lexer/lexer.py" in text,     "lexer missing from bundle"
assert "ipp/parser/parser.py" in text,   "parser missing from bundle"
assert "ipp/interpreter/interpreter.py" in text, "interpreter missing from bundle"
assert "ipp/runtime/builtins.py" in text, "builtins missing from bundle"
assert "IPP_BUNDLE" in text,             "IPP_BUNDLE export missing"

# index.html must reference the bundle
html = index.read_text(encoding='utf-8')
assert "ipp-bundle.js" in html,          "ipp-bundle.js not loaded in index.html"
assert "micropip" in html,               "micropip strategy missing"
assert "Strategy 0" in html,             "Strategy 0 (bundle) missing"
assert "switchTab" in html,              "switchTab missing"

# Playground must auto-switch to console on run
assert "switchTab('console'" in html, "runCode must switch to console tab"

print("v1.7.9.1.9 playground bundle tests passed")
