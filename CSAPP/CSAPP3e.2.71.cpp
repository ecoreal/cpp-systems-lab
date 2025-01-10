/*A:
这段代码错误点：
1.函数名字写错了，应该是 xbyte 而不是 xbyt。
2.wor 应该是 word。
bytenu 应该是 bytenum。
3.只是简单地抽取了指定的字节，然后将其视为无符号整数。如果该字节的符号位为1，
那么这个字节代表的是一个负数，但是这段代码会错误地将其解释为一个大的正数。
*/

//代码实现如下：
int xbyte(packed_t word, int bytenum) {
	
	 
	int shift_left = (3 - bytenum) << 3;
    int shift_right = 3 << 3;
    return (int)word << shift_left >> shift_right;
	
	
}



