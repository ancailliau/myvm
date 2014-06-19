#include "test.h"

void test_minus_1(void)
{
  myvm_stack_push(&vm, 1);
  myvm_minus(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], -1);
}

TEST_SUITE("myvm_minus", 
  (NULL == CU_add_test(pSuite, "minus 1 equals -1", test_minus_1))
  )