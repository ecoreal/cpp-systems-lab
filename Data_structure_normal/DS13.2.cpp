#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<string>s;

struct Node
{
	string val;
	Node* left;
	Node* right;
	Node(string s)
	{
		val = s;
		left = right = nullptr;
	}
	
	Node()
	{
		val = "null";
		left = right = nullptr;
	}
};

int check(Node*p)
{
	int ans = 0;
	if(p==nullptr||p->val =="null")
	{
		return ans;
	}
	
	int left_val = check(p->left);
	if(left_val==-1) return -1;
	
	int right_val = check(p->right);
	if(right_val==-1) return -1;
	 
	if(abs(left_val-right_val)>1) return -1;
	
	ans = max(left_val,right_val)+1;
	return ans; 
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	string s_temp;
	queue<Node*>q;
	while(cin>>s_temp)
	{
		s.push(s_temp);
	}
	
	Node *root = new Node(s.front());
	s.pop();
	q.push(root);
	Node* temp = nullptr;
	
	while(!s.empty())
	{
		temp = q.front();
		q.pop();
		temp->left =new Node(s.front());
		s.pop();
		if(!s.empty())
		{
			temp->right = new Node(s.front());
			s.pop();
		}
		
//		temp->right = s.empty()?nullptr:new Node(s.front());
//		s.pop();
		
		q.push(temp->left);
		q.push(temp->right);
	}
	int is_balance = check(root);
    if(is_balance==-1)
    {
        puts("False");
    }
    else
    {
        puts("True");
    }
    
    return 0;

}


