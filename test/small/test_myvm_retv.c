#include "test.h"

void test_retv(void)
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
  myvm_pushc(31, &vm);
  myvm_retv(&vm);
  
  CU_ASSERT_EQUAL(*(vm.sb + vm.sp), 31);
  CU_ASSERT_EQUAL(vm.sp, 1);
  CU_ASSERT_EQUAL(vm.ip, 5);
  CU_ASSERT_EQUAL(vm.fp, -1);
}

TEST_SUITE("test_retv", 
  (NULL == CU_add_test(pSuite, "Returns from function", test_retv))
  )