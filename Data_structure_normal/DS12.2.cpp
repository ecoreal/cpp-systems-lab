#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	freopen("in.txt","r",stdin);
	int NUM;
	int temp;
	vector<int>v1;
	vector<int>diff; 
	cin>>NUM;
	
	
	for(int i = 0;i<NUM;i++)
	{
		cin>>temp;
		v1.push_back(temp);
	}
	
	for(int i = 0;i<NUM;i++)
	{
		for(int j = i+1;j<NUM;j++)
		{
			temp = abs(v1[i]-v1[j]);
			diff.push_back(temp);
		}
	}
	
	
	sort(diff.begin(),diff.end());
	cout<<diff[(diff.size()-1)/2]<<endl;
	
	
	
	
}
