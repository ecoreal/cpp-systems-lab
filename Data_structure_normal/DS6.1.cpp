//version 1.0
//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//
////struct LinkNode
////{
////	char data;
////	LinkNode *next;
////	LinkNode *prior;
////	LinkNode():next(nullptr),prior(nullptr){};
////	LinkNode(char c):data(c),next(nullptr),prior(nullptr){};
////};
////
////struct LinkString
////{
////	LinkNode *front;
////	LinkNode *rear;
////	int length;
////	LinkString()
////	{
////		front = rear = nullptr;
////		length = 0;
////	}
////	void Initialize(string s)
////	{
////		LinkNode *p;
////		for(char c:s)
////		{
////			p = new LinkNode(c);
////			if(!front)
////			{
////				front = rear = p;
////			}
////			else
////			{
////				front->next = p;
////				rear = p;
////				rear->prior = front;
////			}
////		}
////	}
////	
////};
////
////LinkNode* Match_Max(LinkString s1,LinkString s2)
////{
////	LinkNode *l = s1.front;
////	LinkNode *r = s2.rear;
////	
////}
//void Match_Max(string s1,string s2,string ans,int& ans_int)
//{
//	string s = s1+s2+'#';
//	int j = 0;
//	int k = -1;
//	int num = s.length();
//	int *next = new int[num];
//	while(j<num-1)
//	{
//		if(k==-1||s[k]==s[j])
//		{
//			k++;
//			j++;
//			next[j] = k;
//		}
//		else k = next[k];
//		
//	}
//	ans_int = next[num-1];
//	int count = 0;
////	for(int i = num - ans_int -1;i<=n -2;i++)
////	{
////		int index_ans = 0;
////		ans[index_ans] = s[i];
////		index_ans++;
////	}
//    while(count<ans_int)
//    {
//    	int i = num - ans_int -1;
//    	count++;
//    	ans[count] = s[i];
//	}
//
//	
//} 
//
//int main()
//{
//	ifstream in_data("in.txt");
//	if(!in_data.is_open())
//	{
//		cerr<<"Unable to open the file"<<endl;
//		return 0;
//	}
//    string s1;
//	string s2;
//	string ans;
//	
//	int ans_int = 0;
//	in_data>>s1>>s2;
//	
//	Match_Max(s1,s2,ans,ans_int);
//	
//	if(!ans_int)
//	{
//		cout<<ans_int;
//	}
//	else
//	{
//		cout<<ans<<" "<<ans_int;
//	}
//	
//	
//	
//}
//
//
// 

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//struct LinkNode
//{
//	char data;
//	LinkNode *next;
//	LinkNode *prior;
//	LinkNode():next(nullptr),prior(nullptr){};
//	LinkNode(char c):data(c),next(nullptr),prior(nullptr){};
//};
//
//struct LinkString
//{
//	LinkNode *front;
//	LinkNode *rear;
//	int length;
//	LinkString()
//	{
//		front = rear = nullptr;
//		length = 0;
//	}
//	void Initialize(string s)
//	{
//		LinkNode *p;
//		for(char c:s)
//		{
//			p = new LinkNode(c);
//			if(!front)
//			{
//				front = rear = p;
//			}
//			else
//			{
//				front->next = p;
//				rear = p;
//				rear->prior = front;
//			}
//		}
//	}
//	
//};
//
//LinkNode* Match_Max(LinkString s1,LinkString s2)
//{
//	LinkNode *l = s1.front;
//	LinkNode *r = s2.rear;
//	
//}
void Match_Max(string s1, string s2, string& ans, int& ans_int)
{
	int num_s1 = s1.length();
	int num_s2 = s2.length();
	int num_min = min(num_s1,num_s2);
	string s = s1 + s2 + '#';
	int j = 0;
	int k = -1;
	int num = s.length();
	//int* next = new int[num];
	int next[50000];
	next[0] = -1;
	//&&next[j]<=num_s1
	while (j < num - 1)
	{
		if (k == -1 || s[k] == s[j])
		{
			k++;
			j++;
			next[j] = k;
		}
		else k = next[k];

	}

	ans_int = next[num-1]<num_min?next[num - 1]:num_min;
	int count = 0;
	//	for(int i = num - ans_int -1;i<=n -2;i++)
	//	{
	//		int index_ans = 0;
	//		ans[index_ans] = s[i];
	//		index_ans++;
	//	}
	int i = num - ans_int - 1;
	while (count < ans_int)
	{
		
	/*	ans[count] = s[i];*/
		ans.push_back(s[i]);
		count++;
		i++;
	}
}

int main()
{
	ifstream in_data("in.txt");
	if (!in_data.is_open())
	{
		cerr << "Unable to open the file" << endl;
		return 0;
	}
	string s1;
	string s2;
	string ans;

	int ans_int = 0;
	in_data >> s1 >> s2;

	Match_Max(s1, s2, ans, ans_int);


	if (!ans_int)
	{
		cout << ans_int;
	}
	else
	{
		cout << ans << " " << ans_int;
	}



}
