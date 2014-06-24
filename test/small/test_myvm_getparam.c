#include "test.h"

void test_getparam(void)
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
  myvm_getparam(0, &vm);
  myvm_getparam(1, &vm);
  
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp), 2);
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp - 1), 1);
}

TEST_SUITE("test_getparam", 
  (NULL == CU_add_test(pSuite, "Get two first params", test_getparam))
  )