#define GLOBAL_AREA_SIZE 3
#include "test.h"

void test_setglob_1(void)
{
  vm.gb[2] = 1;
  vm.gb[1] = 2;
  vm.gb[0] = 3;
  
  myvm_getglob(0, &vm);
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp), 3);

  myvm_getglob(1, &vm);
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp), 2);
  
  myvm_getglob(2, &vm);
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp), 1);
  
  CU_ASSERT_EQUAL(vm.gb[2], 1);
  CU_ASSERT_EQUAL(vm.gb[1], 2);
  CU_ASSERT_EQUAL(vm.gb[0], 3);
  
  CU_ASSERT_EQUAL(vm.sp, 2);
}

TEST_SUITE("myvm_getglob", 
  (NULL == CU_add_test(pSuite, "get int from global area", test_setglob_1))
  )