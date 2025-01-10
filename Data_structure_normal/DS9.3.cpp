	//before_debug

//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node *LTree;
//	Node *RTree;
//	Node(int i):data(i)
//	{
//		LTree = RTree = nullptr;
//	}
//	Node()
//	{
//		data = -1;
//		LTree = RTree = nullptr;
//	}
//};
//
//struct BTree
//{
//	Node* root;
//	BTree()
//	{
//		root = nullptr;
//	} 
//	Node* generate(vector<int>&v,int begin,int end);
//};
//
//int get_index(vector<int>&v,int begin,int end)
//{
//	int ans = -1;
//	int temp = v[begin];
//	for(int i = begin;i<=end;i++)
//	{
//		if(v[i]>temp)
//		{
//			ans = i;
//			temp = v[i];
//		}
//	}
//	return ans;
//}
//
//Node* BTree::generate(vector<int>&v,int begin,int end)
//{
//	if(begin>end) return nullptr;
//	int Max = v[get_index(v,begin,end)];
//	Node *p = new Node(Max);
//	
//	p->LTree = generate(v,begin,get_index(v,begin,end)-1);
//	p->RTree = generate(v,get_index(v,begin,end)+1,end);
//	
//	return p;
//}
//
//
//
//void showtree(Node* root)
//{
//	if(root)
//	{
//		cout<<root->data;
//		if(root->LTree||root->RTree)
//		{
//			cout<<'(';
//			showtree(root->LTree);
//			if(root->RTree)
//			{
//				cout<<',';
//			}
//			showtree(root->RTree);
//			cout<<')';
//		}
//	}
//}
//int main()
//{
//	//freopen("in.txt","r",stdin);
//	
//	vector<int>v;
//	string s;
//	getline(cin,s);
//	int count = (s.length()+1)/2;
//	for(int i = 0;i<count;i++)
//	{
//		v.push_back((s[2*i] - '0'));
//	}
//	BTree btree;
//	btree.root = btree.generate(v,0,count-1);
//	showtree(btree.root);
//	
//	
//}


//version2.0

//#include<iostream>
//#include<fstream>
//#include<vector>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node *LTree;
//	Node *RTree;
//	Node(int i):data(i)
//	{
//		LTree = RTree = nullptr;
//	}
//	Node()
//	{
//		data = -1;
//		LTree = RTree = nullptr;
//	}
//};
//
//struct BTree
//{
//	Node* root;
//	BTree()
//	{
//		root = nullptr;
//	} 
//	Node* generate(vector<int>&nums,int begin,int end);
//};
//
//int get_index(vector<int>&nums,int begin,int end)
//{
//	int ans = begin;
//	int temp = nums[begin];
//	for(int i = begin;i<=end;i++)
//	{
//		if(nums[i]>temp)
//		{
//			ans = i;
//			temp = nums[i];
//		}
//	}
//	return ans;
//}
//
//Node* BTree::generate(vector<int>&nums,int begin,int end)
//{
//
//	if(begin>end||end<begin) return nullptr;
//	int Max_index = get_index(nums,begin,end);
//	int Max = nums[Max_index];
//	Node *p = new Node(Max);
//	
//	p->LTree = generate(nums,begin,Max_index-1);
//	p->RTree = generate(nums,Max_index+1,end);
//	
//	return p;
//}
//
//
//
//void showtree(Node* root)
//{
//	if(root)
//	{
//		cout<<root->data;
//		if(root->LTree||root->RTree)
//		{
//			cout<<'(';
//			showtree(root->LTree);
//			if(root->RTree)
//			{
//				cout<<',';
//			}
//			showtree(root->RTree);
//			cout<<')';
//		}
//	}
//}
//int main()
//{
////	freopen("in.txt","r",stdin);
//    ifstream in_data("in.txt");
//	int count = 0;
//	int num;	
//	vector<int>nums;
//	for(int i = 0;i<1000;i++)
//	{
//		in_data>>num;
//		nums.push_back(num);
//		count++;
//		if(in_data.eof())
//		{
//			break;
//		}
//	}
////	for(int i = 0;i<count;i++)
////	{
////		cout<<nums[i]<<endl;
////	}
//
//	BTree btree;
//
//	btree.root = btree.generate(nums,0,count-1);
//	showtree(btree.root);
//}




#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Node
{
	int data;
	Node *LTree;
	Node *RTree;
	Node(int i):data(i)
	{
		LTree = RTree = nullptr;
	}
	Node()
	{
		data = -1;
		LTree = RTree = nullptr;
	}
};

struct BTree
{
	Node* root;
	BTree()
	{
		root = nullptr;
	} 
	Node* generate(vector<int>&nums,int begin,int end);
};

int get_index(vector<int>&nums,int begin,int end)
{
	int ans = begin;
	int temp = nums[begin];
	for(int i = begin + 1;i<end;i++)
	{
		if(nums[i]>temp)
		{
			ans = i;
			temp = nums[i];
		}
	}
	return ans;
}

Node* BTree::generate(vector<int>&nums,int begin,int end)
{

	if(begin>=end) return nullptr;
	int Max_index = get_index(nums,begin,end);
	int Max = nums[Max_index];
	Node *p = new Node(Max);
	
	p->LTree = generate(nums,begin,Max_index);
	p->RTree = generate(nums,Max_index+1,end);
	
	return p;
}



void showtree(Node* root)
{
	if(root)
	{
		cout<<root->data;
		if(root->LTree||root->RTree)
		{
			cout<<'(';
			showtree(root->LTree);
			if(root->RTree)
			{
				cout<<',';
			}
			showtree(root->RTree);
			cout<<')';
		}
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
    ifstream in_data("in.txt");
	int count = 0;
	int num;	
	vector<int>nums;
//	for(int i = 0;i<1000;i++)
//	{
//		in_data>>num;
//		nums.push_back(num);
//		count++;
//		if(in_data.eof())
//		{
//			break;
//		}
//	}
    while(in_data>>num)
    {
    	nums.push_back(num);
    	count++;
	}
//	for(int i = 0;i<count;i++)
//	{
//		cout<<nums[i]<<endl;
//	}

	BTree btree;

	btree.root = btree.generate(nums,0,count);
	showtree(btree.root);
}
