#include "test.h"

void test_0_or_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_or(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 1);
}

void test_1_or_1(void)
{  
  myvm_stack_push(&vm, 1);
  myvm_stack_push(&vm, 1);
  myvm_or(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 1);
}

void test_0_or_0(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 0);
  myvm_or(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

void test_1_or_0(void)
{  
  myvm_stack_push(&vm, 1);
  myvm_stack_push(&vm, 0);
  myvm_or(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 1);
}

TEST_SUITE("myvm_or", 
  (NULL == CU_add_test(pSuite, "0 or 1 equals 1", test_0_or_1))
  || (NULL == CU_add_test(pSuite, "1 or 0 equals 1", test_1_or_0))
  || (NULL == CU_add_test(pSuite, "0 or 0 equals 0", test_0_or_0))
  || (NULL == CU_add_test(pSuite, "1 or 1 equals 1", test_1_or_1))
  )