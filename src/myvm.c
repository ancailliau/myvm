#include <stdio.h>
#include <stdlib.h>
#include "myvm.h"

int myvm_init(struct myvm_vm *vm)
{
  vm->fp =  0;
  vm->sp = -1;
  vm->ip =  0;
  vm->hlt = 0;
  
  vm->code_len = 0;
  
  vm->sb = malloc(INIT_STACK_SIZE * sizeof(int));
  if (vm->sb == NULL) {
    printf("Unable to allocate data stack");
    return 1;
  }
  
  vm->sl = 10;
  
  return 0;
}

void myvm_dispose(struct myvm_vm *vm)
{
  free(vm->sb);
}

void myvm_stack_push(struct myvm_vm *vm, int value)
{
  int *ptr;
  if (vm->sp >= vm->sl) {
    fprintf(stderr, "Stack overflow");
    vm->hlt = 1;
  }
  vm->sp++;
  ptr = (vm->sb + vm->sp);
  *ptr = value;
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
}

void myvm_sub(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) - *(vm->sb + vm->sp + 1);
}

void myvm_mlt(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) * *(vm->sb + vm->sp + 1);
}

void myvm_div(struct myvm_vm *vm)
{
  if (*(vm->sb + vm->sp) == 0) {
    printf("Cannot div by 0");
    vm->hlt = 1;
  }
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) / *(vm->sb + vm->sp + 1);
}

void myvm_mod(struct myvm_vm *vm)
{
  if (*(vm->sb + vm->sp) == 0) {
    printf("Cannot mod by 0");
    vm->hlt = 1;
  }
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) % *(vm->sb + vm->sp + 1);
}

void myvm_minus(struct myvm_vm *vm)
{
  *(vm->sb + vm->sp) = - *(vm->sb + vm->sp);
}

void myvm_and(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) && *(vm->sb + vm->sp + 1);
}

void myvm_or(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) || *(vm->sb + vm->sp + 1);
}

void myvm_not(struct myvm_vm *vm)
{
  if (*(vm->sb + vm->sp))
    *(vm->sb + vm->sp) = 0;
  else
    *(vm->sb + vm->sp) = 1;
}

void myvm_lt(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) < *(vm->sb + vm->sp + 1);
}

void myvm_gt(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) > *(vm->sb + vm->sp + 1);
}

void myvm_eq(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) == *(vm->sb + vm->sp + 1);
}

void myvm_leq(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) <= *(vm->sb + vm->sp + 1);
}

void myvm_geq(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) >= *(vm->sb + vm->sp + 1);
}

void myvm_neq(struct myvm_vm *vm)
{
  vm->sp--;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp) != *(vm->sb + vm->sp + 1);
}

void myvm_pushc(int val, struct myvm_vm *vm)
{
  myvm_stack_push(vm, val);
}

void myvm_pop(struct myvm_vm *vm)
{
  vm->sp--;
}

void myvm_swap(struct myvm_vm *vm)
{
  int value = *(vm->sb + vm->sp - 1);
  *(vm->sb + vm->sp - 1) = *(vm->sb + vm->sp);
  *(vm->sb + vm->sp) = value;
}

void myvm_dup(struct myvm_vm *vm)
{
  vm->sp++;
  *(vm->sb + vm->sp) = *(vm->sb + vm->sp - 1);
}

void myvm_getglob(int val, struct myvm_vm *vm)
{
}

void myvm_setglob(int val, struct myvm_vm *vm)
{
}

void myvm_getlit(int val, struct myvm_vm *vm)
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

void myvm_jmp(struct myvm_vm *vm)
{
}

void myvm_jeq(struct myvm_vm *vm)
{
}

void myvm_jne(struct myvm_vm *vm)
{
}

void myvm_getlocal(int val, struct myvm_vm *vm)
{
}

void myvm_setlocal(int val, struct myvm_vm *vm)
{
}

void myvm_getparam(int val, struct myvm_vm *vm)
{
}

void myvm_save(int local, int param, struct myvm_vm *vm)
{
}

void myvm_frame(int local, int param, struct myvm_vm *vm)
{
}

void myvm_call(int val, struct myvm_vm *vm)
{
}

void myvm_reti(struct myvm_vm *vm)
{
}

void myvm_retb(struct myvm_vm *vm)
{
}

void myvm_retv(struct myvm_vm *vm)
{
}

void myvm_ret(struct myvm_vm *vm)
{
}

void myvm_say(struct myvm_vm *vm)
{
  printf("%i", *(vm->sb + vm->sp));
}
