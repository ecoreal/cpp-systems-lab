typedef struct {
    long a[2];
    long *p; 
} strA;

typedef struct { 
    long u[2];
    long q; 
} strB;


strB process(strA s) { 

    strB r;

    r.u[0] = s.a[1];

    r.u[1] = s.a[0]; 

    r.q =    *s.p; 

    return r;

}

long eval(long x, long y, long z) { 

    strA s;

    s.a[0] = x;

    s.a[1] = y;

    s.p = &z;

    strB r = process(s);

    return r.u[0] + r.u[1] + r.q;

}

    GCC 为这两个函数产生下面的代码:
//调用者 
 long eval(long x, long y, long z) 

   x in %rdi , y in %rsi, z in %rdx

eval:

    subq     $104, %rsp       //%rsp = %rsp -104;即栈指针向下生长104个单位 

    movq     %rdx, 24(%rsp)   //*(%rsp + 24) = %rdx = z;

    leaq     24(%rsp), %rax   //%rax = &*(24 + %rsp) = &z

    movq     %rdi, (%rsp)     //*(%rsp) = x;

    movq     %rsi, 8(%rsp)    //*(%rsp + 8) = y;

    movq     %rax, 16(%rsp)   //*(%rsp + 16) = %rax = &z;

    leaq     64(%rsp), %rdi   //%rdi = &*(%rsp + 64);

    call     process

    movq     72(%rsp), %rax   //%rax = *(%rsp + 72) = x;

    addq     64(%rsp), %rax   //%rax += *(%rsp + 64) = x + y;

    addq     80(%rsp), %rax   //%rax += *(%rsp + 80) = x + y + z;

    addq     $104, %rsp       //复原栈顶指针，原则上将代码全部弹出栈； 

    ret
    
//被调用者
  strB process(strA s) ///=调用该函数时，%rsp会向下生长 8个bit 

process:

    movq     %rdi, %rax       //%rax = %rdi = &*(旧%rsp + 64);//以下 %rsp都指新 %rsp  新%rsp = 旧%rsp - 8； 

    movq     24(%rsp), %rdx   //%rdx = %rsp+24 = &z;

    movq     (%rdx), %rdx     //%rdx = *(%rdx) = z;

    movq     16(%rsp), %rcx   //%rcx = *(%rsp + 16) = y 

    movq     %rcx, (%rdi)     //*(%rsp + 64 + 8) = y;

    movq     8(%rsp), %rcx    //%rcx = *(%rsp + 8) = x; 

    movq     %rcx, 8(%rdi)     //*(%rsp + 64 + 8 + 8) = x;

    movq     %rdx, 16(%rdi)    //*(%rsp + 64 + 8 + 16) = z;

    ret
    
