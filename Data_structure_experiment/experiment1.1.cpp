//final_version
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
string s;

struct Node
{
	string data;
	Node *Ltree;
	Node *Rtree;
	Node(string c):data(c)
	{
		Ltree = Rtree = nullptr;
	};
	
	Node():data("#")
	{
		Ltree = Rtree = nullptr;
	}
};

string creat_postexp(const string &s)
{
	stack<char>st;
	string postexp = "";
	char e;
	for(int i = 0;i<(int)s.length();i++)
	{
		char c = s[i]; 
		
		if(c == '(')
		{
			st.push(c);
		}
		
		else if(c == ')')
		{
			while(!st.empty()&& st.top()!='(')
			{
				e = st.top();
				st.pop();
				postexp += e;
				postexp += '#';
			} 
			st.pop();
		} 
		else if(c =='+'||c =='-')
		{
			while(!st.empty() && st.top() != '(')
			{
				e = st.top();
				st.pop();
				postexp += e;
				postexp += '#';
			}
			st.push(c);
		}
		else if(c =='*'||c =='/')
		{
			while(!st.empty() && st.top() != '('&&(st.top() == '*'||st.top() == '/'))
			{
				e = st.top();
				st.pop();
				postexp += e;
				postexp += '#';
			}
			st.push(c);
		}
		else if(c == ' ')
		{
			
		}
		else
		{
			string d = "";
			while(c>='0'&&c<='9')
			{
				d += c;
				i++;
				c = s[i];
			}
			i--;
			postexp += d;
			postexp += "#";
		}
	}
	while(!st.empty() && st.top() != '(')
	{
		e = st.top();
		st.pop();
		postexp += e;
		postexp += '#';
	}
	return postexp;
}



