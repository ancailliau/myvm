struct myvm_vm {
  unsigned int  fp; // frame pointer
    signed int  sp; // stack pointer
  unsigned int  ip; // instruction pointer
  unsigned int hlt; // halt register
  
    signed int *sb; // stack base pointer
    signed int  sl; // stack limit
    signed int *gb; // global area pointer
    signed int *lb; // literal area pointer
  
           int *code;
           int code_len;
};

int myvm_init(struct myvm_vm *vm);
void myvm_dispose(struct myvm_vm *vm);
void myvm_stack_push(struct myvm_vm *vm, int value);
int myvm_run(struct myvm_vm *vm);

#define INIT_STACK_SIZE 10
#define FRAME_HEADER_SIZE 4

#define OPCODE_MASK   0xFF000000
#define OPCODE_OFFSET 24

#define ARG0_MASK      0x00FFFFFF
#define ARG_LEFT_MASK  0x00FFF000
#define ARG_RIGHT_MASK 0x00000FFF

#define get_opcode(instr) (instr & OPCODE_MASK) >> OPCODE_OFFSET
#define get_arg0(instr) (instr & ARG0_MASK)
#define get_arg_left(instr) (instr & ARG_LEFT_MASK) >> 12
#define get_arg_right(instr) (instr & ARG_RIGHT_MASK)

#define HLT      0x00
                 
#define ADD      0x01
#define SUB      0x02
#define MLT      0x03
#define DIV      0x04
#define MOD      0x05
#define MINUS    0x06
#define AND      0x07
#define OR       0x08
#define NOT      0x09
#define LT       0x0A
#define GT       0x0B
#define EQ       0x0C
#define LEQ      0x0D
#define GEQ      0x0E
#define NEQ      0x0F

#define PUSHC    0x10
#define POP      0x11
#define SWAP     0x12
#define DUP      0x13

#define GETGLOB  0x14
#define SETGLOB  0x15
#define GETLIT   0x16

#define MKVEC    0x17
#define VREF     0x18
#define VSET     0x19

#define JMP      0x1A
#define JEQ      0x1B
#define JNE      0x1C

#define GETLOCAL 0x1D
#define SETLOCAL 0x1E
#define GETPARAM 0x1F

#define SAVE     0x20
#define FRAME    0x21
#define CALL     0x22
#define RETV     0x23
#define RET      0x24

#define SAY      0x25

void myvm_hlt      (int instr, struct myvm_vm *vm);

void myvm_add      (struct myvm_vm *vm);
void myvm_sub      (struct myvm_vm *vm);
void myvm_mlt      (struct myvm_vm *vm);
void myvm_div      (struct myvm_vm *vm);
void myvm_mod      (struct myvm_vm *vm);
void myvm_minus    (struct myvm_vm *vm);
void myvm_and      (struct myvm_vm *vm);
void myvm_or       (struct myvm_vm *vm);
void myvm_not      (struct myvm_vm *vm);
void myvm_lt       (struct myvm_vm *vm);
void myvm_gt       (struct myvm_vm *vm);
void myvm_eq       (struct myvm_vm *vm);
void myvm_leq      (struct myvm_vm *vm);
void myvm_geq      (struct myvm_vm *vm);
void myvm_neq      (struct myvm_vm *vm);
                   
void myvm_pushc    (int value, struct myvm_vm *vm);
void myvm_pop      (struct myvm_vm *vm);
void myvm_swap     (struct myvm_vm *vm);
void myvm_dup      (struct myvm_vm *vm);

void myvm_getglob  (int val, struct myvm_vm *vm);
void myvm_setglob  (int val, struct myvm_vm *vm);
void myvm_getlit   (int val, struct myvm_vm *vm);

void myvm_mkvec    (int val, struct myvm_vm *vm);
void myvm_vref     (int val, struct myvm_vm *vm);
void myvm_vset     (int val, struct myvm_vm *vm);

void myvm_jmp      (struct myvm_vm *vm);
void myvm_jeq      (struct myvm_vm *vm);
void myvm_jne      (struct myvm_vm *vm);

void myvm_getlocal (int val, struct myvm_vm *vm);
void myvm_setlocal (int val, struct myvm_vm *vm);
void myvm_getparam (int val, struct myvm_vm *vm);

void myvm_save     (int local, int param, struct myvm_vm *vm);
void myvm_frame    (int local, int param, struct myvm_vm *vm);
void myvm_call     (int val, struct myvm_vm *vm);
void myvm_retv     (struct myvm_vm *vm);
void myvm_ret      (struct myvm_vm *vm);

void myvm_say      (struct myvm_vm *vm);