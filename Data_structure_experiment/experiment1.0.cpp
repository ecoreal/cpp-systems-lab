#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Triple
{
	int row;
	int col;
	int val;
	Triple (int r,int c,int v):row(r),col(c),val(v){};
	bool operator<(const Triple& y)
	{
		if(this->row==y.row)
		{
			return this->col < y.col;
		}
		return this->row < y.row;
	}
};
 	
void Transform_and_display(int count,const vector<Triple>& pre_data)
{
	vector<Triple> data;
	for(int i = 0;i<count;i++)
	{
		int row = pre_data[i].col;
		int col = pre_data[i].row;
		int val = pre_data[i].val;
		Triple temp = Triple(row,col,val);
		data.push_back(temp);
	}
	sort(data.begin(),data.end());
	for(int i = 0;i<count;i++)
	{
		cout<<data[i].row<<" "<<data[i].col<<" "<<data[i].val<<endl;
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	vector<Triple> data;
	int row,col,count;
	cin>>row>>col>>count;
	int r0,c0,v0;
	

	while(cin>>r0>>c0>>v0)
	{
		Triple temp(r0,c0,v0);
		data.push_back(temp);
	}
	
	cout<<col<<" "<<row<<" "<<count<<endl;
	
	Transform_and_display(count,data);
	
	
}
