#include<iostream>
#include<vector>
using namespace std;

//    n = 5           index_l + index_r = n-1 £»
//	                index_r = n - 1 - index_l 
//0 1 2 3 4             n = 5    
//
//1 2 3 4 5 
//-       6
//-
//- 
//- - - - -
//
//0 1 2 3            n = 4    
//
//1 2 3 4  
//-     5
//-
//- 
//- - - - -

void generate_matrix(vector<vector<int>>&data,int x,int y,int init_num,int n)
{
	if(n<=0) return;
	if(n == 1)
	{
		data[x][y] = init_num;
		return ;
	}
	
	for (int j=y;j<y+n-1;j++)
	{
		data[x][j]= init_num;
		init_num++;
	}
	
	for (int i=x;i<x+n-1;i++)
	{
		data[i][y+n-1]= init_num;
		init_num++;
	}
	for (int j=y+n-1;j>y;j--)
	{
		data[x+n-1][j]= init_num;
		init_num++;
	}
	for (int i=x+n-1;i>x;i--)
	{
		data[i][y]= init_num;
		init_num++;
	}
	
	generate_matrix(data,x+1,y+1,init_num,n-2);
	 
}
void display(vector<vector<int>>&data,int n)
{
	cout<<"["<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<"[";
		for(int j = 0;j<n;j++)
		{
			cout<<data[i][j];
			if(j!=n-1)
			{
				cout<<",";
			}
		}
		cout<<"]";
		if(i!=n-1) cout<<",";
		cout<<endl;
	}
	cout<<"]";
}
void solution(vector<vector<int>>&data,int n)
{
	generate_matrix(data,0,0,1,n);
	display(data,n);
}

int main()
{
	
	freopen("in.txt","r",stdin);
    int n;
	cin>>n;
	vector<vector<int>>data(n,vector<int>(n,0));
	solution(data,n);
} 
