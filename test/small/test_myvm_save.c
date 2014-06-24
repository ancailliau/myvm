#include "test.h"

void test_save(void)
{
  int l, p;
  l = 1;
  p = 2;
  
  myvm_stack_push(&vm, 1);
  myvm_save(l, p, &vm);
  
  CU_ASSERT_EQUAL(vm.sp, FRAME_HEADER_SIZE + l);
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp - l - FRAME_HEADER_SIZE + 2), -1);
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp - l - FRAME_HEADER_SIZE + 3), p);
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp - l - FRAME_HEADER_SIZE + 4), l);
}

TEST_SUITE("myvm_save", 
  (NULL == CU_add_test(pSuite, "Save frame", test_save))
  )