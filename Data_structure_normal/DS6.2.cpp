#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;


void compress(vector<char>&chars,vector<char>&ans)
{
	int index_traverse = 0;
	int n = chars.size();
	char char_temp;

	while(index_traverse<n)
	{
		int count = 1;
		char_temp = chars[index_traverse];
		while(index_traverse<n-1&&chars[index_traverse]==chars[index_traverse+1])
		{
			index_traverse++;
			count++;
		}
		index_traverse++;
		ans.push_back(char_temp);
		if(count!=1)
		{
			stringstream ss;
			ss<<count;
			string count_str = ss.str();
			for(char c:count_str)
			{
				ans.push_back(c);
			}
		}
    }
}

int main()
{
	ifstream in_data("in.txt");
	char c;
	vector<char>chars;
	vector<char>ans;	
	
	while(in_data>>c)
	{
		chars.push_back(c);
	}
	
	compress(chars,ans);
	for(vector<char>::iterator it = ans.begin();it<ans.end();it++)
	{
		cout<<*it<<" ";
	}
//    for(int i = 0;i<=index_ans;i++)
//    {
//    	cout<<chars[i]<<" ";
//	}

	
}
