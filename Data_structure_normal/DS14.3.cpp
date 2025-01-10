#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;

vector<int>v;

void vier_sort(int n)
{
    int d = n/2;
    while(d>0)
    {
        for(int i = d;i<n;i++)
        {
           if(v[i]<v[i-d])
           {
              int temp = v[i];
              int j = i-d;
              do
              {
                  v[j+d] = v[j];
                  j-=d;
              } while (j>=0&&v[j]>temp);
              v[j+d] = temp;
           }
        }
        d/=2;
    }

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

    vier_sort(v.size());
    for(auto& a:v)
    {
        printf("%d ",a);
    }



}
