long cread_alt(long *xp) {
	long p = 0;
    return *(xp ? xp : &p);
}

# cread函数汇编代码
cread:
    testq   %rdi, %rdi        # 测试xp是否为0
    movq    $0, %rax          # 设置返回值为0
    cmovne  (%rdi), %rax      # 如果xp不为0，则将*xp赋值给%rax
    ret 
    
# cread_alt函数汇编代码
cread_alt:
    testq   %rdi, %rdi         # 测试xp是否为0
    movq    $0, -16(%rbp)      #将 默认值设为0
	movq    -16(%rbp), %rax    #设置返回值为0 
	cmovne  %rdi, %rax         #如果xp不为0，将 xp 的值复制到 %rax
	movq    -8(%rax), %rax     #将%rax中存储地址的数值提取出来 
    ret

//思路：
为了 使他可以被编译成使用条件数据传送，当编译时，产生的代码应该使用条件传送指令而不是某种跳转指令。 
即避免xp未空指针时引发的非法读取
那么可以创建一个long 类型的变量，且其数值置为0； 
即： 
如果xp不为nullptr 那么就会返回 *xp 的值，
如果xp为nullptr 那么 xp此时指向long变量的地址，返回*xp便是long变量的数值0； 
