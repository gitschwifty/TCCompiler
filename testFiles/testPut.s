.file "testPut.c"
.data
L_.str:
  .string "Hello world.\n"
.text
.globl _main
_main:
  leaq L_.str(%rip), %rdi #loads address into rdi
  movq $0, %rax #zero floats
  pushq %r10 #save q

  call _printf #call print

  popq %r10 #restore q
  ret