int calculate(const string &postexp)
{
	stack<int> opand;
	int a, b, c, d;
	char ch;
	int i = 0;

	while (i < (int)postexp.length())
	{
		ch = postexp[i];
		switch (ch)
		{
		case '+':
			a = opand.top(); opand.pop();
			b = opand.top(); opand.pop();
			c = b + a;
			opand.push(c);
			break;
		case '-':
			if (postexp[i + 1] == '#' || postexp[i + 1] == '\0')
			{
				a = opand.top(); opand.pop();
				b = opand.top(); opand.pop();
				c = b - a;
				opand.push(c);
				break;
			}
			else break;

		case '*':
			a = opand.top(); opand.pop();
			b = opand.top(); opand.pop();
			c = b * a;
			opand.push(c);
			break;
		case '/':
			a = opand.top(); opand.pop();
			b = opand.top(); opand.pop();
			c = b / a;
			opand.push(c);
			break;
		case'#':
			break;

		default:
			if (i == 0)
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
				if (postexp[i - 1] == '#')
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

				else if (postexp[i - 1] == '-')
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

	return  opand.top();
}

void pre_display(Node *root)
{
	if(root)
	{
		cout<<root->data;
		if(isdigit(root->data[0]))
		cout<<"#";
		
		pre_display(root->Ltree);
		
		pre_display(root->Rtree);
	}
}

void in_display(Node *root)
{
	if(root)
	{
		in_display(root->Ltree);
		
		cout<<root->data;
		if(isdigit(root->data[0]))
		cout<<"#";
	
		in_display(root->Rtree);
	}
}
void post_display(Node *root)
{
	if(root)
	{
		post_display(root->Ltree);
	
		post_display(root->Rtree);
		
		cout<<root->data;
		if(isdigit(root->data[0]))
		cout<<"#";
	}	
}

void lo_display(Node *root)
{
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node *cur = q.front();
		q.pop();
		cout<<cur->data;
		if(isdigit(cur->data[0]))
		cout<<"#";
		
		if(cur->Ltree) q.push(cur->Ltree);
		if(cur->Rtree) q.push(cur->Rtree);
	}
}

Node* creat_tree(string s)
{
	vector<string>v;
	int i = 0;
	int count = 0;
	while(i<(int)s.length())
	{
		string s0 = "";
		while(i<(int)s.length())
		{
			if(s[i]!='#')
			{
				s0+=s[i];
				i++;
			}
			else if(s[i]=='#')
			{
				v.push_back(s0);
				count++;
				i++;
				break;
			}
		}
	}

	Node *temp = nullptr;
	stack<Node*>st;
	for(int i = 0;i<count;i++)
	{
		temp = new Node(v[i]);
		if(!isdigit(v[i][0]))
		{
			temp->Rtree = st.top();
			st.pop();
			temp->Ltree = st.top();
			st.pop();
			st.push(temp);
		}
		else
		{
			st.push(temp);
		}
	}
	return st.top();

}

int main()
{
	
//	freopen("in.txt","r",stdin);
	string s0;
	getline(cin,s0,'=');
	
	Node* root;
	string postexp = creat_postexp(s0);
	s = postexp;
	int result = calculate(s);
	
//	cout<<s<<endl; 
	
	
	root = creat_tree(s);
	
	pre_display(root);
	cout<<endl;
	
	in_display(root);
	cout<<endl;
	
	post_display(root);
	cout<<endl;
	
	lo_display(root);
	cout<<endl;
	
	cout<<result<<endl;
	
	
 } 

////version3.0 
//#include<iostream>
//#include<vector>
//#include<stack>
//#include<algorithm>
//#include<queue>
//using namespace std;
//string s;
//
//struct Node
//{
//	string data;
//	Node *Ltree;
//	Node *Rtree;
//	Node(string c):data(c)
//	{
//		Ltree = Rtree = nullptr;
//	};
//	
//	Node():data("#")
//	{
//		Ltree = Rtree = nullptr;
//	}
//};
//
//string creat_postexp(const string &s)
//{
//	stack<char>st;
//	string postexp = "";
//	char e;
//	for(int i = 0;i<(int)s.length();i++)
//	{
//		char c = s[i]; 
//		
//		if(c == '(')
//		{
//			st.push(c);
//		}
//		
//		else if(c == ')')
//		{
//			while(!st.empty()&& st.top()!='(')
//			{
//				e = st.top();
//				st.pop();
//				postexp += e;
//				postexp += '#';
//			} 
//			st.pop();
//		} 
//		else if(c =='+'||c =='-')
//		{
//			while(!st.empty() && st.top() != '(')
//			{
//				e = st.top();
//				st.pop();
//				postexp += e;
//				postexp += '#';
//			}
//			st.push(c);
//		}
//		else if(c =='*'||c =='/')
//		{
//			while(!st.empty() && st.top() != '('&&(st.top() == '*'||st.top() == '/'))
//			{
//				e = st.top();
//				st.pop();
//				postexp += e;
//				postexp += '#';
//			}
//			st.push(c);
//		}
//		else if(c == ' ')
//		{
//			
//		}
//		else
//		{
//			string d = "";
//			while(c>='0'&&c<='9')
//			{
//				d += c;
//				i++;
//				c = s[i];
//			}
//			i--;
//			postexp += d;
//			postexp += "#";
//		}
//	}
//	while(!st.empty() && st.top() != '(')
//	{
//		e = st.top();
//		st.pop();
//		postexp += e;
//		postexp += '#';
//	}
//	return postexp;
//}
//
//
//
//int calculate(const string &postexp)
//{
//	stack<int> opand;
//	int a, b, c, d;
//	char ch;
//	int i = 0;
//
//	while (i < (int)postexp.length())
//	{
//		ch = postexp[i];
//		switch (ch)
//		{
//		case '+':
//			a = opand.top(); opand.pop();
//			b = opand.top(); opand.pop();
//			c = b + a;
//			opand.push(c);
//			break;
//		case '-':
//			if (postexp[i + 1] == '#' || postexp[i + 1] == '\0')
//			{
//				a = opand.top(); opand.pop();
//				b = opand.top(); opand.pop();
//				c = b - a;
//				opand.push(c);
//				break;
//			}
//			else break;
//
//		case '*':
//			a = opand.top(); opand.pop();
//			b = opand.top(); opand.pop();
//			c = b * a;
//			opand.push(c);
//			break;
//		case '/':
//			a = opand.top(); opand.pop();
//			b = opand.top(); opand.pop();
//			c = b / a;
//			opand.push(c);
//			break;
//		case'#':
//			break;
//
//		default:
//			if (i == 0)
//			{
//				d = 0;
//				while (ch >= '0' && ch <= '9')
//				{
//					d = d * 10 + (ch - '0');
//					i++;
//					ch = postexp[i];
//				}
//				opand.push(d);
//				break;
//			}
//
//			else
//			{
//				if (postexp[i - 1] == '#')
//				{
//					d = 0;
//					while (ch >= '0' && ch <= '9')
//					{
//						d = d * 10 + (ch - '0');
//						i++;
//						ch = postexp[i];
//					}
//					opand.push(d);
//					break;
//				}
//
//				else if (postexp[i - 1] == '-')
//				{
//					d = 0;
//					while (ch >= '0' && ch <= '9')
//					{
//						d = d * 10 + (ch - '0');
//						i++;
//						ch = postexp[i];
//					}
//					d = -d;
//					opand.push(d);
//					break;
//				}
//
//			}
//
//		}
//
//		i++;
//	}
//
//	return  opand.top();
//}
//
//void pre_display(Node *root)
//{
//	if(root)
//	{
//		cout<<root->data;
//		if(isdigit(root->data[0]))
//		cout<<"#";
//		
//		pre_display(root->Ltree);
//		
//		pre_display(root->Rtree);
//	}
//}
//
//void in_display(Node *root)
//{
//	if(root)
//	{
//		in_display(root->Ltree);
//		
//		cout<<root->data;
//		if(isdigit(root->data[0]))
//		cout<<"#";
//	
//		in_display(root->Rtree);
//	}
//}
//void post_display(Node *root)
//{
//	if(root)
//	{
//		post_display(root->Ltree);
//	
//		post_display(root->Rtree);
//		
//		cout<<root->data;
//		if(isdigit(root->data[0]))
//		cout<<"#";
//	}	
//}
//
//void lo_display(Node *root)
//{
//	if(!root) return;
//	queue<Node*> q;
//	q.push(root);
//	
//	while(!q.empty())
//	{
//		Node *cur = q.front();
//		q.pop();
//		cout<<cur->data;
//		if(isdigit(cur->data[0]))
//		cout<<"#";
//		
//		if(cur->Ltree) q.push(cur->Ltree);
//		if(cur->Rtree) q.push(cur->Rtree);
//	}
//}
//
//Node* creat_tree(string s)
//{
//	vector<string>v;
//	int i = 0;
//	int count = 0;
//	while(i<(int)s.length())
//	{
//		string s0 = "";
//		while(i<(int)s.length())
//		{
//			if(s[i]!='#')
//			{
//				s0+=s[i];
//				i++;
//			}
//			else if(s[i]=='#')
//			{
//				v.push_back(s0);
//				count++;
//				i++;
//				break;
//			}
//		}
//	}
//
//	Node *temp = nullptr;
//	stack<Node*>st;
//	for(int i = 0;i<count;)
//	{
//		if(isdigit(v[i][0])&&isdigit(v[i+1][0])&&!isdigit(v[i+2][0]))
//		{
//			temp = new Node(v[i+2]);
//			temp->Rtree = new Node(v[i+1]);
//			temp->Ltree = new Node(v[i]);
//			st.push(temp);
//			i+=3;
//		}
//		else if(st.size()>=2)
//		{
//			temp = new Node(v[i]);
//			temp->Rtree = st.top();
//			st.pop();
//			temp->Ltree = st.top();
//			st.pop();
//			st.push(temp);
//			i++;
//		}
//		//(st.size()==1)
//		else
//		{
//			temp = new Node(v[i]);
//			st.push(temp);
//			i++;
//		}
//		// else if
//		// {
//		// 	temp = new Node(v[i]);
//		// 	st.push(temp);
//		// }
//	}
//	return st.top();
//
//}
//
//int main()
//{
//	
////	freopen("in.txt","r",stdin);
//	string s0;
//	getline(cin,s0,'=');
//	
//	Node* root;
//	string postexp = creat_postexp(s0);
//	s = postexp;
//	int result = calculate(s);
//	
////	cout<<s<<endl; 
//	
//	
//	root = creat_tree(s);
//	
//	pre_display(root);
//	cout<<endl;
//	
//	in_display(root);
//	cout<<endl;
//	
//	post_display(root);
//	cout<<endl;
//	
//	lo_display(root);
//	cout<<endl;
//	
//	cout<<result<<endl;
//	
//	
// } 
//
//
//////version2.0 
////#include<iostream>
////#include<vector>
////#include<stack>
////#include<algorithm>
////#include<queue>
////using namespace std;
////string s;
////
////struct Node
////{
////	string data;
////	Node *Ltree;
////	Node *Rtree;
////	Node(string c):data(c)
////	{
////		Ltree = Rtree = nullptr;
////	};
////	
////	Node():data("#")
////	{
////		Ltree = Rtree = nullptr;
////	}
////};
////
////string creat_postexp(const string &s)
////{
////	stack<char>st;
////	string postexp = "";
////	char e;
////	for(int i = 0;i<(int)s.length();i++)
////	{
////		char c = s[i]; 
////		
////		if(c == '(')
////		{
////			st.push(c);
////		}
////		
////		else if(c == ')')
////		{
////			while(!st.empty()&& st.top()!='(')
////			{
////				e = st.top();
////				st.pop();
////				postexp += e;
////				postexp += '#';
////			} 
////			st.pop();
////		} 
////		else if(c =='+'||c =='-')
////		{
////			while(!st.empty() && st.top() != '(')
////			{
////				e = st.top();
////				st.pop();
////				postexp += e;
////				postexp += '#';
////			}
////			st.push(c);
////		}
////		else if(c =='*'||c =='/')
////		{
////			while(!st.empty() && st.top() != '('&&(st.top() == '*'||st.top() == '/'))
////			{
////				e = st.top();
////				st.pop();
////				postexp += e;
////				postexp += '#';
////			}
////			st.push(c);
////		}
////		else if(c == ' ')
////		{
////			
////		}
////		else
////		{
////			string d = "";
////			while(c>='0'&&c<='9')
////			{
////				d += c;
////				i++;
////				c = s[i];
////			}
////			i--;
////			postexp += d;
////			postexp += "#";
////		}
////	}
////	while(!st.empty() && st.top() != '(')
////	{
////		e = st.top();
////		st.pop();
////		postexp += e;
////		postexp += '#';
////	}
////	return postexp;
////}
////
////Node* creat_tree(string &s)
////{
////	
////	int i = 0;
////	//v只存储数字 
////	vector<Node*>v;
////	//st里面存储节点 
////	stack<Node*>st;
////	
////	Node *temp;
//////	bool falg = false;
////	
////	while(i<(int)s.length())
////	{
////		while(s[i]=='#')
////		{
////			i++;
////		}
////		if(s[i]=='\000')
////		break;
////		
////		char c = s[i];
////		string s0 ="";
////	    while(c!='#')
////	    {
////	    	s0+=c;
////	    	i++;
////	    	c = s[i];
////		}
////		
////		temp = new Node(s0);
////		
////		if(v.size()==2)
////		{
////			Node *n1 = v.back();
////			v.pop_back();
////			Node *n2 = v.back();
////			v.pop_back();
////			temp->Rtree = n1;
////			temp->Ltree = n2;
////			st.push(temp);
////		}
////		else if(v.size()==1)
////		{
////			//因为只有接下来是两个数字我才会放入一个数字节点 
////			v.push_back(temp);
////		}
////		
////		else
////		{
////			if(isdigit(s0[0]))
////			{
////				if(isdigit(s[i+1]))
////				{
////					v.push_back(temp);
////				}
////				else
////				{
////					st.push(temp);
////					
////				} 
////			}
////			else
////			{
////				temp->Rtree = st.top();
////				st.pop();
////				temp->Ltree = st.top();
////				st.pop();
////				st.push(temp);
////				
////			}
////			
////		}
////		
////		continue;
////	}
////	return st.top();
////}
////
////int calculate(const string &postexp)
////{
////	stack<int> opand;
////	int a, b, c, d;
////	char ch;
////	int i = 0;
////
////	while (i < (int)postexp.length())
////	{
////		ch = postexp[i];
////		switch (ch)
////		{
////		case '+':
////			a = opand.top(); opand.pop();
////			b = opand.top(); opand.pop();
////			c = b + a;
////			opand.push(c);
////			break;
////		case '-':
////			if (postexp[i + 1] == '#' || postexp[i + 1] == '\0')
////			{
////				a = opand.top(); opand.pop();
////				b = opand.top(); opand.pop();
////				c = b - a;
////				opand.push(c);
////				break;
////			}
////			else break;
////
////		case '*':
////			a = opand.top(); opand.pop();
////			b = opand.top(); opand.pop();
////			c = b * a;
////			opand.push(c);
////			break;
////		case '/':
////			a = opand.top(); opand.pop();
////			b = opand.top(); opand.pop();
////			c = b / a;
////			opand.push(c);
////			break;
////		case'#':
////			break;
////
////		default:
////			if (i == 0)
////			{
////				d = 0;
////				while (ch >= '0' && ch <= '9')
////				{
////					d = d * 10 + (ch - '0');
////					i++;
////					ch = postexp[i];
////				}
////				opand.push(d);
////				break;
////			}
////
////			else
////			{
////				if (postexp[i - 1] == '#')
////				{
////					d = 0;
////					while (ch >= '0' && ch <= '9')
////					{
////						d = d * 10 + (ch - '0');
////						i++;
////						ch = postexp[i];
////					}
////					opand.push(d);
////					break;
////				}
////
////				else if (postexp[i - 1] == '-')
////				{
////					d = 0;
////					while (ch >= '0' && ch <= '9')
////					{
////						d = d * 10 + (ch - '0');
////						i++;
////						ch = postexp[i];
////					}
////					d = -d;
////					opand.push(d);
////					break;
////				}
////
////			}
////
////		}
////
////		i++;
////	}
////
////	return  opand.top();
////}
////
////void pre_display(Node *root)
////{
////	if(root)
////	{
////		cout<<root->data;
////		if(isdigit(root->data[0]))
////		cout<<"#";
////		
////		pre_display(root->Ltree);
////		
////		pre_display(root->Rtree);
////	}
////}
////
////void in_display(Node *root)
////{
////	if(root)
////	{
////		in_display(root->Ltree);
////		
////		cout<<root->data;
////		if(isdigit(root->data[0]))
////		cout<<"#";
////	
////		in_display(root->Rtree);
////	}
////}
////void post_display(Node *root)
////{
////	if(root)
////	{
////		post_display(root->Ltree);
////	
////		post_display(root->Rtree);
////		
////		cout<<root->data;
////		if(isdigit(root->data[0]))
////		cout<<"#";
////	}	
////}
////
////void lo_display(Node *root)
////{
////	if(!root) return;
////	queue<Node*> q;
////	q.push(root);
////	
////	while(!q.empty())
////	{
////		Node *cur = q.front();
////		q.pop();
////		cout<<cur->data;
////		if(isdigit(cur->data[0]))
////		cout<<"#";
////		
////		if(cur->Ltree) q.push(cur->Ltree);
////		if(cur->Rtree) q.push(cur->Rtree);
////	}
////}
////
////int main()
////{
////	
//////	freopen("in.txt","r",stdin);
////	string s0;
////	getline(cin,s0,'=');
////	
////	Node* root;
////	string postexp = creat_postexp(s0);
////	s = postexp;
////	int result = calculate(s);
////	
//////	cout<<s<<endl; 
////	
//////	reverse(s.begin(),s.end());
//////	s = s.substr(1,s.length());
////	
////	root = creat_tree(s);
////	
////	pre_display(root);
////	cout<<endl;
////	
////	in_display(root);
////	cout<<endl;
////	
////	post_display(root);
////	cout<<endl;
////	
////	lo_display(root);
////	cout<<endl;
////	
////	cout<<result<<endl;
////	
////	
//// } 
//// //version1.0
//////#include<iostream>
//////#include<vector>
//////#include<stack>
//////#include<algorithm>
//////#include<queue>
//////using namespace std;
//////string s;
//////
//////struct Node
//////{
//////	string data;
//////	Node *Ltree;
//////	Node *Rtree;
//////	Node(string c):data(c)
//////	{
//////		Ltree = Rtree = nullptr;
//////	};
//////	
//////	Node():data("#")
//////	{
//////		Ltree = Rtree = nullptr;
//////	}
//////};
//////
//////string creat_postexp(const string &s)
//////{
//////	stack<char>st;
//////	string postexp = "";
//////	char e;
//////	for(int i = 0;i<s.length();i++)
//////	{
//////		char c = s[i]; 
//////		
//////		if(c == '(')
//////		{
//////			st.push(c);
//////		}
//////		
//////		else if(c == ')')
//////		{
//////			while(!st.empty()&& st.top()!='(')
//////			{
//////				e = st.top();
//////				st.pop();
//////				postexp += e;
//////				postexp += '#';
//////			} 
//////			st.pop();
//////		} 
//////		else if(c =='+'||c =='-')
//////		{
//////			while(!st.empty() && st.top() != '(')
//////			{
//////				e = st.top();
//////				st.pop();
//////				postexp += e;
//////				postexp += '#';
//////			}
//////			st.push(c);
//////		}
//////		else if(c =='*'||c =='/')
//////		{
//////			while(!st.empty() && st.top() != '('&&(st.top() == '*'||st.top() == '/'))
//////			{
//////				e = st.top();
//////				st.pop();
//////				postexp += e;
//////				postexp += '#';
//////			}
//////			st.push(c);
//////		}
//////		else if(c == ' ')
//////		{
//////			
//////		}
//////		else
//////		{
//////			string d = "";
//////			while(c>='0'&&c<='9')
//////			{
//////				d += c;
//////				i++;
//////				c = s[i];
//////			}
//////			i--;
//////			postexp += d;
//////			postexp += "#";
//////		}
//////	}
//////	while(!st.empty() && st.top() != '(')
//////	{
//////		e = st.top();
//////		st.pop();
//////		postexp += e;
//////		postexp += '#';
//////	}
//////	return postexp;
//////}
//////
//////Node* creat_tree(string &s)
//////{
//////	
//////	int i = 0;
//////	//v只存储数字 
//////	vector<Node*>v;
//////	//st里面存储节点 
//////	stack<Node*>st;
//////	
//////	Node *temp;
//////	bool falg = false;
//////	
//////	while(i<s.length())
//////	{
//////		while(s[i]=='#')
//////		{
//////			i++;
//////		}
//////		
//////		char c = s[i];
//////		string s0 ="";
//////	    while(c!='#')
//////	    {
//////	    	s0+=c;
//////	    	i++;
//////	    	c = s[i];
//////		}
//////		
//////		temp = new Node(s0);
//////		
//////		if(v.size()==2)
//////		{
//////			Node *n1 = v.back();
//////			v.pop_back();
//////			Node *n2 = v.back();
//////			v.pop_back();
//////			temp->Rtree = n1;
//////			temp->Ltree = n2;
//////			st.push(temp);
//////		}
//////		else if(v.size()==1)
//////		{
//////			//因为只有接下来是两个数字我才会放入一个数字节点 
//////			v.push_back(temp);
//////		}
//////		
//////		else
//////		{
//////			if(isdigit(s0[0]))
//////			{
//////				if(isdigit(s[i+1]))
//////				{
//////					v.push_back(temp);
//////				}
//////				else
//////				{
//////					st.push(temp);
//////					
//////				} 
//////			}
//////			else
//////			{
//////				temp->Ltree = st.top();
//////				st.pop();
//////				temp->Rtree = st.top();
//////				st.pop();
//////				st.push(temp);
//////				
//////			}
//////			
//////		}
//////		
//////		continue;
//////	}
//////	return st.top();
//////}
//////
//////int calculate(const string &postexp)
//////{
//////	stack<int> opand;
//////	int a, b, c, d;
//////	char ch;
//////	int i = 0;
//////
//////	while (i < (int)postexp.length())
//////	{
//////		ch = postexp[i];
//////		switch (ch)
//////		{
//////		case '+':
//////			a = opand.top(); opand.pop();
//////			b = opand.top(); opand.pop();
//////			c = b + a;
//////			opand.push(c);
//////			break;
//////		case '-':
//////			if (postexp[i + 1] == '#' || postexp[i + 1] == '\0')
//////			{
//////				a = opand.top(); opand.pop();
//////				b = opand.top(); opand.pop();
//////				c = b - a;
//////				opand.push(c);
//////				break;
//////			}
//////			else break;
//////
//////		case '*':
//////			a = opand.top(); opand.pop();
//////			b = opand.top(); opand.pop();
//////			c = b * a;
//////			opand.push(c);
//////			break;
//////		case '/':
//////			a = opand.top(); opand.pop();
//////			b = opand.top(); opand.pop();
//////			c = b / a;
//////			opand.push(c);
//////			break;
//////		case'#':
//////			break;
//////
//////		default:
//////			if (i == 0)
//////			{
//////				d = 0;
//////				while (ch >= '0' && ch <= '9')
//////				{
//////					d = d * 10 + (ch - '0');
//////					i++;
//////					ch = postexp[i];
//////				}
//////				opand.push(d);
//////				break;
//////			}
//////
//////			else
//////			{
//////				if (postexp[i - 1] == '#')
//////				{
//////					d = 0;
//////					while (ch >= '0' && ch <= '9')
//////					{
//////						d = d * 10 + (ch - '0');
//////						i++;
//////						ch = postexp[i];
//////					}
//////					opand.push(d);
//////					break;
//////				}
//////
//////				else if (postexp[i - 1] == '-')
//////				{
//////					d = 0;
//////					while (ch >= '0' && ch <= '9')
//////					{
//////						d = d * 10 + (ch - '0');
//////						i++;
//////						ch = postexp[i];
//////					}
//////					d = -d;
//////					opand.push(d);
//////					break;
//////				}
//////
//////			}
//////
//////		}
//////
//////		i++;
//////	}
//////
//////	return  opand.top();
//////}
//////
//////void pre_display(Node *root)
//////{
//////	if(root)
//////	{
//////		cout<<root->data;
//////		if(isdigit(root->data[0]))
//////		cout<<"#";
//////		
//////		pre_display(root->Ltree);
//////		
//////		pre_display(root->Rtree);
//////	}
//////}
//////
//////void in_display(Node *root)
//////{
//////	if(root)
//////	{
//////		pre_display(root->Ltree);
//////		
//////		cout<<root->data;
//////		if(isdigit(root->data[0]))
//////		cout<<"#";
//////	
//////		pre_display(root->Rtree);
//////	}
//////}
//////void post_display(Node *root)
//////{
//////	if(root)
//////	{
//////		pre_display(root->Ltree);
//////	
//////		pre_display(root->Rtree);
//////		
//////		cout<<root->data;
//////		if(isdigit(root->data[0]))
//////		cout<<"#";
//////	}	
//////}
//////
//////void lo_display(Node *root)
//////{
//////	if(!root) return;
//////	queue<Node*> q;
//////	q.push(root);
//////	
//////	while(!q.empty())
//////	{
//////		Node *cur = q.front();
//////		q.pop();
//////		cout<<root->data;
//////		if(isdigit(root->data[0]))
//////		cout<<"#";
//////		
//////		if(cur->Ltree) q.push(cur->Ltree);
//////		if(cur->Rtree) q.push(cur->Rtree);
//////	}
//////}
//////
//////int main()
//////{
//////	
//////	freopen("in.txt","r",stdin);
//////	string s0;
//////	getline(cin,s0,'=');
//////	
//////	Node* root;
//////	string postexp = creat_postexp(s0);
//////	s = postexp;
//////	int result = calculate(s);
//////	
//////	cout<<s<<endl; 
//////	
////////	reverse(s.begin(),s.end());
////////	s = s.substr(1,s.length());
//////	
//////	root = creat_tree(s);
//////	
//////	pre_display(root);
//////	cout<<endl;
//////	
//////	in_display(root);
//////	cout<<endl;
//////	
//////	post_display(root);
//////	cout<<endl;
//////	
//////	lo_display(root);
//////	cout<<endl;
//////	
//////	cout<<result<<endl;
////// } 
