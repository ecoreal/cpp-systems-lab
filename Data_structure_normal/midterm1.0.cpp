#include<iostream>
#include<unordered_map>
#include<stdio.h> 
using namespace std;

unordered_map<string,int> address_s;
unordered_map<int,string> next_s;

//freopen("out.txt","w",stdout);

struct LinkNode
{
	string address;
	int value;
	LinkNode *next;
	LinkNode(string s,int i):address(s),value(i),next(nullptr){}
	
	void push(string s ,int i)
	{
		LinkNode *newNode = new LinkNode(s,i);
		this->next = newNode;
		
	}
};

void solution(LinkNode *first)
{
	LinkNode *slow,*fast,*pre; 
	slow = first;
	fast = first;
	pre = nullptr;
	//ÕÒÖÐ¼äÖ¸Õë 
	while(fast&&fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = nullptr;
	
	
	LinkNode *p1 = first;
	LinkNode *p2 = slow;
	pre = nullptr;
	LinkNode *temp = nullptr;
	while(p2)
	{
		temp = p2->next;
		p2->next = pre;
		pre = p2;
		p2 = temp;
	}
	p2 = pre;
	
	LinkNode *ans = p2;
	while(p1&&p2)
	{
		LinkNode *temp_p1 = p1->next;
		LinkNode *temp_p2 = p2->next;
		
		p2->next = p1;
		p1->next = temp_p2;
		
		p1 = temp_p1; 
		p2 = temp_p2;
	}
	
	while(ans)
	{
		
		cout<<ans->address<<" "<<ans->value<<" ";
		if(!ans->next)cout<<-1<<endl;
		else cout<<ans->next->address<<endl;
		ans = ans->next;
	}
	
}

int main()
{
	//freopen("in.txt","r",stdin);
	string first_address;
	int first_value;
	int num;
	cin>>first_address>>num;
	string s1,s2;
	int value_num;
	
	
	
	for(int i = 0;i<num;i++)
	{
		cin>>s1>>value_num>>s2;
		address_s[s1] = value_num;
		next_s[value_num] = s2;
	}
	
	first_value = address_s[first_address];
	LinkNode *first = new LinkNode(first_address,first_value);
	LinkNode *temp = first;
	
	for(int i = 1;i<num;i++)
	{
		first_address = next_s[first_value];
		first_value = address_s[first_address];
		temp->push(first_address,first_value);
		temp = temp->next;
	}
//	while(first)
//	{
//		cout<<first->address<<" "<<first->value<<endl;
//		first = first->next;
//	}

    solution(first);
	
}


