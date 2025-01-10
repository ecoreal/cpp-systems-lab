#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

vector<int>v;

void merge(int s,int m,int e)
{
    vector<int> v2;
    v2.resize(e-s+1);
    int i = s;
    int j = m+1;
    int k = 0;
    while(i<=m&&j<=e)
    {
        if(v[i]>v[j])
        {
            v2[k++] = v[j];
            j++;
        }
        else
        {
            v2[k++] = v[i];
            i++;
        }
    }
    while(i<=m)
    {
        v2[k] = v[i];
        ++i;
        ++k;
    }
    while(j<=e)
    {
        v2[k] = v[j];
        ++j;
        ++k;
    }

    for( k = 0,i = s; i<=e ;k++)
    {
        v[i] =v2[k];
        i++; 
    }

}

void mergesort(int start,int end)
{
    if(start>=end) return ;
    int mid = (start+end)/2;
    mergesort(start,mid);
    mergesort(mid+1,end);
    merge(start,mid,end);
}
int main()
{
    ifstream in_data("in.txt");
    freopen("out.txt","w",stdout);
    string s;
    while(getline(in_data,s))
    {
        stringstream ss(s);
        int num;
        while(ss>>num)
        {
            v.push_back(num);
        }
    }

    mergesort(0,v.size()-1);

    for(auto &a:v)
    {
        printf("%d ",a);
    }


}
