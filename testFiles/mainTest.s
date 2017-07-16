	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc							##starts it idk
## BB#0:
	pushq	%rbp 												## add a space to the base q
Ltmp0:															##offset stuff idk
	.cfi_def_cfa_offset 16						##def cfa offset 16
Ltmp1:															##also an offset
	.cfi_offset %rbp, -16							##sets base pointer offset to 16
	movq	%rsp, %rbp									##moves q from stack pointer to base pointer
Ltmp2:															##actual stuff going on
	.cfi_def_cfa_register %rbp						##defines cfa register on base ptr
	xorl	%eax, %eax							##xor the long %eax to %eax toggles it idk y
	movl	$0, -4(%rbp)							##moves long from 0 register to next baseq spot
	popq	%rbp										##pops next from base queue
	retq													##returns queue
	.cfi_endproc									##ends this I think


.subsections_via_symbols
