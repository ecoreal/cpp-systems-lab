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

void quick_sort2(int s,int e,int goal)
{
    if(s>e) return;
    int mid = reset(s,e);
    if(goal==mid)
    {
        printf("%d ",v[mid]);
        return;
    }
    else
    {
        if(goal>mid)
        {
            quick_sort2(mid+1,e,goal);
        }
        else
        {
            quick_sort2(s,mid-1,goal);
        }
    }
    return;

}
int main()
{
    ifstream in_data("in.txt");
    freopen("out.txt","w",stdout); 
    string s;
    int num;
    while(getline(in_data,s))
    {
        stringstream ss(s);
        while(ss>>num)
        {
            v.push_back(num);
        }
    }
    num = v.size()-1;
    int i = 0;

    while(i<10)
    {
        quick_sort2(0,v.size()-1,num);
        num--;
        i++;
    }

    


}
