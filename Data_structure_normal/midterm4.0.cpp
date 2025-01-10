#include<iostream>
using namespace std;
int initial[201];
int odd[101];
int even[101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int index_odd = 0;
	int index_even = 0;
	int num;
	
	while(cin>>num)
	{
		if(num%2 == 1)
		{
			odd[index_odd++] = num;
		}
		else if(num%2 == 0)
		{
			even[index_even++] = num;
		}
	}
	for(int i = 0;i<index_even;i++)
	{
		cout<<even[i]<<" ";
	} 
	
	for(int i = 0;i<index_odd;i++)
	{
		cout<<odd[i]<<" ";
	} 
	return 0;
	
}
