#include "test.h"

void test_sub_0_and_0(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 0);
  myvm_sub(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

void test_sub_5_and_1(void)
{
  myvm_stack_push(&vm, 5);
  myvm_stack_push(&vm, 1);
  myvm_sub(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 4);
}

void test_sub_1_and_5(void)
{
  myvm_stack_push(&vm, 1);
  myvm_stack_push(&vm, 5);
  myvm_sub(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], -4);
}

void test_sub_m5_and_1(void)
{
  myvm_stack_push(&vm, -5);
  myvm_stack_push(&vm, 1);
  myvm_sub(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], -6);
}

void test_sub_m1_and_5(void)
{
  myvm_stack_push(&vm, -1);
  myvm_stack_push(&vm, 5);
  myvm_sub(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], -6);
}

void test_sub_0_and_maxint(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, INT_MAX);
  myvm_sub(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], -INT_MAX);
}

TEST_SUITE("myvm_sub", 
  (NULL == CU_add_test(pSuite, "0 minus 0 equals 0", test_sub_0_and_0))
  || (NULL == CU_add_test(pSuite, "5 minus 1 equals 4", test_sub_5_and_1))
  || (NULL == CU_add_test(pSuite, "1 minus 5 equals -4", test_sub_1_and_5))
  || (NULL == CU_add_test(pSuite, "-5 minus 1 equals -6", test_sub_m5_and_1))
  || (NULL == CU_add_test(pSuite, "-1 minus 5 equals -6", test_sub_m1_and_5))
  || (NULL == CU_add_test(pSuite, "0 minus INT_MAX equals -INT_MAX", test_sub_0_and_maxint))
  )