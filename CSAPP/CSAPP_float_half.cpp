
unsigned  float_half(unsigned uf)
{
    unsigned sign = uf&0x80000000;
	unsigned exp = uf&0x7f800000;
	unsigned f = uf&0x007fffff;
	//0000 0000 0111 1111 1111 1111 1111 1111
	//0111 1111 1111 1111 1111 1111 1111 1111
	//SI        If
	
	if((exp>>23)==0xff)
	{
		return uf;
	}  
	else if(exp<=0x00800000)
	{
		f>>1;
		frac +=((uf&0x00000003)==0x00000003)
		//È¡Õû 
	} 
	else
	{
		exp-=0x00800000;
	}
	0 0000 f110   6/512;
	0 0001 f110   7/ 4*64 = 7/256  7/512  ->0 0000 111
	
	0 0000 f100    1/2 = 1/128
	0 0001 f100    3/ 2*64 = 3/128  3/256 -> 0 0000 110  
	
	
	
	
 } 
