#include "test.h"

void test_mlt_0_and_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_mlt(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

TEST_SUITE("myvm_mlt", 
  (NULL == CU_add_test(pSuite, "0 mlt 1 is 0", test_mlt_0_and_1))
  )