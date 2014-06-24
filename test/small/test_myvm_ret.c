#include "test.h"

void test_ret(void)
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
  myvm_ret(&vm);
  
  CU_ASSERT_EQUAL(vm.sp, 0);
  CU_ASSERT_EQUAL(vm.ip, 0);
  CU_ASSERT_EQUAL(vm.fp, -1);
}

TEST_SUITE("test_ret", 
  (NULL == CU_add_test(pSuite, "Returns from procedure", test_ret))
  )