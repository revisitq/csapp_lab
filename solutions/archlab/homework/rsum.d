
rsum.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <rsum>:
   0:	48 85 f6             	test   %rsi,%rsi
   3:	79 06                	jns    b <rsum+0xb>
   5:	b8 00 00 00 00       	mov    $0x0,%eax
   a:	c3                   	retq   
   b:	53                   	push   %rbx
   c:	48 8b 1f             	mov    (%rdi),%rbx
   f:	48 83 ee 01          	sub    $0x1,%rsi
  13:	48 83 c7 08          	add    $0x8,%rdi
  17:	e8 00 00 00 00       	callq  1c <rsum+0x1c>
  1c:	48 01 d8             	add    %rbx,%rax
  1f:	5b                   	pop    %rbx
  20:	c3                   	retq   
