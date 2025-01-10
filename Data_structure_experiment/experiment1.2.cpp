#include<iostream>
using namespace std;

struct Node
{
	char data;
	Node *Ltree;
	Node *Rtree;
	Node(char c):data(c)
	{
		Ltree = Rtree = nullptr;
	}
	Node()
	{
		data = '#';
		Ltree = Rtree = nullptr;
	}
};


Node *generate(Node* &root,string &s)
{
	char data = s[0];
	s.erase(0,2);
	int i = 0;
	Node *p = root;
	
	while(i<(int)s.length())
	{
		switch(s[i])
		{
			case'0':
                if(!p->Ltree)
                {
                    p->Ltree = new Node('#');
                }
				p = p->Ltree;
				break;
			case'1':
                if(!p->Rtree)
                {
                    p->Rtree = new Node('#');
                }
				p = p->Rtree;
				break;
		}
		i++;
	}
	p->data = data;
	return root;
	
};
void display(Node *root,string s)
{
    int i = 0;
    while(i<(int)s.length())
    {
        Node *p = root;
        while(i<(int)s.length())
        {
            switch(s[i])
            {
            case '0':
                p = p->Ltree;
                break;
            case '1':
                p = p->Rtree;
                break;
            }
            if((!p->Ltree)&&(!p->Rtree))
            {
                cout<<p->data;
                i++;
                break;
            }
            i++;
        }
    }

}

int main()
{
	
	int num;
	cin>>num;
	string s;
	Node *root = new Node('#');
	while(num--)
	{
		cin>>s;
		root = generate(root,s);
	}
	freopen("in.txt","r",stdin); 

    cin>>s;

    display(root,s);
 } 
