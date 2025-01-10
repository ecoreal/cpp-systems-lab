//#include<iostream>
//#include<sstream>
//#include<string>
//#include<fstream>
//using namespace std;
//
//class LinkNode
//{
//public:
//	double data;
//	LinkNode *next;
//	LinkNode():next(nullptr){};
//	LinkNode(double d):data(d),next(nullptr){};
//	
//};
//
//class STACK
//{
//public:
//	LinkNode *head;
//	
//	STACK();
//	~STACK();
//	
//	bool empty();
//	bool push(double e);
//	bool pop(double &e);
//	bool getpop(double &e);
//	
//	
//	
//};
//
//STACK::STACK()
//{
//	head = new LinkNode();
//}
//
//STACK::~STACK()
//{
//	LinkNode *pre = head , *p = pre->next;
//	
//	while(!p)
//	{
//		delete pre;
//		pre = p; p = p->next;
//	}
//	delete pre;
//}
//
//bool STACK::empty()
//{
//	return head->next==nullptr;
//}
//
//bool STACK::push(double e)
//{
//	LinkNode *p = new LinkNode(e);
//	p->next = head->next;
//	head->next = p;
//	return true;
//}
//
//bool STACK::pop(double &e)
//{
//	if(this->empty()) return false;
//	LinkNode *p ;
//	
//	p = head->next;
//	head->next = p->next;
//	
//	e = p->data;
//	delete p;
//	return true;
//}
//
//bool STACK::getpop(double &e)
//{
//	if(this->empty()) return false;
//	
//	e = head->next->data;
//	return true;
//}
//
//
//class Express
//{
//public:
//	string postexp;
//
//	Express (string str);
//	double GetValue();
//};
//
//Express::Express(string str)
//{
//	postexp = str;
//}
//
//double Express::GetValue()
//{
//	STACK opand;
//	double a = 0,b = 0,c = 0,d = 0,ans = 0;
//	char ch;
//	int i = 0;
//	while(i<postexp.length())
//	{
//		ch = postexp[i];
//		switch(ch)
//		{
//			case'+':
//				opand.pop(a);
//				opand.pop(b);
//			    c = a + b;
//			    opand.push(c);
//			    break;
//			
//			case'-':
//				opand.pop(a);
//				opand.pop(b);
//			    c = a - b;
//			    opand.push(c);
//			    break;
//			
//			case'*':
//				opand.pop(a);
//				opand.pop(b);
//			    c = a * b;
//			    opand.push(c);
//			    break;
//			
//			case'/':
//				opand.pop(a);
//				opand.pop(b);
//			    c = a / b;
//			    opand.push(c);
//			    break;
//			    
//			default:
//				d = 0;
//				while(ch>='0'&&ch<='9')
//				{
//					d = d*10 +(ch-'0');
//					i++;
//					ch = postexp[i];
//				}
//				opand.push(d);
//				break;	
//		}
//		i++;
//	}
//	
//	opand.getpop(ans);
//	return ans;
//	
//}
//int main()
//{
//	ifstream in_data("in.txt");
//	
//	string line;
//	getline(in_data,line);
//	
//	string str;
//	for(auto c:line)
//	{
//		if(c!=',')
//		{
//			str.push_back(c);
//		}
//	}
//	
//	Express solution(str);
//	
//	cout<<solution.GetValue()<<endl;	
//
//	
//}



#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

class LinkNode
{
public:
	int data;
	LinkNode* next;
	LinkNode() :next(nullptr) {};
	LinkNode(int d) :data(d), next(nullptr) {};

};

class STACK
{
public:
	LinkNode* head;

	STACK();
	~STACK();

	bool empty();
	bool push(int e);
	bool pop(int& e);
	bool getpop(int& e);



};

STACK::STACK()
{
	head = new LinkNode();
}

STACK::~STACK()
{
	LinkNode* pre = head, * p = pre->next;

	while (!p)
	{
		delete pre;
		pre = p; p = p->next;
	}
	delete pre;
}

bool STACK::empty()
{
	return head->next == nullptr;
}

bool STACK::push(int e)
{
	LinkNode* p = new LinkNode(e);
	p->next = head->next;
	head->next = p;
	return true;
}

bool STACK::pop(int& e)
{
	if (this->empty()) return false;
	LinkNode* p;

	p = head->next;
	head->next = p->next;

	e = p->data;
	delete p;
	return true;
}

bool STACK::getpop(int& e)
{
	if (this->empty()) return false;

	e = head->next->data;
	return true;
}


class Express
{
public:
	string postexp;

	Express(string str);
	int GetValue();
};

Express::Express(string str)
{
	postexp = str;
}

int Express::GetValue()
{
	STACK opand;
	int a = 0, b = 0, c = 0, d = 0, ans = 0;
	char ch;
	int i = 0;
	
	while (i < (int)postexp.length())
	{
		ch = postexp[i];
		switch (ch)
		{
		case',':
			break;

		case'+':
			opand.pop(a);
			opand.pop(b);
			c = b + a;
			opand.push(c);
			break;

		case'-':
			if(postexp[i+1]==','||postexp[i+1]=='\0')
			{
				opand.pop(a);
			    opand.pop(b);
		    	c = b - a;;
		    	opand.push(c);
		    	break;
		    }
		    else break;
	
		case'*':
			opand.pop(a);
		    opand.pop(b);
		    c = b * a;
		    opand.push(c);
		    break;
			

		case'/':
			opand.pop(a);
			opand.pop(b);
			c = b / a;
			opand.push(c);
			break;

		default:
			if(i==0)
			{
				d = 0;
		    	while (ch >= '0' && ch <= '9')
		    	{
					d = d * 10 + (ch - '0');
					i++;
					ch = postexp[i];
				}
				opand.push(d);
				break;
			}
			
			else 
			{
				if(postexp[i-1]==',')
				{
					d = 0;
			    	while (ch >= '0' && ch <= '9')
			    	{
						d = d * 10 + (ch - '0');
						i++;
						ch = postexp[i];
					}
					opand.push(d);
					break;
				}
				
				else if(postexp[i-1]=='-')
				{
					d = 0;
			    	while (ch >= '0' && ch <= '9')
			    	{
						d = d * 10 + (ch - '0');
						i++;
						ch = postexp[i];
					}
					d = -d; 
					opand.push(d);
					break;
				}	
				
			}	
			
		}
		
		i++;
	}

	opand.getpop(ans);
	return ans;

}
int main()
{
	ifstream in_data("in.txt");

	string line;
	getline(in_data, line);

	Express solution(line);
	
	cout << solution.GetValue() << endl;


}
