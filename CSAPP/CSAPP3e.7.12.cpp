 考虑目标文件 m.o 中对函数 swap 的调用(作业题7.6)。

9:    e8 00 00 00 00        callq e <main+Oxe>    swap()

具有如下重定位条目:

r.offset = 0xa

r.symbol = swap

r.type = R_X86_64_PC32 

r.addend = -4

A. 假设链接器将 m.o 中的 .text 重定位到地址 0x4004e0, 把 swap 重定位到地址 0x4004f8。那么 callq 指令中对 swap 的重定位引用的值应该是什么?
答:
  首先 refaddr = ADDR(.text) + r.offset = 0x4004e0 + 0xa = 0x4004ea;
  refptr = (unsigned)(ADDR(r.symbol) + r.addend - refaddr) = 0x4004f8 + (-4) - 0x4004ea = 0xa;
 

B. 假设链接器将 m.o 中的 .text 重定位到地址 0x4004d0, 把 swap 重定位到地址 0x400500。那么 callq 指令中对 swap 的重定位引用的值应该是什么?
答:
  首先 refaddr = ADDR(.text) + r.offset = 0x4004d0 + 0xa = 0x4004da;
  refptr = (unsigned)(ADDR(r.symbol) + r.addend - refaddr) = 0x400500 + (-4) - 0x4004da = 0x22;
 
