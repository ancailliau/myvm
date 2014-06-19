#include "test.h"

void test_dup_0(void)
{
  myvm_stack_push(&vm, 0);
  myvm_dup(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
  CU_ASSERT_EQUAL(vm.sb[vm.sp - 1], 0);
}

TEST_SUITE("myvm_dup", 
  (NULL == CU_add_test(pSuite, "dup 0 push 0", test_dup_0))
  )