#include "test.h"

void test_0_and_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_and(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

void test_1_and_0(void)
{
  myvm_stack_push(&vm, 1);
  myvm_stack_push(&vm, 0);
  myvm_and(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

void test_1_and_1(void)
{
  myvm_stack_push(&vm, 1);
  myvm_stack_push(&vm, 1);
  myvm_and(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 1);
}

void test_0_and_0(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 0);
  myvm_and(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

TEST_SUITE("myvm_and", 
  (NULL == CU_add_test(pSuite, "0 and 1 equals 0", test_0_and_1))
  || (NULL == CU_add_test(pSuite, "1 and 0 equals 0", test_1_and_0))
  || (NULL == CU_add_test(pSuite, "1 and 1 equals 1", test_1_and_1))
  || (NULL == CU_add_test(pSuite, "0 and 0 equals 0", test_0_and_0))
  )