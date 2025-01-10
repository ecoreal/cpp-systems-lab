#include<iostream>
#include<vector>
using namespace std;
int uset[1001];
int remain_roads;


int find(int x)
{
	if(uset[x] == x)
	{
		return x;
	}
	else
	{
		uset[x] = find(uset[x]);
	}
	return uset[x];
}

void uion(int x,int y)
{
	int pre1 = find(x);
	int pre2 = find(y);
	if(pre1!=pre2)
	{
		uset[pre1] = pre2;
		remain_roads--;
	}
	
}
int main()
{
	freopen("in.txt","r",stdin);
	int city_number;
	int road_number;
	
	cin>>city_number>>road_number;

//	uset.push_back(0);
	remain_roads = city_number-1;
	
	for(int i = 1;i<=city_number;i++)
	{
		uset[i] = i;
 		//uset.push_back(i);
	}
	
	int city1,city2;
	for(int i = 0;i<road_number;i++)
	{
		cin>>city1>>city2;
		uion(city1,city2);
	}

	cout<<max(remain_roads,0);
 } 
