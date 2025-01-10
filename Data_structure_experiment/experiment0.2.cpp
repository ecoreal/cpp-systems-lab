//version 1.0
//#include<iostream>
//#include<vector>
//using namespace std;
//const int MaxSize = 14;
//struct Queue
//{
////	int *data = new int [MaxSize];
////	int data[MaxSize];
//    int *data;
//	int front, rear;
//
//	Queue()
//	{
//		data = new int[MaxSize];
//		front = rear = 0;
//	}
//	~Queue()
//	{
//		delete[]data;
//
//	}
//
//	bool is_empty()
//	{
//		return (front == rear);
//	}
//
//	bool is_over()
//	{
//		return ((rear + 1) % MaxSize == front);
//	}
//
//	bool push(int num)
//	{
//		if (this->is_over()) return false;
//		rear = (rear + 1) % MaxSize;
//		data[rear] = num;
//		return true;
//	}
//
//	bool pop(int& num)
//	{
//		if (this->is_empty()) return false;
//		front = (front + 1) % MaxSize;
//		num = data[front];
//		return true;
//	}
//	int GetLength()
//	{
//		return ((rear - front + MaxSize) % MaxSize);
//	}
//
//	void displayL()
//	{
//		for (int i = front + 1; i <= rear; i++)
//		{
//			cout << data[i] << " ";
//		} 
//		cout << endl;
//	}
//	void displayR()
//	{
//		for (int i = rear; i > front; i--)
//		{
//			cout << data[i] << " ";
//		}
//		cout << endl;
//	}
//
//};
//
//int main()
//{
//	int n, num;
//	vector<int>v;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		v.push_back(num);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		Queue solution;
//		Queue ans;
//		for (int j = 0; j < v[i]; j++)
//		{
//			solution.push(j + 1);
//		}
//
//		int count = 1;
//		int temp = 0;
//		while (!solution.is_empty())
//		{
//			for (int k = 1; k <= count; k++)
//			{
//				solution.pop(temp);
//				solution.push(temp);
//			}
//			
//			solution.pop(temp);
//			ans.push(temp);
//			count++;
//			
//		}
//
//		if (ans.GetLength() % 2 == 0)
//		{
//			ans.displayL();
//		}
//		else
//		{
//			ans.displayR();
//		}
//
//
//	}
//
//}

//version 2.0 
//#include<iostream>
//#include<vector>
//using namespace std;
//const int MaxSize = 14;
//struct Queue
//{
////	int *data = new int [MaxSize];
////	int data[MaxSize];
//    int *data;
//	int front, rear;
//
//	Queue()
//	{
//		data = new int[MaxSize];
//		front = rear = 0;
//	}
//	~Queue()
//	{
//		delete[]data;
//
//	}
//
//	bool is_empty()
//	{
//		return (front == rear);
//	}
//
//	bool is_over()
//	{
//		return ((rear + 1) % MaxSize == front);
//	}
//
//	bool push(int num)
//	{
//		if (this->is_over()) return false;
//		rear = (rear + 1) % MaxSize;
//		data[rear] = num;
//		return true;
//	}
//
//	bool pop(int& num)
//	{
//		if (this->is_empty()) return false;
//		front = (front + 1) % MaxSize;
//		num = data[front];
//		return true;
//	}
//	int GetLength()
//	{
//		return ((rear - front + MaxSize) % MaxSize);
//	}
//
//	void displayL()
//	{
//		for (int i = front + 1; i <= rear; i++)
//		{
//			cout << data[i];
//			if(i!=rear) cout<<" "; 
//			
//		} 
//	}
//	void displayR()
//	{
//		for (int i = rear; i > front; i--)
//		{
//			cout << data[i] ;
//			if(i!=front+1) cout<<" ";
//		}
//	}
//
//};
//
//int main()
//{
//	int n, num;
//	vector<int>v;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		v.push_back(num);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		Queue solution;
//		Queue ans;
//		for (int j = 0; j < v[i]; j++)
//		{
//			solution.push(j + 1);
//		}
//
//		int count = 1;
//		int temp = 0;
//		if (solution.GetLength() == 2||solution.GetLength() == 3)
//		{
//			while (!solution.is_empty())
//			{
//				for (int k = 1; k <= count; k++)
//				{
//					solution.pop(temp);
//					solution.push(temp);
//				}
//
//				solution.pop(temp);
//				ans.push(temp);
//			}
//		}
//		if (solution.GetLength() == 4)
//		{
//			while (!solution.is_empty())
//			{
//				for (int k = 1; k <= count; k++)
//				{
//					solution.pop(temp);
//					solution.push(temp);
//				}
//
//				solution.pop(temp);
//				ans.push(temp);
//				count++;
//
//			}
//		}
//		if (solution.GetLength() == 5)
//		{
//			while (!solution.is_empty())
//			{
//				for (int k = 1; k <= count; k++)
//				{
//					solution.pop(temp);
//					solution.push(temp);
//				}
//
//				solution.pop(temp);
//				ans.push(temp);
//				if (count == 1) count++;
//
//				
//
//			}
//		}
//
//		
//
//		if (ans.GetLength() % 2 == 0)
//		{
//			ans.displayL();
//		}
//		else
//		{
//			ans.displayR();
//		}
//		if(i!=n-1) cout<<endl;
//	}
//
//}


//version3.0
#include<iostream>
#include<vector>
using namespace std;
const int MaxSize = 15;
struct Queue
{
//	int data[MaxSize];
  int *data;
	int front, rear;

	Queue()
	{
		data = new int[MaxSize];
		front = rear = 0;
	}
	~Queue()
	{
		delete[]data;
	}

	bool is_empty()
	{
		return (front == rear);
	}

	bool is_over()
	{
		return ((rear + 1) % MaxSize == front);
	}

	bool push(int num)
	{
		if (this->is_over()) return false;
		rear = (rear + 1) % MaxSize;
		data[rear] = num;
		return true;
	}

	bool pop(int& num)
	{
		if (this->is_empty()) return false;
		front = (front + 1) % MaxSize;
		num = data[front];
		return true;
	}
	int GetLength()
	{
		return ((rear - front + MaxSize) % MaxSize);
	}

	void display()
	{
		for (int i = rear; i >front; i--)
		{
			cout << data[i];
			if(i!=front+1) cout<<" "; 
			
		} 
	}

};

void solution(int n)
{
	Queue q;
	int temp = 0;
	for(int i = n;i>=1;i--)
	{
		q.push(i);
		for(int j = 0;j<i;j++)
		{
			q.pop(temp);
			q.push(temp);
		}
	}
	q.display();
	cout<<endl;
	
}

int main()
{
	int n, num;
	vector<int>v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		
		cin >> num;
		v.push_back(num);
	}
	
	for(int i = 0;i<n;i++)
	{
		solution(v[i]);
	}
	
}
