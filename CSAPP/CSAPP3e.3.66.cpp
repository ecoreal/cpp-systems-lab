    long sum_col(long n, long A[NR(n)][NC(n)], long j) 
    n in %rdi, A in %rsi, j in %rdx
    sum_col:

        leaq    1(,%rdi,4), %r8         //%r8 = 1 + 4*n； 

        leaq    (%rdi,%rdi,2), %rax     //%rax = %rdi + 2*%rdi = 3n;

        movq    %rax, %rdi              //%rdi = %rax = 3n;

        testq   %rax, %rax              //%rax^%rax 即判断%rax是否为0 

        jle     .L4                     //如果%rax 即3n小于等于0跳转至.L4 

        salq    $3, %r8                 //%r8<<3 = (1 + 4*n)*%r8 = 8*(1 + 4*n);
        
        leaq    (%rsi,%rdx,8), %rcx     //%rcx = %rsi + 8*%rdx = A + 8*j;

        movl    $0, %eax                //%rax = 0;

        movl    $0, %edx                //%rdx = 0;

    .L3:

        addq    (%rcx), %rax            //%rax += *rcx += *(A + 8*j) += A[0][j];

        addq    $1, %rdx                //rdx += 1;

        addq    %r8, %rcx               //rcx = A + 8*j + 8 + 32*n;

        cmpq    %rdi, %rdx              //用%rdx - %rdi 并改变条件码寄存器的值 

        jne     .L3                     //如果小于等于0 即%rdx<%rdi,直观来说就是 是否进行了 3n次跳转到.L3 

        rep; ret                        //返回 

    .L4:                               //3n小于等于0 直接返回0 

        movl    $0, %eax               //%rax = 0

        ret                            //返回%rax中的值 

运用你的逆向工程技术，确定 NR 和 NC 的定义。
  答： 综上所述，
  NR(n) = 3*n 
  NC(n) = (1 + 4*n)<<3 = 8*(1 + 4*n)
  
