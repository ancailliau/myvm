myvm
====

`myvm` is a small stack-based virtual machine implemented in C. The virtual
machine implements a small set of instructions. This virtual machine is 
based on the virtual machine described in this book.

The first eight bits represents the opcode. The trailing bits represents
the argument (or the arguments), as the following schema shows.

    | 0        7 | 8                           32 |
    |------------|--------------------------------|
    |  opcode    |  arg1                          |
    |------------|--------------------------------|
    
    |<- 8 bits ->|<- 24 bits -------------------->|
    
    
    | 0        7 | 8           20 | 21         32 |
    |------------|----------------|---------------|
    |  opcode    |  arg1          |  arg2         |
    |------------|----------------|---------------|
    
    |<- 8 bits ->|<- 12 bits ---->|<- 12 bits --->|
    
The following instructions are implemented

* hlt
* add
* sub
* mlt
* div
* mod
* minus
* and
* or
* not
* lt
* gt
* eq
* leq
* geq
* neq
* pushc
* pop
* swap
* dup
* say

And the following instructions are not yet implemented

* getglob
* setglob
* getlit
* mkvec
* vref
* vset
* jmp
* jeq
* jne
* getlocal
* setlocal
* getparam
* save
* frame
* call
* reti
* retb
* retv
* ret