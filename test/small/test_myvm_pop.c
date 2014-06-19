#include "test.h"

void test_pop_0(void)
{
  myvm_stack_push(&vm, 0);
  myvm_pop(&vm);
  CU_ASSERT_EQUAL(vm.sp, -1);
}

TEST_SUITE("myvm_pop", 
  (NULL == CU_add_test(pSuite, "Pop unitary stack empty stack", test_pop_0))
  )