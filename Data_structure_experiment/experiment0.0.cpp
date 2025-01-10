//version1.0
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//struct LinkNode //单链表结点类型
//{
//	int data; //存放数据元素
//	LinkNode* next; //下一个结点的指针
//	LinkNode() :next(NULL) { } //构造函数
//	LinkNode(int d)
//	{
//		data = d;
//		next = nullptr;
//	} //重载构造函数
//};
//
//class LinkList //单链表类
//{
//	public:
//	LinkNode* head; //单链表头结点
//	LinkList() //构造函数,创建一个空单链表
//	{
//		head = new LinkNode();
//	}
//	
//	~LinkList() //析构函数,销毁单链表
//	{
//		LinkNode* pre,* p;
//		pre = head; p = pre->next;
//		while (p != NULL) //用p遍历结点并释放其前驱结点
//		{
//			delete pre; //释放pre结点
//			pre = p; p = p->next; //pre,p同步后移一个结点
//		}
//		
//		delete pre; //p为空时pre指向尾结点,此时释放尾结点
//		
//	}
//	
//	void CreateList(vector<int>data);
//	void Sort();
//	void DeletDuplicates();
//	void DispPoly();
//	void Merge(LinkList &A, LinkList &B, LinkList &C);
//	
//};
//
//
//void LinkList::CreateList(vector<int>data) 
//{
//	LinkNode *p , *r;
//	r = head;
//	for(vector<int>::iterator it = data.begin();it!=data.end();it++)
//	{
//		p = new LinkNode(*it);
//		r->next = p;
//		r = p;
//	}
//	r->next = nullptr;
//}	
//
//void LinkList::Sort()
//{
//	LinkNode *pi = head->next;
//	LinkNode *pj = pi->next;
//	if(pi&&pj) return ;
//	while(pi!=nullptr)
//	{
//		pj = pi->next;
//		while(pj!=nullptr)
//		{
//			if(pi->data>pj->data)
//			{
//				swap(pi->data,pj->data);
//			}
//			pj = pj->next;
//		}
//		pi = pi->next;
//	}
//}
//
//void LinkList::DeletDuplicates()
//{
//	LinkNode *p = head->next;
//	while(!p&&!p->next)
//	{
//		if(p->data == p->next->data)
//		{
//			p->next = p->next->next;
//		}
//		p = p->next;
//	}
//}
//
//void LinkList::DispPoly()
//{
//	LinkNode *p = head->next;
//	while(!p)
//	{
//		cout<<p->data<<" ";
//	}
//}
//
//
//void LinkList::Merge(LinkList &A, LinkList &B, LinkList &C)
//{
//	LinkNode *pa = A.head->next;
//	LinkNode *pb = B.head->next;
//	LinkNode *pc = B.head;
//	
//	while(!pa&&!pb)
//	{
//		if(pa->data<pb->data)
//		{
//			pc->next = pa;
//			pc = pa;
//			pa = pa->next;
//		}
//		else if(pa->data>pb->data)
//		{
//			pc->next = pb;
//			pc = pb;
//			pb = pb->next;
//		}
//		else
//		{
//			pc->next = pa;
//			pc = pa;
//			pa = pa->next;
//			pb = pb->next;
//		}
//	}
//	pc->next = nullptr;
//	if(!pa) pc->next = pa;
//	if(!pb) pc->next = pb;	
//}
//
//int main(){
//	int num;
//	vector<int> v1;
//	vector<int> v2;
//	while(cin>>num)
//	{
//		v1.push_back(num);
//		if(cin.get()=='\n') break;
//	}
//	
//	while(cin>>num)
//	{
//		v2.push_back(num);
//	}
//	
//	LinkList L1,L2,ans;
//	L1.CreateList(v1);
//	L2.CreateList(v2);
//	
//	L1.Sort();
//	L2.Sort();
//	
//	L1.DeletDuplicates();
//	L2.DeletDuplicates();
//	
//	ans.Merge(L1,L2,ans);
//	
//	ans.DispPoly();
//	
//	
//}


#include<iostream>
#include<vector>
using namespace std;


struct LinkNode //单链表结点类型
{
	int data; //存放数据元素
	LinkNode* next; //下一个结点的指针
	LinkNode() :next(NULL) { } //构造函数
	LinkNode(int d)
	{
		data = d;
		next = nullptr;
	} //重载构造函数
};

class LinkList //单链表类
{
public:
	LinkNode* head; //单链表头结点
	LinkList() //构造函数,创建一个空单链表
	{
		head = new LinkNode();
	}

	~LinkList() //析构函数,销毁单链表
	{
		LinkNode* pre, * p;
		pre = head; p = pre->next;
		while (p != NULL) //用p遍历结点并释放其前驱结点
		{
			delete pre; //释放pre结点
			pre = p; p = p->next; //pre,p同步后移一个结点
		}

		delete pre; //p为空时pre指向尾结点,此时释放尾结点

	}

	void CreateList(vector<int>data);
	void Sort();
	void DeletDuplicates();
	void DispPoly();
	void Merge(LinkList& A, LinkList& B, LinkList& C);

};


void LinkList::CreateList(vector<int>data)
{
	LinkNode* p, * r;
	r = head;
	for (vector<int>::iterator it = data.begin(); it != data.end(); it++)
	{
		p = new LinkNode(*it);
		r->next = p;
		r = p;
	}
	r->next = nullptr;
}

void LinkList::Sort()
{
	LinkNode* pi = head->next;
	LinkNode* pj = pi->next;
	if (!pi && !pj) return;
	while (pi != nullptr)
	{
		pj = pi->next;
		while (pj != nullptr)
		{
			if (pi->data > pj->data)
			{
				swap(pi->data, pj->data);
			}
			pj = pj->next;
		}
		pi = pi->next;
	}
}

void LinkList::DeletDuplicates()
{
	LinkNode* p = head->next;
	while (p && p->next)
	{
		while(p->next != nullptr&&(p->data == p->next->data))
		{
			p->next = p->next->next;
		}
		p = p->next;
	}
}

void LinkList::DispPoly()
{
	LinkNode* p = head->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}


void LinkList::Merge(LinkList& A, LinkList& B, LinkList& C)
{
	LinkNode* pa = A.head->next;
	LinkNode* pb = B.head->next;
	LinkNode* pc = C.head;

	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pb = pb->next;
		}
	}
	pc->next = nullptr;
	if (pa) pc->next = pa;
	if (pb) pc->next = pb;
}

int main() {
	int num;
	vector<int> v1;
	vector<int> v2;

	while (cin >> num)
	{
		v1.push_back(num);
		if (cin.get() == '\n') break;
	}

	while (cin >> num)
	{
		v2.push_back(num);
		if (cin.get() == '\n') break;
	}

	LinkList L1, L2, ans;
	L1.CreateList(v1);
	L2.CreateList(v2);

	L1.Sort();
	L2.Sort();

	L1.DeletDuplicates();
	L2.DeletDuplicates();



 	ans.Merge(L1, L2, ans);
	ans.DeletDuplicates();


	ans.DispPoly();
	return 0;


}
