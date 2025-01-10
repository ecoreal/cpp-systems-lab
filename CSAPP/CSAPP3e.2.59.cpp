#include<iostream>
#include<bitset>
#include<iomanip>
using namespace std;

int main()
{
	unsigned int x;
	unsigned int y;
	unsigned int ans;
	
	x=0x89ABCDEF;
	y=0x76543210;
	
	ans=(x&0x000000FF)|(y&0xFFFFFF00);
	
	cout<<"Binary output:"<<endl;
	cout<<bitset<32>(ans)<<endl;
	cout<<"---------------"<<endl;
	
	cout<<" Hexadecimal output"<<endl;
	cout<<hex<<ans<<endl;
	cout<<"---------------"<<endl;
	
	cout<<"Decimal output"<<endl;
	cout<<dec<<ans<<endl;
	
	return 0;
}
