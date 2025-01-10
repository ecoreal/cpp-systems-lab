#include<iostream>
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
	Node():data(-1),LTree(nullptr),RTree(nullptr){};
};

struct BTree
{
	Node *root;
	BTree():root(nullptr){};
	Node* generate(vector<int>pres,int i,vector<int>,int j,int n);

};

Node* BTree::generate(vector<int>pres,int i,vector<int>ins,int j,int n)
{
	if(n<=0) return nullptr;
	int temp = pres[i];
	Node* p = new Node(temp);
	int m = j;
	while(ins[m]!=temp)m++;
	int k = m-j;
	
	p->LTree = generate(pres,i+1,ins,j,k);
	p->RTree = generate(pres,i+k+1,ins,m+1,n-k-1);
	
	return p;
	
}

void display_post(Node *p)
{
	if(!p) return;
	
	display_post(p->LTree);
	display_post(p->RTree);
	cout<<p->data<<" ";	
} 


int main()
{
	freopen("in.txt","r",stdin);
	int n;
	int temp;
	cin>>n;
	vector<int>pres;
	vector<int>ins;
	for(int i = 0;i<n;i++)
	{
		cin>>temp;
		pres.push_back(temp);
	}
	
	for(int i = 0;i<n;i++)
	{
		cin>>temp;
		ins.push_back(temp);
	}
	BTree btree;
	btree.root = btree.generate(pres,0,ins,0,n);
	display_post(btree.root);
	
 } 
