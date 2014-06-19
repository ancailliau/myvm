#include "test.h"

void test_0_gt_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_gt(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

TEST_SUITE("myvm_gt", 
  (NULL == CU_add_test(pSuite, "0 not greater than 1", test_0_gt_1))
  )