#include<iostream>
#include<vector>
using namespace std;

int my_hash[201];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int goal;
	int num;
	int index = 0;
	cin>>goal;
	
	while(cin>>num)
	{
		index = num%199;
		while(my_hash[index]!=0)
		{
			index++;
			index%=200;
		}
		my_hash[index]=num;
	}
	
	bool flag = false;
	index = goal%199;
	vector<int>ans;
	
	while(1)
	{
		if(my_hash[index]==0) break;
		
		ans.push_back(my_hash[index]);
		if(my_hash[index]==goal)
		{
			flag = true;
			break;
		}
		index+=1;
		index%=200;
	}
	
	if(flag) cout<<"True"<<endl;
	else cout<<"False"<<endl;
	
	for(vector<int>::iterator it = ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<" ";
	}
	
	
	
 } 
