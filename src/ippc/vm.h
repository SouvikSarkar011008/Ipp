/*
 * Ipp C Extension - Core VM header
 * v2.0.0 - C Extension VM for performance
 */

#ifndef IPPC_VM_H
#define IPPC_VM_H

#include <Python.h>
#include <structmember.h>

/* Maximum stack size */
#define IPPC_STACK_MAX 1024
#define IPPC_FRAMES_MAX 256
#define IPPC_GLOBALS_MAX 1024

/* Value types */
typedef enum {
    IPPC_TYPE_NIL = 0,
    IPPC_TYPE_BOOL,
    IPPC_TYPE_NUMBER,
    IPPC_TYPE_STRING,
    IPPC_TYPE_LIST,
    IPPC_TYPE_DICT,
    IPPC_TYPE_FUNCTION,
    IPPC_TYPE_CFUNCTION,
    IPPC_TYPE_CLASS,
    IPPC_TYPE_INSTANCE,
    IPPC_TYPE_MODULE,
} IppType;

/* Forward declarations */
typedef struct IppValue IppValue;
typedef struct IppFrame IppFrame;
typedef struct IppVM IppVM;

/* Value structure */
struct IppValue {
    IppType type;
    union {
        int boolean;
        double number;
        PyObject *object;
    } as;
};

/* Call frame */
struct IppFrame {
    PyObject *function;
    PyObject *closure;
    int ip;
    int stack_base;
    int local_count;
    IppValue *locals;
};

/* Core VM structure */
struct IppVM {
    PyObject_HEAD
    
    /* Stack */
    IppValue stack[IPPC_STACK_MAX];
    int stack_top;
    
    /* Call frames */
    IppFrame frames[IPPC_FRAMES_MAX];
    int frame_count;
    
    /* Global variables */
    PyObject *globals;
    
    /* Builtins */
    PyObject *builtins;
    
    /* State */
    int running;
    int max_depth;
    int call_depth;
    
    /* Last value */
    IppValue last_value;
    
    /* Error handling */
    PyObject *error;
};

/* VM Methods */
static int vm_init(IppVM *self, PyObject *args, PyObject *kwds);
static PyObject *vm_run(IppVM *self, PyObject *args);
static PyObject *vm_push(IppVM *self, PyObject *value);
static PyObject *vm_pop(IppVM *self);
static PyObject *vm_peek(IppVM *self);
static void vm_error(IppVM *self, const char *message);

/* Opcode implementation in C */
static void op_constant(IppVM *vm);
static void op_add(IppVM *vm);
static void op_sub(IppVM *vm);
static void op_mul(IppVM *vm);
static void op_div(IppVM *vm);
static void op_neg(IppVM *vm);
static void op_not(IppVM *vm);
static void op_eq(IppVM *vm);
static void op_lt(IppVM *vm);
static void op_gt(IppVM *vm);
static void op_jump(IppVM *vm, int offset);
static void op_jump_if_false(IppVM *vm, int offset);
static void op_loop(IppVM *vm, int offset);
static void op_get_local(IppVM *vm, int slot);
static void op_set_local(IppVM *vm, int slot);
static void op_get_global(IppVM *vm, PyObject *name);
static void op_set_global(IppVM *vm, PyObject *name);
static void op_call(IppVM *vm, int arg_count);
static void op_return(IppVM *vm);
static void op_closure(IppVM *vm, PyObject *function);
static void op_close(IppVM *vm);
static void op_class(IppVM *vm, PyObject *name);
static void op_method(IppVM *vm, PyObject *name);
static void op_invoke(IppVM *vm, PyObject *method, int arg_count);
static void op_index_get(IppVM *vm);
static void op_index_set(IppVM *vm);

/* Type definitions */
typedef void (*IppOpcode)(IppVM *vm);

extern PyTypeObject IppVMType;

#endif /* IPPC_VM_H */