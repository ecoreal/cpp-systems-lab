//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int>v1;
//struct Node
//{
//	int data;
//	Node* left;
//	Node* right;
//	Node()
//	{
//		data = -1;
//		left = right = nullptr;
//	}
//	Node(int i)
//	{
//		data = i;
//		left = right = nullptr;
//	}
//	void insert(Node* p)
//	{
//		Node* temp = this;
//		while(temp)
//		{
//			if(p->data<this->data)
//			{
//				temp = temp->left;
//			}
//			else
//			{
//				temp = temp->right;
//			}
//		}
//		temp = p;
//		
//	}
//};
//
//
//void display(Node* p)
//{
//	if(!p) return;
//	v1.push_back(p->data);
//	display(p->left);
//	display(p->right);
//}
//
//int main()
//{
//	freopen("in.txt","r",stdin);
//	int n;
//	cin>>n;
//	int num;
//	Node *root = nullptr;
//	
//	while(n--)
//	{
//		cin>>num;
//		Node *temp = nullptr;
//		temp = new Node(num);
//		if(!root)
//		{
//			root = temp;
//		}
//		else
//		{
//			root->insert(temp);
//		}
//	}
//	for(auto &a:v1) printf("%d ",a); 
//	
//	
//}



#include<iostream>
#include<vector>
using namespace std;

vector<int>v1;
//vector<int>v2;
int count = 0;
int goal;
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node()
	{
		data = -1;
		left = right = nullptr;
	}
	Node(int i)
	{
		data = i;
		left = right = nullptr;
	}
	
};

void insert(Node*& root,Node* p)
{
    if(!root)
    {
        root = p;
        return;
    }
    if(p->data<root->data)
    {
        insert(root->left,p);
    }
    else
    {
        insert(root->right,p);
    }
    return;
    
}

void display(Node* p)
{
	if(!p) return;
	v1.push_back(p->data);
	display(p->left);
	display(p->right);
}

void find(Node*p)
{
    if(p->data==goal)
    {
        count++;
        return;
    }
    if(p->data<goal)
    {
        count++;
        find(p->right);
    }
    else
    {
        count++;
        find(p->left);
    }

}

void quicksort_first()
{
    int base = v1[0];
    int i = 0;
    int j = v1.size()-1;
    while(i<j)
    {
        while(i<j&&v1[j]>=base)
        {
            j--;
        }
        if(i<j)
        {
            v1[i] = v1[j];
            i++;
        }

        while(i<j&&v1[i]<=base)
        {
            i++;
        }
        if(i<j)
        {
            v1[j] = v1[i];
            j--;
        }
    }
    v1[i] = base;

}
int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	int num;
	Node *root = nullptr;
	
	while(n--)
	{
		cin>>num;
		Node *temp = nullptr;
		temp = new Node(num);
		if(!root)
		{
			root = temp;
		}
		else
		{
			insert(root,temp);
		}
	}
    cin>>goal;

    find(root);
    printf("%d",count);
    puts("");
    display(root);
	for(auto &a:v1) printf("%d ",a);
    puts("");

    quicksort_first();
    for(auto &a:v1) printf("%d ",a); 

	
	
}

