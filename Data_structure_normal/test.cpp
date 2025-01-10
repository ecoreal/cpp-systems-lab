//#include<iostream> 
//using namespace std;
//
//
//int is_equal(int x,int y)
//{
//	
//	return !(x^y);
//}
//
//int bitMask(int high,int low)
//{
//	int a = 2^(high+1)-1;
//	int b = 2^(low)-1;
//	return (a + (~b)+1);
//}
//
//int addOK(int x, int y) {
//	
//	int temp = x+y;
//	
//	int over = ((x^temp)&(y^temp))<<31;
//	
//	
//    return !over;
//        
//}
//
//int isLess(int x, int y) {
//	
//	unsigned sign_x = (unsigned)x>>31;
//	
//	unsigned sign_y = (unsigned)y>>31;
//	
//	unsigned sign_diff = sign_x^sign_y;
//
//	unsigned neg_x = ~x+1;
//	
//	unsigned flag = ((neg_x+y)>>31) & 0x1;
//
//       return (sign_diff & sign_x)|(~sign_diff & flag);
//}
//
//
//int main()
//{
//	int a=0x80000000;
//	int b=0x80000000;
//	
//	cout<<isLess(0x80000000,0xe0a04da5);
//	
//	return 0;
//	
//}

#include<iostream>
//#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    // int x,y;
    // int nums[10][10];
    // memset(nums,0,sizeof(nums));
    // nums[x = 0][y = 1] = 888;
    // cout<<nums[x][y]<<endl;

    // char a[7] = {'H','e','l','l','o'};
    // char b[7];
    // strcpy(b,a);
    // for(int i = 0;i<strlen(b);i++)
    // {
    //     cout<<b[i]<<" ";
    // }
     int nums[10];

    for(int i = 0;i<10;i++)
    {
        nums[i] = i*i;
    }
    int j = 2; 

    return 0;

}
