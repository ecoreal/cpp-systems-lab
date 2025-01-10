#include<iostream>
using namespace std;

int fac(int x)
{
	int ans= !(~x) || !(x^0x00000000) || !((x&0x000000FF)^0x000000FF) || !((x&0xFF000000));
	
	return ans;
} 

int main()
{
	//To test A 
	int x1=0xFFFFFFFE;//0
	
	//To test B
	int x2=0x00000001;//1
	int x3=0X80101010;//0
	
	//To test C
	int x4=0x001000FF;//1
	
	//To test D
	int x5=0x00FFFFFF;//1
	int x6=0x01FFF123;//0
	
	cout<<fac(x1)<<" "<<fac(x2)<<" "<<fac(x3)<<" "<<fac(x4)<<" "<<fac(x5)<<" "<<fac(x6)<<endl;
	
	return 0;
}
