#include<iostream>
#include<vector>
using namespace std;

//	----- n = 5
//	q----1 0      anti_diag  column + row = simple 0  1 3  2 2 3 1 0 4  0--(n - 1)^2
//	-q---2 1      diag column - row + n - 1= simple   -4 + 4 -- 4 + 4   0--2*(n - 1)
//	--q--3 2
//	---q-4 3
//diag = column - row + n - 1
//anti_diag = column + row


vector<int>row_to_column(100,-1);
vector<bool>column(100,0);
vector<bool>diag(100,0);
vector<bool>anti_diag(100,0);
int n;
int ans = 0;

bool is_forbidden(int r,int c)
{
	for(int i = 0;i<r;i++)
	{
		if(column[c] == 1||diag[c - r + n -1] == 1||anti_diag[c + r] == 1) return true;
	}
	return false;
}
void set(int r,int c)
{
	column[c] = 1;
	diag[c - r + n -1] = 1;
	anti_diag[c + r] = 1;
}

void reset(int r,int c)
{
	column[c] = 0;
	diag[c - r + n -1] = 0;
	anti_diag[c + r] = 0;
}
void Queen(int row)
{
	if(row == n)
	{
		ans++;
		return;
	}
	
	for(int column = 0;column<n;column++)
	{
		if(!is_forbidden(row,column))
		{
			row_to_column[row] = column;
			set(row,row_to_column[row]);
			Queen(row + 1);
			reset(row,row_to_column[row]);
			row_to_column[row] = -1;
		}
		
	}
}

void solution(int n)
{

	Queen(0);
	cout<<ans;
    return;
}


int main()
{
	freopen("in.txt","r",stdin);
	cin>>n;
    solution(n);
	
}

