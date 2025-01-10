考虑下面的联合声明:
union ele { 
    struct {
        long *p;
        long y; 
    } el;
    
    struct { 
        long x;
        union ele *next; 
    } e2;
};

这个声明说明联合中可以嵌套结构。

    下面的函数(省略了一些表达式)对一个链表进行操作，链表是以上述联合作为元素的:

void proc (union ele *up) {

    up-> ________ =*(________) - ________;
    答：
	up->e2.x =  *((*(up->e2.next)).e1.p) - (*(up->e2.next)).e1.y;

}

A. 下列字段的偏移址是多少(以字节为单位): 

    e1.p        ____0____

    e1.y        ____8____

    e2.x        ____0____

    e2.next     ____8____

B. 这个结构总共需要多少个字节?
   答：需要16个字节。 
   因为e1需要16个字节，e2需要16个字节 而联合体的内存取决于内存最大的那个数据结构，所以需要16个字节 

C. 编译器为 proc 产生下面的汇编代码:

       void proc (uion ele *up)

       up in %rdi

    proc:

        movq 8(%rdi), %rax      //%rax = *(%rdi + 8) = y 或者 next 

        movq (%rax) , %rdx      //%rdx = *(%rax) = *(up->e2.next); 
		                        //又对%rax进行*操作，所以上述中只能是next 即 %rax = up->e2.next

        movq (%rdx), %rdx       //%rdx = *(%rdx) = *(*(up->e2.next).e1.p);

        subq 8(%rax), %rdx      //%rdx = %rdx - *(%rax + 8) = *(*(up->e2.next).e1.p) - *(up->e2.next + 8) 
		                        //= *(*(up->e2.next).e1.p) - *(up->e2.next).e1.y;

        movq %rdx, (%rdi)       //*(%rdi) = %rdx = *((*(up->e2.next)).e1.p) - (*(up->e2.next)).e1.y;

        ret

在这些信息的基础上，填写 proc 代码中缺失的表达式。
提示: 有些联合引用的解释可以有歧义，当你清楚引用指引到哪里的时候，就能够澄清这些歧义。
只有一个答案，不需要进行强制类型转换，且不违反任何类型限制。
