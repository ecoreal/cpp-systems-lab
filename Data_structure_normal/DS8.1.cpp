#include<iostream> 
#include<stack>
#include<vector>
#include<queue>
using namespace std;

struct BTNode
{
	int data;
	BTNode *LTree;
	BTNode *RTree;
	BTNode():data('#'),LTree(nullptr),RTree(nullptr){};
	BTNode(int c)
	{
		data = c;
		LTree = RTree = nullptr;
	}
};

struct BTree
{
	BTNode *root;
	BTree()
	{
		root = nullptr;
	}
	void initial(string s);
};

void BTree::initial(string s)
{
//	stack<BTNode *>st; 
    vector<BTNode*>v;
	BTNode *p = nullptr;
	int flag = 0;
	int i = 0;
//	BTNode *temp = nullptr;
	while(i<(int)s.length())
	{
		switch(s[i])
		{
			case'(':
				//st.push(p);
				v.push_back(p);
				flag = 0;
				break;
			case')':
				v.pop_back();
				break;
			case',':
				flag = 1;
				break;
			default:
				int total = 0;
				while(s[i]>='0'&&s[i]<='9')
				{
					total = total *10 +(s[i] -'0');
					i++;
				}
				p = new BTNode(total);
				if(!root)
				{
					root = p;
				}
				else
				{
//					temp = st.top();
					if((flag == 0)&&(!v.empty()))		v.back()->LTree = p;
					else if(!v.empty())                 v.back()->RTree = p;
				}
				i--;
		    
		}
		i++;
	}
}

void display_one(BTNode *p)
{
	if(p)
	{
		if((!p->LTree)&&(!p->RTree))
		{
			cout<<p->data<<" ";
		}
		display_one(p->LTree);
		display_one(p->RTree);
	} 
}

void display_two(BTNode *p)
{
	if(p)
	{
		if((!p->LTree)&&(!p->RTree))
		{
			cout<<p->data<<" ";
		}
		display_two(p->RTree);
		display_two(p->LTree);
    }
}


void display_three(BTNode *p)
{
	queue<BTNode*>q;
	if(!p) return ;
	q.push(p);
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			BTNode *temp = q.front();
			cout<<temp->data<<" ";
			if(temp->RTree) q.push(temp->RTree);
			if(temp->LTree) q.push(temp->LTree);
			q.pop();
		}
	}
	return ;
}

void display(BTree &bt)
{
	BTNode *p = bt.root;
	display_one(p);
	cout<<endl;
	
	display_two(p);
	cout<<endl;
	
	display_three(p);
}

int main()
{
	
	freopen("in.txt","r",stdin);
	string s;
	cin>>s;
	BTree bt;
	
	bt.initial(s);
	display(bt);
	
}
