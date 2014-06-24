#include <stdio.h>
#include <stdlib.h>
#include "../../src/myvm.h"

int main(int argc, char *argv[])
{
  int code [] = {
    PUSHC << OPCODE_OFFSET,               // pushc 0      10   0
    SETLOCAL << OPCODE_OFFSET,            // setlocal 0   1E   1
    GETPARAM << OPCODE_OFFSET | 1,        // getparam 1   1F   2
    GETPARAM << OPCODE_OFFSET,            // getparam 0   1F   3
    ADD << OPCODE_OFFSET,                 // add          01   4
    SETLOCAL << OPCODE_OFFSET,            // setlocal 0   1E   5
    GETLOCAL << OPCODE_OFFSET,            // getlocal 0   1D   6
    RETV << OPCODE_OFFSET,                // retv         23   7
    
    SAVE << OPCODE_OFFSET | 1 << 12 | 2,  // save 1 2     20   8
    PUSHC << OPCODE_OFFSET | 1,           // pushc 1      10   9
    PUSHC << OPCODE_OFFSET | 2,           // pushc 2      10   10
    FRAME << OPCODE_OFFSET | 1 << 12 | 2, // frame 1 2    21   11
    CALL << OPCODE_OFFSET,                // call 0       22   12
    
    SAY << OPCODE_OFFSET,                 // say          25   13
    HLT << OPCODE_OFFSET,                 // hlt          00   14
  };
  
  struct myvm_vm vm;
  vm.code = code;
  myvm_init(&vm);
  vm.ip = 8;
  myvm_run(&vm);
  myvm_dispose(&vm);
}