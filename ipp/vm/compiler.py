from ..parser.ast import *
from .bytecode import Chunk, OpCode


class Compiler:
    def __init__(self):
        self.chunk = Chunk()
        self.locals = {}
        self.scopes = [self.locals]
    
    def compile(self, node: Program):
        for stmt in node.statements:
            self.compile_stmt(stmt)
        
        self.chunk.write(OpCode.HALT, 0)
        return self.chunk
    
    def compile(self, node: Program):
        for stmt in node.statements:
            self.compile_stmt(stmt)
        
        self.chunk.write(OpCode.RETURN_VAL, 0)
        return self.chunk
    
    def compile_stmt(self, node: ASTNode):
        if isinstance(node, VarDecl):
            self.compile_var_decl(node)
        elif isinstance(node, LetDecl):
            self.compile_var_decl(node, constant=True)
        elif isinstance(node, FunctionDecl):
            self.compile_function(node)
        elif isinstance(node, ClassDecl):
            self.compile_class(node)
        elif isinstance(node, ImportDecl):
            self.compile_import(node)
        elif isinstance(node, ExprStmt):
            self.compile_expr(node.expression)
            self.chunk.write(OpCode.POP, 0)
        elif isinstance(node, IfStmt):
            self.compile_if(node)
        elif isinstance(node, ForStmt):
            self.compile_for(node)
        elif isinstance(node, WhileStmt):
            self.compile_while(node)
        elif isinstance(node, ReturnStmt):
            if node.value:
                self.compile_expr(node.value)
            else:
                self.chunk.write(OpCode.NIL, 0)
            self.chunk.write(OpCode.RETURN_VAL, 0)
        elif isinstance(node, BreakStmt):
            self.chunk.write(OpCode.JUMP, 0)
        elif isinstance(node, ContinueStmt):
            self.chunk.write(OpCode.LOOP, 0)
    
    def compile_var_decl(self, node, constant=False):
        if node.initializer:
            self.compile_expr(node.initializer)
        else:
            self.chunk.write(OpCode.NIL, 0)
        
        self.chunk.write(OpCode.DEFINE_GLOBAL, 0)
    
    def compile_function(self, node: FunctionDecl):
        pass
    
    def compile_class(self, node: ClassDecl):
        pass
    
    def compile_import(self, node: ImportDecl):
        pass
    
    def compile_if(self, node: IfStmt):
        self.compile_expr(node.condition)
        self.chunk.write(OpCode.JUMP_IF_FALSE, 0)
        
        for stmt in node.then_branch:
            self.compile_stmt(stmt)
        
        if node.elif_branches:
            for cond, body in node.elif_branches:
                self.compile_expr(cond)
                self.chunk.write(OpCode.JUMP_IF_FALSE, 0)
                for stmt in body:
                    self.compile_stmt(stmt)
        
        if node.else_branch:
            for stmt in node.else_branch:
                self.compile_stmt(stmt)
    
    def compile_for(self, node: ForStmt):
        self.compile_expr(node.iterator)
        
        for stmt in node.body:
            self.compile_stmt(stmt)
    
    def compile_while(self, node: WhileStmt):
        self.compile_expr(node.condition)
        
        for stmt in node.body:
            self.compile_stmt(stmt)
    
    def compile_expr(self, node: ASTNode):
        if isinstance(node, NumberLiteral):
            self.chunk.add_constant(node.value, 0)
        elif isinstance(node, StringLiteral):
            self.chunk.add_constant(node.value, 0)
        elif isinstance(node, BooleanLiteral):
            self.chunk.write(OpCode.TRUE if node.value else OpCode.FALSE, 0)
        elif isinstance(node, NilLiteral):
            self.chunk.write(OpCode.NIL, 0)
        elif isinstance(node, Identifier):
            self.chunk.write(OpCode.GET_GLOBAL, 0)
            self.chunk.add_constant(node.name, 0)
        elif isinstance(node, BinaryExpr):
            self.compile_binary_expr(node)
        elif isinstance(node, UnaryExpr):
            self.compile_unary_expr(node)
        elif isinstance(node, CallExpr):
            self.compile_call(node)
        elif isinstance(node, GetExpr):
            self.compile_get(node)
        elif isinstance(node, SetExpr):
            self.compile_set(node)
        elif isinstance(node, ListLiteral):
            self.compile_list(node)
        elif isinstance(node, DictLiteral):
            self.compile_dict(node)
    
    def compile_binary_expr(self, node: BinaryExpr):
        self.compile_expr(node.left)
        self.compile_expr(node.right)
        
        if node.operator == "+":
            self.chunk.write(OpCode.ADD, 0)
        elif node.operator == "-":
            self.chunk.write(OpCode.SUBTRACT, 0)
        elif node.operator == "*":
            self.chunk.write(OpCode.MULTIPLY, 0)
        elif node.operator == "/":
            self.chunk.write(OpCode.DIVIDE, 0)
        elif node.operator == "%":
            self.chunk.write(OpCode.MODULO, 0)
        elif node.operator == "^":
            self.chunk.write(OpCode.POWER, 0)
        elif node.operator == "==":
            self.chunk.write(OpCode.EQUAL, 0)
        elif node.operator == "!=":
            self.chunk.write(OpCode.NOT_EQUAL, 0)
        elif node.operator == "<":
            self.chunk.write(OpCode.LESS, 0)
        elif node.operator == ">":
            self.chunk.write(OpCode.GREATER, 0)
        elif node.operator == "<=":
            self.chunk.write(OpCode.LESS_EQUAL, 0)
        elif node.operator == ">=":
            self.chunk.write(OpCode.GREATER_EQUAL, 0)
        elif node.operator == "and":
            self.chunk.write(OpCode.AND, 0)
        elif node.operator == "or":
            self.chunk.write(OpCode.OR, 0)
        elif node.operator == "..":
            self.chunk.write(OpCode.RANGE, 0)
    
    def compile_unary_expr(self, node: UnaryExpr):
        self.compile_expr(node.right)
        
        if node.operator == "-":
            self.chunk.write(OpCode.NEGATE, 0)
        elif node.operator == "not":
            self.chunk.write(OpCode.NOT, 0)
    
    def compile_call(self, node: CallExpr):
        self.compile_expr(node.callee)
        
        for arg in node.arguments:
            self.compile_expr(arg)
        
        self.chunk.write(OpCode.CALL, 0)
        self.chunk.write(len(node.arguments), 0)
    
    def compile_get(self, node: GetExpr):
        self.compile_expr(node.object)
        self.chunk.write(OpCode.GET_PROPERTY, 0)
        self.chunk.add_constant(node.name, 0)
    
    def compile_set(self, node: SetExpr):
        self.compile_expr(node.object)
        self.compile_expr(node.value)
        self.chunk.write(OpCode.SET_PROPERTY, 0)
        self.chunk.add_constant(node.name, 0)
    
    def compile_list(self, node: ListLiteral):
        for elem in node.elements:
            self.compile_expr(elem)
        self.chunk.write(OpCode.LIST, 0)
        self.chunk.write(len(node.elements), 0)
    
    def compile_dict(self, node: DictLiteral):
        for key, value in node.entries:
            self.compile_expr(key)
            self.compile_expr(value)
        self.chunk.write(OpCode.DICT, 0)
        self.chunk.write(len(node.entries), 0)


def compile_ast(ast: Program) -> Chunk:
    compiler = Compiler()
    return compiler.compile(ast)