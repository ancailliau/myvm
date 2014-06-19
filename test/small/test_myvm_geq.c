#include "test.h"

void test_0_geq_1(void)
{
  myvm_stack_push(&vm, 0);
  myvm_stack_push(&vm, 1);
  myvm_geq(&vm);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

TEST_SUITE("myvm_geq", 
  (NULL == CU_add_test(pSuite, "0 not greater or equals to 1", test_0_geq_1))
  )