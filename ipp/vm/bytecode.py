from enum import IntEnum


class OpCode(IntEnum):
    CONSTANT = 0
    NIL = 1
    TRUE = 2
    FALSE = 3
    
    POP = 4
    
    DUP = 5
    SWAP = 6
    
    GET_GLOBAL = 7
    SET_GLOBAL = 8
    GET_LOCAL = 9
    SET_LOCAL = 10
    GET_UPVALUE = 11
    SET_UPVALUE = 12
    
    GET_PROPERTY = 13
    SET_PROPERTY = 14
    GET_INDEX = 15
    SET_INDEX = 16
    
    JUMP = 17
    JUMP_IF_FALSE = 18
    JUMP_IF_TRUE = 19
    LOOP = 20
    
    CALL = 21
    INVOKE = 22
    SUPER_INVOKE = 23
    
    CLOSURE = 24
    CLOSE_UPVALUE = 25
    
    RETURN = 26
    RETURN_VAL = 27
    
    CLASS = 28
    METHOD = 29
    
    IMPORT = 30
    
    ADD = 31
    SUBTRACT = 32
    MULTIPLY = 33
    DIVIDE = 34
    MODULO = 35
    POWER = 36
    
    NEGATE = 37
    NOT = 38
    
    EQUAL = 39
    NOT_EQUAL = 40
    GREATER = 41
    GREATER_EQUAL = 42
    LESS = 43
    LESS_EQUAL = 44
    
    CONCATENATE = 45
    RANGE = 46
    
    LIST = 47
    DICT = 48
    
    HALT = 99


class Chunk:
    def __init__(self):
        self.code = []
        self.constants = []
        self.lines = []
    
    def write(self, opcode, line):
        self.code.append(opcode)
        self.lines.append(line)
    
    def add_constant(self, value, line):
        self.constants.append(value)
        self.write(OpCode.CONSTANT, line)
        self.write(len(self.constants) - 1, line)
    
    def patch_jump(self, offset, target):
        jump = target - offset - 2
        if jump < 0:
            raise RuntimeError("Invalid jump offset")
        self.code[offset] = jump & 0xFF
    
    def __repr__(self):
        lines = []
        for i, opcode in enumerate(self.code):
            lines.append(f"{i:04d}: {OpCode(opcode).name}")
        return "\n".join(lines)