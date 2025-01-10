#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	ifstream in_data("in.txt");
	//freopen("out.txt","w",stdout);
	string s;
	while(getline(in_data,s))
	{
		cout<<s<<" "; 
	}
}
