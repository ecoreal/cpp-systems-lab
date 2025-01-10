#include<iostream>
using namespace std;
int Stack [20];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num ;
	int stacktop = -1;
	
	while(cin>>num)
	{
		if(num!=-1)
		{
			++stacktop;
			if(stacktop<20)
			{
				Stack[stacktop] = num;
			}
			else 
			{
				cout<<999<<endl; 
				break;
			}
		
		}
		else
		{
			if(stacktop<=-1)
			{
				cout<<-999<<endl;
				break;
			}
			else
			{
				cout<<Stack[stacktop--]<<endl;
			}
		}
	
	}
	
	
}
