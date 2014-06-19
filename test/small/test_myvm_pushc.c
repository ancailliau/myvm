#include "test.h"

void test_pushc_0(void)
{
  myvm_pushc(0, &vm);
  CU_ASSERT_EQUAL(vm.sp, 0);
  CU_ASSERT_EQUAL(vm.sb[vm.sp], 0);
}

TEST_SUITE("myvm_pushc", 
  (NULL == CU_add_test(pSuite, "Push constant 0 make stack unitary", test_pushc_0))
  )