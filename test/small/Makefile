CC=gcc
CFLAGS=-c -Wall -I$(C_INCLUDE_PATH)
LDFLAGS=-L$(LIBRARY_PATH)

VM_SOURCES=../../src/myvm.c
VM_OBJECTS=$(VM_SOURCES:.c=.o)

TESTS_SOURCES=\
	test_myvm_add.c \
	test_myvm_sub.c \
	test_myvm_mlt.c \
	test_myvm_div.c \
	test_myvm_mod.c \
	test_myvm_minus.c \
	test_myvm_and.c \
	test_myvm_or.c \
	test_myvm_not.c \
	test_myvm_gt.c \
	test_myvm_lt.c \
	test_myvm_eq.c \
	test_myvm_leq.c \
	test_myvm_geq.c \
	test_myvm_neq.c \
	test_myvm_pushc.c \
	test_myvm_pop.c \
	test_myvm_swap.c \
	test_myvm_dup.c \
	test_myvm_save.c \
	test_myvm_frame.c \
	test_myvm_setlocal.c \
	test_myvm_getlocal.c \
	test_myvm_getparam.c \
	test_myvm_ret.c \
	test_myvm_retv.c

TESTS_OBJECTS=$(TESTS_SOURCES:.c=.o)
TESTS_EXECUTABLE=$(TESTS_SOURCES:.c=.out)

all: $(TESTS_EXECUTABLE)

.o.out:
	$(CC) $(LDFLAGS) $(VM_OBJECTS) $< -o $@  -lcunit 

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(TESTS_EXECUTABLE)

run: clean all
	@sh ./run_tests.sh