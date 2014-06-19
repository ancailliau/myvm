#include "test.h"

void test_add_0_and_0(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 0);
  myvm_add(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

void test_add_5_and_1(void)
{
  myvm_stack_push(&vm, 5);
  myvm_stack_push(&vm, 1);
  myvm_add(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 6);
}

void test_add_1_and_5(void)
{
  myvm_stack_push(&vm, 1);
  myvm_stack_push(&vm, 5);
  myvm_add(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 6);
}

void test_add_m5_and_1(void)
{
  myvm_stack_push(&vm, -5);
  myvm_stack_push(&vm, 1);
  myvm_add(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], -4);
}

void test_add_m1_and_5(void)
{
  myvm_stack_push(&vm, -1);
  myvm_stack_push(&vm, 5);
  myvm_add(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 4);
}

void test_add_0_and_maxint(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, INT_MAX);
  myvm_add(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], INT_MAX);
}

void test_add_0_and_minint(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, INT_MIN);
  myvm_add(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], INT_MIN);
}

void test_add_maxint_and_minint(void)
{
  myvm_stack_push(&vm, INT_MAX);
  myvm_stack_push(&vm, INT_MIN);
  myvm_add(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], -1);
}

TEST_SUITE("myvm_add", 
  (NULL == CU_add_test(pSuite, "0 plus 0 equals 0", test_add_0_and_0))
  || (NULL == CU_add_test(pSuite, "5 plus 1 equals 6", test_add_5_and_1))
  || (NULL == CU_add_test(pSuite, "1 plus 5 equals 6", test_add_1_and_5))
  || (NULL == CU_add_test(pSuite, "-5 plus 1 equals -4", test_add_m5_and_1))
  || (NULL == CU_add_test(pSuite, "-1 plus 5 equals 4", test_add_m1_and_5))
  || (NULL == CU_add_test(pSuite, "0 plus INT_MAX equals INT_MAX", test_add_0_and_maxint))
  || (NULL == CU_add_test(pSuite, "0 plus INT_MIN equals INT_MIN", test_add_0_and_minint))
  || (NULL == CU_add_test(pSuite, "INT_MAX plus INT_MIN equals -1", test_add_maxint_and_minint))
  )