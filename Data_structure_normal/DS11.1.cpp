include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
const int  maxV=100;

typedef struct{
	int numberVertices,numEgges;
	char VerticeList[maxV];
	int edge[maxV][maxV];
} MGraph;

int main()
{
//	freopen("in.txt","r",stdin);
	MGraph mg;
	string s1;
	string s2;
	cin>>s1>>s2;
	int i = 0;
	int count = 0;
	int j = 0;
	//init
	unordered_map<char,int>mp;
	unordered_map<char,int>in;
	unordered_map<char,int>out;
	
	while(i<(int)s1.length())
	{
		if(s1[i]!='{'&&s1[i]!='}'&&s1[i]!=',')
		{
			mg.VerticeList[count] = s1[i];
			mp[s1[i]] = count;
			in[s1[i]] = 0;
			out[s1[i]] = 0;
			count++;
		}
		i++;
	}
	mg.numberVertices = count;
	
	while(j<(int)s2.length())
	{
		out[s2[j+1]]++;
		in[s2[j+3]]++;
		mg.edge[mp[s2[j+1]]][mp[s2[j+3]]] = 1;
		j+=6;
	}
    int k = 0;
    vector<char> ans;

    while(k<mp.size())
    {
        if(out[mg.VerticeList[k]]>in[mg.VerticeList[k]])
        {
            ans.push_back(mg.VerticeList[k]);
        }
        k++;
    }
    cout<<"K vertices: ";
    for(vector<char>::iterator it = ans.begin();it!= ans.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"Number of K vertices: "<<ans.size();
    
	
	
	
	
	
	
	
	
} 
