#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	int val;
	Node *LTree;
	Node *RTree;
	
	Node(int i):val(i)
	{
		LTree = RTree = nullptr;
	}
	Node():val(0),LTree(nullptr),RTree(nullptr){};
	
};

struct BTree
{
	Node *root;
	BTree()
	{
		root = nullptr;
	}
	void initial(string s);
	int is_cbt();
};

void BTree::initial(string s)
{
	Node *temp = nullptr;
	int i = 0;
	int flag = 0;
	vector<Node *>v;
	while(i<(int)s.length())
	{
		switch(s[i])
		{
			case'(':
				v.push_back(temp);
				flag = 0;
				break;
			case',':
				flag = 1;
				break;
			case')':
				v.pop_back();
				break;
			default:
				int total = 0;
				while(s[i]>='0'&&s[i]<='9')
				{
					total = total*10 + (s[i] - '0');
					i++;
				}
				temp = new Node(total);
				if(!root)
				{
					root = temp;
				}
				else
				{
					if(flag == 0&&!v.empty()) v.back()->LTree = temp;
					else if(!v.empty()) v.back()->RTree = temp;
				}
				i--; 
		}
		i++;
	}
}

int BTree::is_cbt()
{
	int ans = 1;
	queue<Node*>q;
	q.push(root);
	Node *temp = nullptr;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(!temp) break;
		else
		{
			q.push(temp->LTree);
			q.push(temp->RTree);
		}
	}
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp != nullptr) ans = 0;
	}
	
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	BTree btree;
	string s;
	cin>>s;
	
	
	btree.initial(s);
	cout<<btree.is_cbt();
 
} 
