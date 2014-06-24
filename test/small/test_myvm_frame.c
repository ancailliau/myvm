#include "test.h"

void test_frame(void)
{
  int l, p;
  l = 1;
  p = 2;
  
  myvm_stack_push(&vm, 1);
  myvm_save(l, p, &vm);
  myvm_pushc(1, &vm);
  myvm_pushc(2, &vm);
  myvm_frame(l, p, &vm);
  
  CU_ASSERT_EQUAL(vm.fp, vm.sp - (FRAME_HEADER_SIZE + l + p) + 1);
}

TEST_SUITE("test_frame", 
  (NULL == CU_add_test(pSuite, "Frame frame", test_frame))
  )