#include <stdio.h>
#include <stdlib.h>
#include "myvm.h"

int main(int argc, char *argv[])
{
  char *file;
  FILE *ptr_myfile;
  
  int i, instr, len;
  int *code;
  
  file = argv[1];
  
  ptr_myfile = fopen(file, "r");
  if (!ptr_myfile) {
    printf("Unable to open file");
    return 1;
  }
  
  fread(&len, sizeof(int), 1, ptr_myfile);
  code = malloc(len * sizeof(int));
  for (i = 0; i < len; i++) {
    fread(&instr, sizeof(int), 1, ptr_myfile);
    code[i] = instr;
  }
  fclose(ptr_myfile);
  
  myvm_run(code);
  
  free(code);
}
