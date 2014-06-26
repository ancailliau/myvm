#include <stdio.h>
#include <stdlib.h>
#include "myvm.h"

int myvm_init (struct myvm_vm *vm, int global_size, int literal_size)
{
  vm->fp = -1;
  vm->sp = -1;
  vm->ip =  0;
  vm->hlt = 0;
  
  vm->code_len = 0;
  
  vm->sb = malloc(INIT_STACK_SIZE * sizeof(int));
  if (vm->sb == NULL) {
    printf("Unable to allocate data stack");
    return 1;
  }
  
  vm->sl = 20;
  
  vm->gb = malloc(global_size * sizeof(int));
  if (vm->gb == NULL) {
    printf("Unable to allocate global area");
    return 1;
  }
  
  vm->lb = malloc(literal_size * sizeof(char));
  if (vm->lb == NULL) {
    printf("Unable to allocate literal area");
    return 1;
  }
  
  return 0;
}

void myvm_dispose(struct myvm_vm *vm)
{
  free(vm->sb);
  free(vm->gb);
  free(vm->lb);
}

void myvm_stack_push(struct myvm_vm *vm, int value)
{
  if (vm->sp >= vm->sl) {
    fprintf(stderr, "Stack overflow %d\n", vm->sp);
    vm->hlt = 1;
  }
  vm->sp++;
  *(vm->sb + vm->sp) = value;
}

int myvm_run(struct myvm_vm *vm)
{
  int i;
  while (vm->hlt == 0) {
    int opcode;
    int instr = vm->code[vm->ip];
    
    opcode = get_opcode(instr);
    
    switch (opcode) {
      case HLT:
        myvm_hlt(instr, vm);
        break;
      case ADD:
        myvm_add(vm);
        break;
      case SUB:
        myvm_sub(vm);
        break;
      case MLT:
        myvm_mlt(vm);
        break;
      case DIV:
        myvm_div(vm);
        break;
      case MOD:
        myvm_mod(vm);
        break;
      case MINUS:
        myvm_minus(vm);
        break;
      case AND:
        myvm_and(vm);
        break;
      case OR:
        myvm_or(vm);
        break;
      case NOT:
        myvm_not(vm);
        break;
      case LT:
        myvm_lt(vm);
        break;
      case GT:
        myvm_gt(vm);
        break;
      case EQ:
        myvm_eq(vm);
        break;
      case LEQ:
        myvm_leq(vm);
        break;
      case GEQ:
        myvm_geq(vm);
        break;
      case NEQ:
        myvm_neq(vm);
        break;
      case PUSHC:
        myvm_pushc(get_arg0(instr), vm);
        break;
      case POP:
        myvm_pop(vm);
        break;
      case SWAP:
        myvm_swap(vm);
        break;
      case DUP:
        myvm_dup(vm);
        break;
      case GETGLOB:
        myvm_getglob(get_arg0(instr), vm);
        break;
      case SETGLOB:
        myvm_setglob(get_arg0(instr), vm);
        break;
      case GETLIT:
        myvm_getlit(get_arg0(instr), vm);
        break;
      case MKVEC:
        myvm_mkvec(get_arg0(instr), vm);
        break;
      case VREF:
        myvm_vref(get_arg0(instr), vm);
        break;
      case VSET:
        myvm_vset(get_arg0(instr), vm);
        break;
      case JMP:
        myvm_jmp(get_arg0(instr), vm);
        break;
      case JEQ:
        myvm_jeq(get_arg0(instr), vm);
        break;
      case JNE:
        myvm_jne(get_arg0(instr), vm);
        break;
      case GETLOCAL:
        myvm_getlocal(get_arg0(instr), vm);
        break;
      case SETLOCAL:
        myvm_setlocal(get_arg0(instr), vm);
        break;
      case GETPARAM:
        myvm_getparam(get_arg0(instr), vm);
        break;
      case SAVE:
        myvm_save(get_arg_left(instr), get_arg_right(instr), vm);
        break;
      case FRAME:
        myvm_frame(get_arg_left(instr), get_arg_right(instr), vm);
        break;
      case CALL:
        myvm_call(get_arg0(instr), vm);
        break;
      case RETV:
        myvm_retv(vm);
        break;
      case RET:
        myvm_ret(vm);
        break;
      case SAY:
        myvm_say(vm);
        break;
      default:
        printf("ERROR\n");
        goto exit;
    }
  }

exit:
  return EXIT_SUCCESS;
}

/* OPCODES */

void myvm_hlt(int instr, struct myvm_vm *vm)
{
  vm->hlt = 1;
}

void myvm_add(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) + *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_sub(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) - *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_mlt(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) * *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_div(struct myvm_vm *vm)
{
  if (*(vm->sb + vm->sp) == 0) {
    printf("Cannot div by 0");
    vm->hlt = 1;
  }
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) / *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_mod(struct myvm_vm *vm)
{
  if (*(vm->sb + vm->sp) == 0) {
    printf("Cannot mod by 0");
    vm->hlt = 1;
  }
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) % *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_minus(struct myvm_vm *vm)
{
  *(vm->sb + vm->sp) = - *(vm->sb + vm->sp);
  vm->ip++;
}

