#include<iostream>
#include<vector>
#include <algorithm>
#include<fstream>
#include<sstream>
using namespace std;

class STACK
{
public:
	vector<int>Stack;

	void push(int x)
	{
		Stack.push_back(x);

	}

	int pop()
	{
		int top = Stack.back();
		Stack.pop_back();
		return top;
	}

	void merge(STACK& other)
	{
		while (!other.is_empty())
		{
			this->push(other.pop());

		}

	}
	
	int top()
	{
		return Stack.back();;
	}

	bool is_empty() {
		return Stack.empty();
	}

};


int main()
{
	ifstream in_data("in.txt");
	int n;
	STACK A, B, C;
	string operation;
	string stackName;

	in_data >> n;
	for (int i = 0; i < n; i++)
	{
		in_data >> operation;
		if (operation == "push")
		{
			int x;
			in_data >> stackName >> x;
			if (stackName == "A")
			{
				A.push(x);
				C.push(x);
			}
			else
			{
				B.push(x);
				C.push(x);
			}

		}
		else if (operation == "pop")
		{
			in_data >> stackName;
			int delete_num = 0;
			if (stackName == "A")
			{
				delete_num = A.pop();
				while (delete_num == -1)
				{
					delete_num = A.pop();
				}

				cout << delete_num << endl;

				if (!C.is_empty())
				{
					vector<int>::iterator it = find(C.Stack.begin(), C.Stack.end(), delete_num);
					*it = -1;
				}


			}

			else
			{
				delete_num = B.pop();
				while (delete_num == -1)
				{
					delete_num = B.pop();
				}
				cout << delete_num << endl;
				if (!C.is_empty())
				{
					vector<int>::iterator it = find(C.Stack.begin(), C.Stack.end(), delete_num);
					*it = -1;
				}


				//	            delete_num = B.pop();
				//	            cout << delete_num << endl;
				//	            vector<int>::iterator it = find(C.Stack.begin(), C.Stack.end(), delete_num);
				//	            *it = -1;

			}

		}
		else
		{

			string stackName1, stackName2;
			in_data >> stackName1 >> stackName2;
			STACK* stack1 = (stackName1 == "A" ? &A : &B);
			STACK* stack2 = (stackName2 == "A" ? &A : &B);

			while (!stack1->is_empty())
			{
				stack1->pop();
			}

			while (!stack2->is_empty())
			{
				stack2->pop();
			}
			
			if(!C.is_empty())
			{
				for(vector<int>::iterator it = C.Stack.begin();it <C.Stack.end();it++)
				{
					stack1->push(*it);
				} 
			}

		}

	}

	return 0;
}
