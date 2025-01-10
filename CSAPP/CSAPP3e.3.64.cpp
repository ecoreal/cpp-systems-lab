A. 将等式(3.1)从二维扩展到三维，提供数组元素 A[i][j][k]的位置的公式。 
    答：
  设L为数组元素的大小 
  &A[i][j][k] = A + L(i*S*T + j*T + k);
  
B. 运用你的逆向工程技术，根据汇编代码，确定R、S和T的值。
    答： 
  
      store_ele: 

        leaq     (%rsi,%rsi,2), %rax     //%rax = %rsi + 2*%rsi = 3j;

        leaq     (%rsi,%rax,4), %rax     //%rax = j + 4*%rax = 13j;

        movq     %rdi, %rsi              //%rsi = %rdi = i

        salq     $6, %rsi                //%rsi = i<<6 = 64i;

        addq     %rsi, %rdi              //%rdi = %rdi + %rsi = 65i;

        addq     %rax, %rdi              //%rdi = %rdi + %rax = 65i + 13j;

        addq     %rdi, %rdx              //%rdx = %rdx + %rdi = 65i + 13j + k;

        movq     A(, %rdx, 8) , %rax     //%rax = *(A + 8*%rdx) = *(A + 8*(65i + 13j + k));

        movq     %rax, (%rcx)            //*dest = *(A + 8*%rdx) = *(A + 8*(65i + 13j + k));

        movl     $3640, %eax             //%rax = 3640;

        ret
		  
    得：
	T = 13;
	S = 5;
	R =  3640/8/13/5 = 7;        
        
