#include <limits.h>

int saturating_add(int x, int y) {
	int sum = x + y;
	int mask = INT_MIN;
	//INT_MIN 1000 0000  0000 0000  0000 0000  0000 0000

	//x>0 y>0 ÇÒsum<0 
	int Positive_over = !(x&INT_MIN) && !(y&INT_MIN) && (sum&INT_MIN);
	
    //x<0 y<0 ÇÒsum>0 
	int Negative_over = (x&INT_MIN) && (y&INT_MIN) && !(sum&INT_MIN);
	
	if(Positive_over)
	{
		return INT_MAX;
	}
	else if(Negative_over)
	{
		return INT_MIN
	}
	
	else
	{
		return sum;
	}
	
}


