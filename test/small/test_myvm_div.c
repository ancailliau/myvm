#include "test.h"

void test_div_0_by_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_div(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

TEST_SUITE("myvm_div", 
  (NULL == CU_add_test(pSuite, "0 div by 1 equals 0", test_div_0_by_1))
  )