void myvm_and(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) && *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_or(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) || *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_not(struct myvm_vm *vm)
{
  if (*(vm->sb + vm->sp))
    *(vm->sb + vm->sp) = 0;
  else
    *(vm->sb + vm->sp) = 1;
  vm->ip++;
}

void myvm_lt(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) < *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_gt(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) > *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_eq(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) == *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_leq(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) <= *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_geq(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) >= *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_neq(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) != *(vm->sb + vm->sp + 1);
  vm->ip++;
}

void myvm_pushc(int val, struct myvm_vm *vm)
{
  if (vm->sp >= vm->sl) {
    fprintf(stderr, "Stack overflow %d\n", vm->sp);
    vm->hlt = 1;
  }
  
  vm->sp++;  
  *(vm->sb + vm->sp) = val;
  vm->ip++;
}

void myvm_pop(struct myvm_vm *vm)
{
  vm->sp--;
  vm->ip++;
}

void myvm_swap(struct myvm_vm *vm)
{
  int value = *(vm->sb + vm->sp - 1);
  *(vm->sb + vm->sp - 1) = *(vm->sb + vm->sp);
  *(vm->sb + vm->sp) = value;
  vm->ip++;
}

void myvm_dup(struct myvm_vm *vm)
{
  vm->sp++;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp - 1);
  vm->ip++;
}

void myvm_getglob(int n, struct myvm_vm *vm)
{
  vm->sp++;
  *(vm->sb + vm->sp) = *(vm->gb + n);
}

void myvm_setglob(int n, struct myvm_vm *vm)
{
  *(vm->gb + n) = *(vm->sb + vm->sp);
  vm->sp--;
}

void myvm_getlit(int n, struct myvm_vm *vm)
{
}

void myvm_mkvec(int val, struct myvm_vm *vm)
{
}

void myvm_vref(int val, struct myvm_vm *vm)
{
}

void myvm_vset(int val, struct myvm_vm *vm)
{
}

void myvm_jmp(int l, struct myvm_vm *vm)
{
  vm->ip = l;
}

void myvm_jeq(int l, struct myvm_vm *vm)
{
  if (*(vm->sb + vm->sp) > 0)
    vm->ip = l;
  else
    vm->ip++;
}

void myvm_jne(int l, struct myvm_vm *vm)
{
  if (*(vm->sb + vm->sp) == 0)
    vm->ip = l;
  else
    vm->ip++;
}

void myvm_getlocal(int n, struct myvm_vm *vm)
{
  vm->sp++;
  *(vm->sb + vm->sp) = *(vm->sb + vm->fp + FRAME_HEADER_SIZE + n);
}

void myvm_setlocal(int n, struct myvm_vm *vm)
{
  *(vm->sb + vm->fp + FRAME_HEADER_SIZE + n) = *(vm->sb + vm->sp);
  vm->sp--;
}

void myvm_getparam(int n, struct myvm_vm *vm)
{
  int l;
  vm->sp++;
  l = *(vm->sb + vm->fp + 3); 
  *(vm->sb + vm->sp) = *(vm->sb + vm->fp + FRAME_HEADER_SIZE + l + n);
}

void myvm_save(int l, int p, struct myvm_vm *vm)
{
  if ((FRAME_HEADER_SIZE + l + p + vm->sp) >= vm->sl) {
    fprintf(stderr, "Not enough memory to allocate %d\n", 
            FRAME_HEADER_SIZE + l + p + vm->sp);
    vm->hlt = 1;
    return;
  }
  
  vm->sp = vm->sp + FRAME_HEADER_SIZE;
  *(vm->sb + vm->sp) = l;
  *(vm->sb + vm->sp - 1) = p;
  *(vm->sb + vm->sp - 2) = vm->fp;
  vm->sp = vm->sp + l;
}

void myvm_frame(int l, int p, struct myvm_vm *vm)
{
  vm->fp = vm->sp - (FRAME_HEADER_SIZE + l + p) + 1;
}

void myvm_call(int val, struct myvm_vm *vm)
{
  // store next instruction pointer in frame
  *(vm->sb + vm->fp) = vm->ip;
  vm->ip = val;
}

void myvm_retv(struct myvm_vm *vm)
{
  // Store the return value in place of no. params
  *(vm->sb + vm->fp + 2) = *(vm->sb + vm->sp); 
  vm->sp = vm->fp; 
  vm->ip = *(vm->sb + vm->fp);
  // place ret value on top of stack
  *(vm->sb + vm->sp) = *(vm->sb + vm->fp + 2); 
  vm->fp = *(vm->sb + vm->fp + 1);
}

void myvm_ret(struct myvm_vm *vm)
{ 
  vm->sp = vm->fp - 1;
  vm->ip = *(vm->sb + vm->fp);
  vm->fp = *(vm->sb + vm->fp + 1);
}

void myvm_say(struct myvm_vm *vm)
{
  printf("%i", *(vm->sb + vm->sp));
  vm->sp--;
  vm->ip++;
}
