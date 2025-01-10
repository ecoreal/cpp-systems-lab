//version 1.0
////#include <iostream>
////#include <stack>
////#include <string>
////#include <sstream>
////
////// 判断是否为运算符
////bool isOperator(const std::string& token) {
////    return token == "+" || token == "-" || token == "*" || token == "/";
////}
////
////// 计算逆波兰表达式
////int evalRPN(const std::vector<std::string>& tokens) {
////    std::stack<int> numStack;
////    for (const std::string& token : tokens) {
////        if (isOperator(token)) {
////            int num2 = numStack.top();
////            numStack.pop();
////            int num1 = numStack.top();
////            numStack.pop();
////            if (token == "+") numStack.push(num1 + num2);
////            else if (token == "-") numStack.push(num1 - num2);
////            else if (token == "*") numStack.push(num1 * num2);
////            else if (token == "/") numStack.push(num1 / num2);
////        } else {
////            std::istringstream iss(token);
////            int num;
////            iss >> num;
////            numStack.push(num);
////        }
////    }
////    return numStack.top();
////}
////
////int main() {
////    std::string expression;
////    std::getline(std::cin, expression, '=');
////
////    std::vector<std::string> tokens;
////    std::istringstream iss(expression);
////    std::string token;
////    while (iss >> token) {
////        tokens.push_back(token);
////    }
////
////    int result = evalRPN(tokens);
////    std::cout << result << std::endl;
////
////    return 0;
////}
//
//
//#include<iostream>
//#include<string>
//#include<sstream>
//#include<stack>
//using namespace std;
//
//struct Solution
//{
//	string exp;
//	string postexp;
//	stack<char>opor;
//	Solution(string s) :exp(s)
//	{
//		//转换 
//		int i = 0;
//		char ch ,e;
//		while(i<(int)exp.length())
//		{
//			
//			ch = exp[i];
//			if(ch =='(')
//			{
//				opor.push(ch);
//			}
//			else if(ch == ')')
//			{
//				while(!opor.empty()&&opor.top()!='(')
//				{
//					e = opor.top();
//					opor.pop();
//					postexp += e;
//				}
//				opor.pop();
//			}
//			else if(ch == '+'||ch == '-')
//			{
//				while(!opor.empty()&&opor.top()!='(')
//				{
//					e = opor.top();
//					opor.pop();
//					postexp +=e;
//				}
//				opor.push(ch);
//			}
//			else if(ch =='*'||ch=='/')
//			{
//				while((!opor.empty()&&opor.top()!='(')&& (opor.top()=='*'||opor.top()=='/'))
//				{
//					e = opor.top();
//					opor.pop();
//					postexp +=e;
//				}
//				opor.push(ch);
//			}
//			else if(ch ==' ')
//			{
//				
//			}
//			else
//			{
//				string d = "";
//				while(ch>='0'&&ch<='9')
//				{
//					d+=ch;
//					i++;
//					if(i<(int)exp.length())
//					{
//						ch = exp[i];
//					}
//					else break;
//				}
//				i--;
//				postexp +=d;
//				postexp +="#";
//				
//			}
//			i++;
//		}
//		
//		while(!opor.empty())
//		{
//			e = opor.top();
//			opor.pop();
//			postexp += e;
//		}
//	};
//	void calculate()
//	{
//		stack<int> opand;
//		int a,b,c,d;
//		char ch;
//		int i = 0;
//		
//		while(i<(int)postexp.length())
//		{
//			ch = postexp[i];
//			switch(ch)
//			{
//				case '+':
//					a = opand.top();opand.pop();
//					b = opand.top();opand.pop();
//					c = b+a;
//					opand.push(c);
//					break;
//				case '-':
//					if(postexp[i+1]=='#'||postexp[i+1]=='\0')
//					{
//						a = opand.top();opand.pop();
//						b = opand.top();opand.pop();
//						c = b-a;
//						opand.push(c);
//						break;
//					}
//					else break;
//					
//				case '*':
//					a = opand.top();opand.pop();
//					b = opand.top();opand.pop();
//					c = b*a;
//					opand.push(c);
//					break;
//				case '/':
//					a = opand.top();opand.pop();
//					b = opand.top();opand.pop();
//					c = b/a;
//					opand.push(c);
//					break;
//				default:
//					d = 0;
//					if(postexp[i-1]=='#')
//					{
//						while(ch>='0'&&ch<='9')
//						{
//							d = 10*d+(ch-'0');
//							i++;
//							ch = postexp[i];
//						}
//						opand.push(d);
//						break;
//					}
//					else if(postexp[i-1]=='-')
//					{
//						d = 0;
//				    	while (ch >= '0' && ch <= '9')
//				    	{
//							d = d * 10 + (ch - '0');
//							i++;
//							ch = postexp[i];
//						}
//						d = -d; 
//						opand.push(d);
//						break;
//					}	
//			}
//			i++;
//		}
//		
//		cout<<opand.top();
//	} 
//	
//	
//};
//
//int main()
//{
//	
//	string expression;
//    getline(cin, expression, '=');
//    
//	Solution ans(expression);
//	ans.calculate();
//	
//
//	
//}
//


#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;

struct Solution
{
	string exp;
	string postexp;
	stack<char>opor;
	Solution(string s) :exp(s)
	{
		//转换 
		int i = 0;
		char ch, e;
		while (i < (int)exp.length())
		{

			ch = exp[i];
			if (ch == '(')
			{
				opor.push(ch);
			}
			else if (ch == ')')
			{
				while (!opor.empty() && opor.top() != '(')
				{
					e = opor.top();
					opor.pop();
					postexp += e;
					//
					postexp += '#';
				}
				opor.pop();
			}
			else if (ch == '+' || ch == '-')
			{
				while (!opor.empty() && opor.top() != '(')
				{
					e = opor.top();
					opor.pop();
					postexp += e;
					//
					postexp += '#';
				}
				opor.push(ch);
			}
			else if (ch == '*' || ch == '/')
			{
				while ((!opor.empty() && opor.top() != '(') && (opor.top() == '*' || opor.top() == '/'))
				{
					e = opor.top();
					opor.pop();
					postexp += e;
					//
					postexp += '#';
				}
				opor.push(ch);
			}
			else if (ch == ' ')
			{

			}
			else
			{
				string d = "";
				while (ch >= '0' && ch <= '9')
				{
					d += ch;
					i++;
					if (i < (int)exp.length())
					{
						ch = exp[i];
					}
					else break;
				}
				i--;
				postexp += d;
				postexp += "#";

			}
			i++;
		}

		while (!opor.empty())
		{
			e = opor.top();
			opor.pop();
			postexp += e;
			//
			postexp += '#';
		}
		cout<<postexp<<endl;
	};
	void calculate()
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

		cout << opand.top();
	}


};

int main()
{
	freopen("in.txt","r",stdin);

	string expression;
	getline(cin, expression, '=');

	Solution ans(expression);

	ans.calculate();
}
