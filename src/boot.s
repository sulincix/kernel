#define FIXADDR(addr) (((addr)-_int32)+0x7C00)

.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16

stack_bottom:
.skip 16384 # 16 KiB

stack_top:
.section .text
.global _start
.type _start, @function

_protsec:
	mov %eax,%cr0
	inc %eax
	mov %cr0,%eax
	ret

_start:
	mov $stack_top, %esp
	cli
	call _protsec
	call kernel_main

1:	hlt
	jmp 1b

.size _start, . - _start

