#include "test.h"

void test_not_1(void)
{
  myvm_stack_push(&vm, 1);
  myvm_not(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

void test_not_0(void)
{
  myvm_stack_push(&vm, 0);
  myvm_not(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 1);
}

TEST_SUITE("myvm_not", 
  (NULL == CU_add_test(pSuite, "Not 1 equals 0", test_not_1))
  || (NULL == CU_add_test(pSuite, "Not 0 equals 1", test_not_0))
  )