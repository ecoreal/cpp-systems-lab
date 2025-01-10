#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
vector<int>v;
int count;

void swap(int& a,int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void stack_assistant(int i)
{
    int current = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<=count&&v[current]<v[left])
    {
        current = left;
    }
    if(right<=count&&v[current]<v[right])
    {
        current = right;
    }
    if(current!=i)
    {
        swap(v[current],v[i]);
        stack_assistant(current);
    }
}

void stack_sort()
{
    int i = (count+1)/2-1;
    while(i>=0)
    {
        stack_assistant(i);
        i--;
    }
}

void display()
{
    printf("%d ",v[0]);
    swap(v[0],v[count]);
    count--;
    stack_sort();

}

int main()
{
    ifstream in_data("in.txt");
    int n,m,num;
    in_data>>n>>m;
    count = n-1;
    while(n--)
    {
        in_data>>num;
        v.push_back(num);
    }

    stack_sort();

    while(m--)
    {
        display();
    }

}
