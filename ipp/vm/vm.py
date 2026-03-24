from .bytecode import Chunk, OpCode


class VM:
    def __init__(self, chunk: Chunk):
        self.chunk = chunk
        self.stack = []
        self.ip = 0
    
    def run(self):
        while self.ip < len(self.chunk.code):
            opcode = self.chunk.code[self.ip]
            
            if opcode == OpCode.HALT:
                break
            elif opcode == OpCode.CONSTANT:
                self.ip += 1
                idx = self.chunk.code[self.ip]
                self.stack.append(self.chunk.constants[idx])
            elif opcode == OpCode.NIL:
                self.stack.append(None)
            elif opcode == OpCode.TRUE:
                self.stack.append(True)
            elif opcode == OpCode.FALSE:
                self.stack.append(False)
            elif opcode == OpCode.POP:
                self.stack.pop()
            elif opcode == OpCode.ADD:
                b = self.stack.pop()
                a = self.stack.pop()
                if isinstance(a, (int, float)) and isinstance(b, (int, float)):
                    self.stack.append(a + b)
                elif isinstance(a, str) and isinstance(b, str):
                    self.stack.append(a + b)
            elif opcode == OpCode.SUBTRACT:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a - b)
            elif opcode == OpCode.MULTIPLY:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a * b)
            elif opcode == OpCode.DIVIDE:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a / b)
            elif opcode == OpCode.NEGATE:
                a = self.stack.pop()
                self.stack.append(-a)
            elif opcode == OpCode.NOT:
                a = self.stack.pop()
                self.stack.append(not a)
            elif opcode == OpCode.EQUAL:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a == b)
            elif opcode == OpCode.NOT_EQUAL:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a != b)
            elif opcode == OpCode.LESS:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a < b)
            elif opcode == OpCode.GREATER:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a > b)
            elif opcode == OpCode.LESS_EQUAL:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a <= b)
            elif opcode == OpCode.GREATER_EQUAL:
                b = self.stack.pop()
                a = self.stack.pop()
                self.stack.append(a >= b)
            elif opcode == OpCode.GET_GLOBAL:
                self.ip += 1
                idx = self.chunk.code[self.ip]
                name = self.chunk.constants[idx]
                self.stack.append(f"<global:{name}>")
            elif opcode == OpCode.LIST:
                count = self.stack.pop()
                items = []
                for _ in range(count):
                    items.insert(0, self.stack.pop())
                self.stack.append(items)
            elif opcode == OpCode.DICT:
                count = self.stack.pop()
                d = {}
                for _ in range(count):
                    value = self.stack.pop()
                    key = self.stack.pop()
                    d[key] = value
                self.stack.append(d)
            elif opcode == OpCode.RETURN_VAL:
                return self.stack[-1] if self.stack else None
            elif opcode == OpCode.RETURN:
                return None
            else:
                print(f"Unknown opcode: {opcode}")
                break
            
            self.ip += 1
        
        return None


def execute_bytecode(chunk: Chunk):
    vm = VM(chunk)
    return vm.run()