.file "mainTest.c"
.text
.globl _main
_main:
.LFB0:
  .cfi_startproc
  pushq %rbp
  .cfi_def_cfa_offset 16
  .cfi_offset %rbp, -16
  movq %rsp, %rbp
  .cfi_def_cfa_register %rbp
  xorl %eax, %eax
  movl $0, -4(%rbp)
  popq %rbp
  retq
  .cfi_endproc
