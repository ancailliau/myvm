#include <stdio.h>
#include <stdlib.h>
#include "myvm.h"

int main(int argc, char *argv[])
{
  char *file;
  FILE *ptr_myfile;
  
  int val1, val2, val3;
  
  struct myvm_vm vm;
  
  myvm_init (&vm);
  
  file = argv[1];
  
  ptr_myfile = fopen(file, "r");
  if (!ptr_myfile) {
    printf("Unable to open file");
    return 1;
  }
  
  fread(&(vm.code_len), sizeof(int), 1, ptr_myfile);
  vm.code = malloc(vm.code_len * sizeof(int));
  for (val1 = 0; val1 < vm.code_len; val1++) {
    fread(&val2, sizeof(int), 1, ptr_myfile);
    vm.code[val1] = val2;
  }
  
  while (vm.hlt == 0) {
    int opcode;
    int instr = vm.code[vm.ip];
    
    opcode = get_opcode(instr);
    vm.ip++;
    
    switch (opcode) {
      case HLT:
        myvm_hlt(instr, &vm);
        break;
      case ADD:
        myvm_add(&vm);
        break;
      case SUB:
        myvm_sub(&vm);
        break;
      case MLT:
        myvm_mlt(instr, &vm);
        break;
      case DIV:
        myvm_div(instr, &vm);
        break;
      case MOD:
        myvm_mod(instr, &vm);
        break;
      case MINUS:
        myvm_minus(instr, &vm);
        break;
      case AND:
        myvm_and(instr, &vm);
        break;
      case OR:
        myvm_or(instr, &vm);
        break;
      case NOT:
        myvm_not(instr, &vm);
        break;
      case LT:
        myvm_lt(instr, &vm);
        break;
      case GT:
        myvm_gt(instr, &vm);
        break;
      case EQ:
        myvm_eq(instr, &vm);
        break;
      case LEQ:
        myvm_leq(instr, &vm);
        break;
      case GEQ:
        myvm_geq(instr, &vm);
        break;
      case NEQ:
        myvm_neq(instr, &vm);
        break;
      case PUSHC:
        myvm_pushc(get_arg0(instr), &vm);
        break;
      case POP:
        myvm_pop(&vm);
        break;
      case SWAP:
        myvm_swap(&vm);
        break;
      case DUP:
        myvm_dup(&vm);
        break;
      case GETGLOB:
        myvm_getglob(instr, &vm);
        break;
      case SETGLOB:
        myvm_setglob(instr, &vm);
        break;
      case GETLIT:
        myvm_getlit(instr, &vm);
        break;
      case MKVEC:
        myvm_mkvec(instr, &vm);
        break;
      case VREF:
        myvm_vref(instr, &vm);
        break;
      case VSET:
        myvm_vset(instr, &vm);
        break;
      case JMP:
        myvm_jmp(instr, &vm);
        break;
      case JEQ:
        myvm_jeq(instr, &vm);
        break;
      case JNE:
        myvm_jne(instr, &vm);
        break;
      case GETLOCAL:
        myvm_getlocal(instr, &vm);
        break;
      case SETLOCAL:
        myvm_setlocal(instr, &vm);
        break;
      case GETPARAM:
        myvm_getparam(instr, &vm);
        break;
      case SAVE:
        myvm_save(instr, &vm);
        break;
      case FRAME:
        myvm_frame(instr, &vm);
        break;
      case CALL:
        myvm_call(instr, &vm);
        break;
      case RETI:
        myvm_reti(instr, &vm);
        break;
      case RETB:
        myvm_retb(instr, &vm);
        break;
      case RETV:
        myvm_retv(instr, &vm);
        break;
      case RET:
        myvm_ret(instr, &vm);
        break;
      case SAY:
        myvm_say(instr, &vm);
        break;
      default:
        printf("ERROR\n");
        goto exit;
    }
  }

exit:
  free(vm.code);
  fclose(ptr_myfile);
  myvm_dispose(&vm);
  
  return EXIT_SUCCESS;
}
