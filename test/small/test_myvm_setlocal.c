#include "test.h"

void test_setlocal(void)
{
  int l, p;
  l = 1;
  p = 2;
  
  myvm_stack_push(&vm, 1);
  myvm_save(l, p, &vm);
  myvm_pushc(1, &vm);
  myvm_pushc(2, &vm);
  myvm_frame(l, p, &vm);
  myvm_call(17, &vm);
  myvm_pushc(19, &vm);
  myvm_setlocal(0, &vm);
  
  CU_ASSERT_EQUAL(*(vm.sb + vm.fp + FRAME_HEADER_SIZE), 19);
}

TEST_SUITE("test_setlocal", 
  (NULL == CU_add_test(pSuite, "Set local variable 0", test_setlocal))
  )