import math
import random
import json


def ipp_print(*args):
    output = []
    for arg in args:
        if arg is None:
            output.append("nil")
        elif isinstance(arg, bool):
            output.append("true" if arg else "false")
        elif isinstance(arg, float):
            if arg.is_integer():
                output.append(str(int(arg)))
            else:
                output.append(str(arg))
        elif isinstance(arg, (list, tuple)):
            output.append(str(arg))
        else:
            output.append(str(arg))
    print(" ".join(output))
    return None


def ipp_len(obj):
    if isinstance(obj, (list, tuple, str)):
        return len(obj)
    if hasattr(obj, 'elements'):
        return len(obj.elements)
    if hasattr(obj, '__len__'):
        return len(obj)
    raise RuntimeError(f"Cannot get length of {type(obj)}")


def ipp_type(obj):
    if obj is None:
        return "nil"
    if isinstance(obj, bool):
        return "bool"
    if isinstance(obj, int):
        return "number"
    if isinstance(obj, float):
        return "number"
    if isinstance(obj, str):
        return "string"
    if isinstance(obj, (list, tuple)):
        return "list"
    if isinstance(obj, dict):
        return "dict"
    if callable(obj):
        return "function"
    return "unknown"


def ipp_to_number(value):
    try:
        return float(value)
    except (ValueError, TypeError):
        return None


def ipp_to_string(value):
    if value is None:
        return "nil"
    if isinstance(value, bool):
        return "true" if value else "false"
    return str(value)


def ipp_abs(n):
    return abs(n)


def ipp_min(*args):
    if not args:
        raise RuntimeError("min requires at least one argument")
    return min(args)


def ipp_max(*args):
    if not args:
        raise RuntimeError("max requires at least one argument")
    return max(args)


def ipp_range(start, end=None, step=1):
    if end is None:
        return list(range(start))
    return list(range(start, end, step))


def ipp_random():
    return random.random()


def ipp_randint(min_val, max_val):
    return random.randint(int(min_val), int(max_val))


def ipp_round(n):
    return round(n)


def ipp_floor(n):
    return math.floor(n)


def ipp_ceil(n):
    return math.ceil(n)


def ipp_sqrt(n):
    return math.sqrt(n)


def ipp_pow(base, exp):
    return base ** exp


def ipp_sin(n):
    return math.sin(n)


def ipp_cos(n):
    return math.cos(n)


def ipp_tan(n):
    return math.tan(n)


def ipp_input(prompt=""):
    return input(prompt)


def ipp_exit(code=0):
    exit(code)


def ipp_keys(d):
    if not isinstance(d, dict):
        raise RuntimeError("keys requires a dict")
    return list(d.keys())


def ipp_values(d):
    if not isinstance(d, dict):
        raise RuntimeError("values requires a dict")
    return list(d.values())


def ipp_items(d):
    if not isinstance(d, dict):
        raise RuntimeError("items requires a dict")
    return list(d.items())


def ipp_has_key(d, key):
    return key in d


BUILTINS = {
    "print": ipp_print,
    "len": ipp_len,
    "type": ipp_type,
    "to_number": ipp_to_number,
    "to_string": ipp_to_string,
    "abs": ipp_abs,
    "min": ipp_min,
    "max": ipp_max,
    "range": ipp_range,
    "random": ipp_random,
    "randint": ipp_randint,
    "round": ipp_round,
    "floor": ipp_floor,
    "ceil": ipp_ceil,
    "sqrt": ipp_sqrt,
    "pow": ipp_pow,
    "sin": ipp_sin,
    "cos": ipp_cos,
    "tan": ipp_tan,
    "input": ipp_input,
    "exit": ipp_exit,
    "keys": ipp_keys,
    "values": ipp_values,
    "items": ipp_items,
    "has_key": ipp_has_key,
}