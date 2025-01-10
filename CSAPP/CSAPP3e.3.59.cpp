下面的代码计算两个 64 位有符号值 x 和 y 的 128 位乘积，并将结果存储在内存中:

typedef __int128 int128_t;
void store_prod(int128_t *dest, int64_t x, int64_t y) { 

    *dest = x * (int128_t) y;

}

GCC 产出下面的汇编代码来实现计算 : 

store_prod :

    movq %rdx, %rax      //将rdx寄存器中存储的y的低64位放入到rax寄存器当中 

    cqto                 //将rax的符号扩展到rdx中，就是将rdx中的所有位都设置为rax的最高位 

    movq %rsi, %rcx      //将rsi寄存器中存储的x的低64位放入到rcx寄存器当中 

    sarq $63, %rcx       //对于rcx中存储的数进行算数右移63位，也就是说将rcx全部位置为x低64的最高位 

    imulq %rax, %rcx     //将rax和rcx相乘，并存储到rcx中 就是将y的低64位和x低64位的最高位的拷贝相乘 

    imulq %rsi, %rdx     //将rsi和rdx相乘，并存储到rdx中 就是将x的低64位和y低64位的最高位的拷贝相乘 

    addq %rdx, %rcx      //将rdx和rcx相加，并存储到rcx当中 
   
    mulq %rsi            //将rsi和rax相乘 所得结果的低64位存储到rax中，高64位存储到rdx中 

    addq %rcx, %rdx      //将rcx和rdx相加，并存储到rdx中  现在rcx中存储的便是 实际ph的值 

    movq %rax, (%rdi)    //将rax中的数据存入rdi目标内存的低64位 
 
    movq %rdx, 8(%rdi)   //将rdx中的数据存入对rdi目标内存偏移量为8的高64位 

    ret                  //返回 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


movq %rdx, %rax        ; 将 y 的低 64 位放入 rax 中
cqto                    ; 将 rax 的符号扩展到 rdx 中，即将 rdx 中的所有位设置为 rax 的最高位的拷贝
movq %rsi, %rcx        ; 将 x 的低 64 位放入 rcx 中
sarq $63, %rcx         ; 对 rcx 中的 64 位进行算术右移 63 位，此操作将 x 的最高位拷贝到 rcx 的所有位中
imulq %rax, %rcx       ; 将 rax（y 的低 64 位）和 rcx（x 的最高位的拷贝）相乘，并将结果放入 rcx 中，得到 ph 的部分乘积
imulq %rsi, %rdx       ; 将 rsi（x）和 rdx（y 的符号扩展后的高 64 位）相乘，并将结果放入 rdx 中，得到 pl 的部分乘积
addq %rdx, %rcx        ; 将得到的 pl 部分乘积加到 ph 的部分乘积中，结果存入 rcx，// 现在 rcx 包含了 ph 部分的最终值
mulq %rsi               ; 将 rsi（x）和 rax（y 的低 64 位）相乘，结果存入 rax 和 rdx，这是 pl 的部分乘积的另一部分
addq %rcx, %rdx         ; 将之前计算得到的 ph 部分乘积（存放在 rcx 中）加到 pl 的另一部分乘积（存放在 rdx 中），结果存入 rdx，得到最终的 pl 部分乘积
movq %rax, (%rdi)      ; 将 rax（pl 的另一部分乘积）存入目标内存的低 64 位
movq %rdx, 8(%rdi)    ; 将 rdx（ph 部分的最终值）存入目标内存的高 64 位
ret                      ; 返回


 ------------------------------------------------------------------------------------------------
    //通过这两次乘法操作，可以得到128位的乘积，其中高64位存储在rcx中，低64位存储在rdx中。
	//然后，通过加法操作将得到的两部分乘积相加，最终得到了完整的128位乘积，其中高位存储在rdx中，低位存储在rax中。













