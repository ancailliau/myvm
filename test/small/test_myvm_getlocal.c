#include "test.h"

void test_getlocal(void)
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
  myvm_getlocal(0, &vm);
  
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp), 19);
}

TEST_SUITE("test_getlocal", 
  (NULL == CU_add_test(pSuite, "Get local variable 0", test_getlocal))
  )