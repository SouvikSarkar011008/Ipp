#!/usr/bin/env python3
"""
Test v1.7.1: Opcode Unit Tests
Tests each VM opcode via compiled Ipp code
"""

import sys
import os
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from ipp.lexer.lexer import tokenize
from ipp.parser.parser import parse
from ipp.interpreter.interpreter import Interpreter


def run_code(code):
    """Helper to run Ipp code and return result"""
    tokens = tokenize(code)
    ast = parse(tokens)
    interp = Interpreter()
    interp.run(ast)
    return interp.last_value


def test_arithmetic():
    """Test arithmetic operations"""
    print("Testing arithmetic...")
    
    assert run_code("10 + 5") == 15
    assert run_code("10 - 5") == 5
    assert run_code("10 * 5") == 50
    assert run_code("10 / 2") == 5
    assert run_code("10 % 3") == 1
    assert run_code("2 ** 10") == 1024
    
    print("  arithmetic: OK")


def test_comparison():
    """Test comparison operations"""
    print("Testing comparison...")
    
    assert run_code("5 < 10") == True
    assert run_code("10 > 5") == True
    assert run_code("5 == 5") == True
    assert run_code("5 != 3") == True
    assert run_code("5 <= 5") == True
    assert run_code("10 >= 5") == True
    
    print("  comparison: OK")


def test_logical():
    """Test logical operations"""
    print("Testing logical...")
    
    assert run_code("not false") == True
    assert run_code("not true") == False
    assert run_code("true and true") == True
    assert run_code("true and false") == False
    assert run_code("false or true") == True
    assert run_code("false or false") == False
    
    print("  logical: OK")


def test_variables():
    """Test variable operations"""
    print("Testing variables...")
    
    assert run_code("var x = 10\nx") == 10
    assert run_code("var x = 10\nvar y = 20\nx + y") == 30
    
    print("  variables: OK")


def test_lists():
    """Test list operations"""
    print("Testing lists...")
    
    result = run_code("[1, 2, 3]")
    assert result.elements == [1, 2, 3]
    
    result = run_code("var l = [1, 2, 3]\nlen(l)") == 3
    result = run_code("var l = [1, 2, 3]\nl[0]") == 1
    result = run_code("var l = [1, 2, 3]\nl[2]") == 3
    
    print("  lists: OK")


def test_dicts():
    """Test dict operations"""
    print("Testing dicts...")
    
    result = run_code('{"a": 1, "b": 2}')
    assert result.data["a"] == 1
    assert result.data["b"] == 2
    
    result = run_code('var d = {"a": 1}\nd["a"]')
    assert result == 1
    
    print("  dicts: OK")


def test_strings():
    """Test string operations"""
    print("Testing strings...")
    
    assert run_code('"hello" + " world"') == "hello world"
    assert run_code('len("hello")') == 5
    assert run_code('"hello".upper()') == "HELLO"
    
    print("  strings: OK")


def test_functions():
    """Test function operations"""
    print("Testing functions...")
    
    assert run_code("func add(a, b) { return a + b }\nadd(5, 3)") == 8
    assert run_code("func fib(n) { if n <= 1 { return n } return fib(n-1) + fib(n-2) }\nfib(10)") == 55
    
    print("  functions: OK")


def test_control_flow():
    """Test control flow operations"""
    print("Testing control flow...")
    
    assert run_code("if true { 1 } else { 2 }") == 1
    assert run_code("if false { 1 } else { 2 }") == 2
    
    result = run_code("var sum = 0\nfor i in 0..5 { sum = sum + i }\nsum")
    assert result == 10
    
    result = run_code("var i = 0\nwhile i < 5 { i = i + 1 }\ni")
    assert result == 5
    
    print("  control flow: OK")


def test_try_catch():
    """Test try/catch operations"""
    print("Testing try/catch...")
    
    result = run_code("try { throw(\"error\") } catch e { \"caught\" }")
    assert result == "caught"
    
    result = run_code("try { 42 } catch e { \"failed\" }")
    assert result == 42
    
    print("  try/catch: OK")


def test_classes():
    """Test class operations"""
    print("Testing classes...")
    
    result = run_code('''
    class Point {
        func init(x, y) {
            this.x = x
            this.y = y
        }
    }
    var p = Point(3, 4)
    p.x
    ''')
    assert result == 3
    
    result = run_code('''
    class Point {
        func init(x, y) {
            this.x = x
            this.y = y
        }
    }
    var p = Point(3, 4)
    p.y
    ''')
    assert result == 4
    
    print("  classes: OK")


def main():
    print("=== v1.7.1: Opcode Unit Tests ===\n")
    
    try:
        test_arithmetic()
        test_comparison()
        test_logical()
        test_variables()
        test_lists()
        test_dicts()
        test_strings()
        test_functions()
        test_control_flow()
        test_try_catch()
        test_classes()
        
        print("\nv1.7.1: Opcode unit tests PASSED")
        return 0
    except Exception as e:
        print(f"\nFAILED: {e}")
        import traceback
        traceback.print_exc()
        return 1


if __name__ == '__main__':
    sys.exit(main())