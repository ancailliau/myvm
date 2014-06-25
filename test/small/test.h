#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "../../src/myvm.h"

#ifndef GLOBAL_AREA_SIZE
#define GLOBAL_AREA_SIZE 0
#endif

struct myvm_vm vm;

int init_suite(void)
{
  return myvm_init (&vm, GLOBAL_AREA_SIZE);
}

int clean_suite(void)
{
  myvm_dispose(&vm);
  return 0;
}

#define TEST_SUITE(name, cond) int main()\
{\
  int errorNb; \
  CU_pSuite pSuite = NULL;\
  if (CUE_SUCCESS != CU_initialize_registry())\
    return CU_get_error();\
  pSuite = CU_add_suite("Test "#name, init_suite, clean_suite);\
  if (NULL == pSuite) {\
    CU_cleanup_registry();\
    return CU_get_error();\
  }\
  if(cond) {\
    CU_cleanup_registry();\
    return CU_get_error();\
  }\
  printf("===== Tests for ");\
  printf(name);\
  printf(" ========================================");\
  CU_basic_set_mode(CU_BRM_VERBOSE);\
  CU_basic_run_tests();\
  CU_basic_show_failures(CU_get_failure_list());\
  printf("\n\n");\
  errorNb = CU_get_number_of_failures();\
  CU_cleanup_registry();\
  return CU_get_error() || errorNb > 0;\
}
