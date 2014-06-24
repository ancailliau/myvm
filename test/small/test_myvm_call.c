#include "test.h"

void test_call(void)
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
  
  CU_ASSERT_EQUAL(*(vm.sb + vm.fp), 0);
  CU_ASSERT_EQUAL(vm.ip, 17);
}

TEST_SUITE("test_call", 
  (NULL == CU_add_test(pSuite, "Call", test_call))
  )