#include<iostream>
#include<vector>
using namespace std;

vector<int>v1;
//vector<int>v2;
int count = 0;
int goal;
int depth = 0;
int depth0 = 0;
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
        depth0++;
        root = p;
        return;
    }
    if(p->data<root->data)
    {
        depth0++;
        insert(root->left,p);
        
    }
    else
    {
        depth0++;
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

void swap(int& a,int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void big_stack_assistant(int i,int n)
{
    int current = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<=n&&v1[current]<v1[left])
    {
        current = left;
    }
    if(right<=n&&v1[current]<v1[right])
    {
        current = right;
    }

    if(current !=i)
    {
        swap(v1[i],v1[current]);
        big_stack_assistant(current,n);
    }
}

void big_stack()
{
    int n = v1.size()-1;
    for(int i = (n-1)/2;i>=0;i--)
    {
        big_stack_assistant(i,n);
    }
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
            depth0 = 0;
			insert(root,temp);
            depth = max(depth,depth0);
		}
	}
    cin>>goal;
    printf("%d",depth);
    puts("");

    find(root);
    printf("%d",count);
    puts("");

    display(root);
	// for(auto &a:v1) printf("%d ",a);
    //puts("");

    // quicksort_first();
    // for(auto &a:v1) printf("%d ",a); 

    big_stack();
    for(auto &a:v1) printf("%d ",a);


	
	
}

