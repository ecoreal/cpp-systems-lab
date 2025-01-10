#include<iostream>
using namespace std;


//void GetNext(string t,int* next) //由模式串t求出next值
//{ 
//	int j=0, k=-1;
//	next[0]=-1;
//	while (j<t.length()-1)
//	{ 
//		if (k==-1 || t[j]==t[k]) //k为-1或比较的字符相等时
//		{ 
//			j++; k++; //依次移到下一个字符
//			next[j]=k;
//		}
//		else k=next[k]; //比较的字符不相等时k回退
//	}
//}
//
//
//int KMP(string s,string t) //基本KMP算法
//{ 
//	int n=s.length(),m=t.length();
//	int* next=new int[m];
//	GetNext(t,next); //求出局部匹配信息next数组
//	int i=0,j=0;
//	while (i<n && j<m) //s和t均没有遍历完
//	{ 
//		if (j==-1 || s[i]==t[j]) //j=-1或者比较的字符相同时
//		{
//		   i++;
//		   j++; //i,j各增1
//		}
//		else j=next[j]; //否则i不变,j回退
//	}
//	if (j>=m) return i-m; //t串遍历完毕：匹配成功
//	else return -1; //匹配不成功，返回-1
//}
//
//
//void GetNextvalue(string t,int* nextval)
//{
//	int j = 0,k = -1;
//	nextval[0] = -1;
//	while(j<t.length())
//	{
//		if(k==-1||t[j]==t[k])
//		{
//			j++;
//			k++;
//			if(t[j]!=t[k])
//			{
//				nextval[j]=k;
//			}
//			else nextval[j]=nextval[k];
//		}
//		else k = nextval[k];
//	}
//}
//int KMPval(string s,string t)
//{
//	int i = 0, j = 0;
//	int n = s.length(),m = t.length();
//	
//	GetNextval(t,nextval);
//	
//	while(i<n&&j<m)
//	{
//		if(j==-1||s[i]==t[j])
//		{
//			i++;
//			j++;
//		}
//		else j = nextval[j];
//	}
//	if(j>=m) return i-m;
//	else return -1;
//	
//	
//}

//5.28
//可以改成（string t,int* nextval) 
void Get_nextval(string t,int nextval[])
{
	int j = 0;
	int k = -1;
	while(j<t.length())
	{
		if(k==-1||t[k]==t[j])
		{
			k++;j++;
			if(t[k]!=t[j])
			{
				nextval[j] = k;
			}
			else
			{
				nextval[j] = nextval[k];
			}
		}
		else
		{
			k = nextval[k];
		}
		
	}
	
	
}
int KMP(string s,string t)
{
	int s_n = s.length();
	int t_n = t.length();
	int nextval[s_n];
	//改成
	//int* nextval = new int[t_n];
	Get_nextval(t,nextval);
	int i = 0;
	int j = 0;
	while(i<s_n&&j<t_n)
	{
		if(j==-1||s[i]==t[j])
		{
			j++;
			i++;
		} 
		else
		{
			j = nextval[j];
		}
	}
	if(j>=t_n)
	{
		return i-j;
		//改成 i-t_n; 
	}
	else return -1;
	
}





















