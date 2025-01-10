#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
vector<int>v;

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int reset(int s,int e)
{
    int base = v[s];
    int i = s;
    int j = e;
    while(i<j)
    {
        while(i<j&&v[j]>=base)
        {
            j--;
        }
        if(i<j)
        {
            swap(v[j],v[i]);
            i++;
        }

        while(i<j&&v[i]<=base)
        {
            i++;
        }
        if(i<j)
        {
            swap(v[i],v[j]);
            j--;
        }
    }
    v[i] = base;
    return i;
}
void quicksort(int s,int e)
{
    if(s>=e) return;
    int i = reset(s,e);
    quicksort(s,i-1);
    quicksort(i+1,e);

}
int main()
{
    ifstream in_data("in.txt");
    freopen("out.txt","w",stdout);
    string s ;
    int num;
    while(getline(in_data,s))
    {
        stringstream ss(s);
        while(ss>>num)
        {
            v.push_back(num);
        }
    }
    
    quicksort(0,v.size()-1);
    for(auto &a:v)
    {
    	printf("%d ",a);
	}

}
