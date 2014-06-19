#include "test.h"

void test_0_leq_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_leq(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 1);
}

TEST_SUITE("myvm_leq", 
  (NULL == CU_add_test(pSuite, "0 lower or equals to 1", test_0_leq_1))
  )