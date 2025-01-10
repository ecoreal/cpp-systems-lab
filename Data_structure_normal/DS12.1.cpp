#include<iostream>
#include<vector>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	vector<int>v1;
	int target;
	vector<int>path;
	cin>>num;
	target = num;
	while(cin>>num)
	{
		v1.push_back(num);
	}
//	cout<<target<<endl;
//	for(vector<int>::iterator it = v1.begin();it!=v1.end();it++)
//	{
//		cout<<*it<<" ";
//	}
    int left = 0;
    int right = v1.size()-1;
    
    int mid = (left+right)/2;
    while(left<=right)
    {
    	path.push_back(v1[mid]);
    	if(v1[mid]==target)
		{	
			break;
		}
		else if(v1[mid]>target)
		{
			right = mid-1; 
			mid = (left+right)/2;
		}
		else 
		{
			left = mid+1; 
			mid = (left+right)/2;
		}
	}
	
	if(left<=right) cout<<"True"<<endl;
	else cout<<"False"<<endl;
	
	for(vector<int>::iterator it = path.begin();it!=path.end();it++)
	{
		cout<<*it<<" ";
	}

	
	
 } 
