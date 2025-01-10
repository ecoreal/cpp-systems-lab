#include<iostream>
#include<vector>
using namespace std;
vector<int>uset;
vector<int>queue1;
vector<int>queue2;

void initial(int n)
{
	uset.push_back(0);
	for(int i = 1;i<=n;i++)
	{
		uset.push_back(i);
	}
}

void link(int pre,int data)
{
	uset[data] = pre; 
}

int find(int x)
{
	return uset[x];
}

//int is_phase1(int data1,int data2)
//{
//	if(data1==data2) return data1;
//	
//	if(is_phase1(uset[data1],data2))
//	{
//		return is_phase1(uset[data1],data2);
//	}
//	else if(is_phase1(data1,uset[data2]))
//	{
//		return is_phase1(data1,uset[data2]);
//	}
//	else
//	{
//		return 0
//	}
//}

void generate(vector<int>&queue,int data)
{
	if(queue.empty())
	{
		queue.push_back(data);
		generate(queue,uset[data]);
		
	}
	else
	{
		if(data!=queue.back())
		{
			queue.push_back(data);
			generate(queue,uset[data]);
		}
		else
		{
			return;
		}
	}
}

void generate_queue(int data1,int data2)
{
	generate(queue1,data1);
	generate(queue2,data2);
}


int calculate(int data1,int data2)
{
	int count1 = queue1.size();
	int count2 = queue2.size();
	if(count1>count2)
	{
		vector<int>temp_queue = queue1;
		queue1 = queue2;
		queue2 = temp_queue;
		
		int temp = count1;
		count1 = count2;
		count2 = temp;
	}
	for(int i = 0;i<count1;i++)
	{
		int pre1 = queue1[i];
		for(int j = 0;j<count2;j++)
		{
			if(pre1 == queue2[j])
			{
				return pre1;
			}
		}
	}
	
	return 0;
}
int main()
{
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	initial(n);
	
	int pre,data;
	while(n>1)
	{
		cin>>pre>>data;
		link(pre,data);
		
		n--;
	}
	
	int data1,data2;
	cin>>data1>>data2;
	
	generate_queue(data1,data2);
	
	int ans = calculate(data1,data2);
	cout<<ans;
	return 0;
	
	
	
}
