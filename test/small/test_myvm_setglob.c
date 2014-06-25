#define GLOBAL_AREA_SIZE 3
#include "test.h"

void test_setglob_1(void)
{
  myvm_stack_push(&vm, 1);
  myvm_stack_push(&vm, 2);
  myvm_stack_push(&vm, 3);
  myvm_setglob(0, &vm);
  myvm_setglob(1, &vm);
  myvm_setglob(2, &vm);
  
  CU_ASSERT_EQUAL(vm.gb[2], 1);
  CU_ASSERT_EQUAL(vm.gb[1], 2);
  CU_ASSERT_EQUAL(vm.gb[0], 3);
  
  CU_ASSERT_EQUAL(vm.sp, -1);
}

TEST_SUITE("myvm_setglob", 
  (NULL == CU_add_test(pSuite, "store int in global area", test_setglob_1))
  )