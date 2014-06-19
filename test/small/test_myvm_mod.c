#include "test.h"

void test_mod_0_and_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_mod(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

TEST_SUITE("myvm_mod", 
  (NULL == CU_add_test(pSuite, "0 mod 1 equals 0", test_mod_0_and_1))
  )