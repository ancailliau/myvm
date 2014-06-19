#include "test.h"

void test_0_neq_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_neq(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 1);
}

TEST_SUITE("myvm_neq", 
  (NULL == CU_add_test(pSuite, "0 not equals 1", test_0_neq_1))
  )