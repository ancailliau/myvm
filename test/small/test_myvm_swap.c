#include "test.h"

void test_swap_0_and_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_swap(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp - 1], 1);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
  CU_ASSERT_EQUAL(vm.sp, 1);
}

TEST_SUITE("myvm_swap", 
  (NULL == CU_add_test(pSuite, "Swap 0 and 1 means 1 and 0", test_swap_0_and_1))
  )