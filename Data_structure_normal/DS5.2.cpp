//version 1.0

//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<string>
//#include<vector>
//using namespace std;
//const int MaxSize = 50000;
//
//class Stu
//{
//public:
//	int F;
//	int S; 
//	int ID;
//	int pos = 0;
//	Stu(){};
//	Stu(int f,int s,int i):F(f),S(s),ID(i){};
//	void calculate(int time)
//	{
//		pos = F + S*(time-1);
//	}
//};
//
//class CSqQueue
//{
//public:
//	Stu* data;  
//    int front, rear;
//	CSqQueue()
//	{
//		data = new Stu[MaxSize];
//		front = rear = 0;
//	}
//	
//	~CSqQueue()
//	{
//		delete [] data;
//	}
//	
//	bool is_empty()
//	{
//		return (front == rear);
//		
//	}
//	
//	bool is_over()
//	{
//		return ((rear+1)%MaxSize == front);
//	}
//	
//	bool push(Stu st)
//	{
//		if(this->is_over()) return false;
//		
//		rear = (rear+1)%MaxSize;
//		data[rear] = st;
//		return true;
//	}
//	
//	bool pop(Stu &st)
//	{
//		if (this->is_empty()) return false;
//		
//		front=(front+1)%MaxSize;
//		st=data[front];
//		return true;
//	}
//	
//	int getlength()
//	{
//		return (rear-front+MaxSize)%MaxSize;
//	}
//	
//	bool popId(int id,Stu& st)
//	{
//	    Stu x;
//	    int n= this->getlength();
//		if (id<1 || id>n) return false;
//		for (int i=1;i<=n;i++)
//		{
//			this->pop(x);
//			if (data[i].ID!=id)
//			this->push(x);
//			else
//			{
//				st = data[i]; 
////				st.F=x.F;
////				st.S = x.S;
////				st.ID = x.ID;
////				st.pos = x.pos;
//
//			}
//		}
//		return true;
//	}
//
//};
//
//
//
//int main()
//{
//	int time = 1;
//	int n ;
//	int F, S;
//	Stu temp_st;
//	CSqQueue solution;
//	
//	ifstream in_data("in.txt");
//	if (!in_data.is_open()) {
//        cerr << "Unable to open input file." << endl;
//        return 1;
//    }
//    
//	in_data>>n;
//
//	for(int i = 0;i<n;i++)
//	{
//		in_data>>F>>S;
//		solution.push(Stu(F,S,i+1));
//	}
//	
//	int position_max = 0;
//	int ans_ID = 1;
//	for(int i = 0;i<n;i++)
//	{
//		int count = solution.front;
//		while((count+1)!=n)
//		{
//			solution.data[count].calculate(time);
//			if(solution.data[count].pos > position_max)
//			{
//				position_max = solution.data[count].pos;
//				ans_ID = count+1;
//			}
//		}
//		cout<<ans_ID<<" ";
//		solution.popId(ans_ID,temp_st);
//		time++;
//	}
//	
//	return 0;
//}

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
const int MaxSize = 50000;

class Stu
{
public:
	int F = 0;
	int S = 0;
	int ID = 0;
	int pos = 0;
	Stu() {};
	Stu(int f, int s, int i) :F(f), S(s), ID(i),pos(0){};
	void calculate(int time)
	{
		pos = F + S * (time - 1);
	}
	Stu& operator=(Stu& other)
	{
		if (this != &other)
		{
			F = other.F;
			S = other.S;
			ID = other.ID;
			pos = other.pos;
		}
		return *this;
	}
};

class CSqQueue
{
public:
	Stu *data;
	/*Stu *data = new Stu[MaxSize];*/
	int front, rear;
	CSqQueue()
	{
		data = new Stu[MaxSize];
		front = rear = 0;
	}

	~CSqQueue()
	{
		delete[] data;
	}

	bool is_empty()
	{
		return (front == rear);

	}

	bool is_over()
	{
		return ((rear + 1) % MaxSize == front);
	}

	bool push(Stu st)
	{
		if (this->is_over()) return false;

		rear = (rear + 1) % MaxSize;
		data[rear] = st;
		return true;
	}

	bool pop(Stu& st)
	{
		if (this->is_empty()) return false;

		front = (front + 1) % MaxSize;
		st = data[front];
		return true;
	}

	int getlength()
	{
		return (rear - front + MaxSize) % MaxSize;
	}

	bool popId(int id)//, Stu& st
	{
		if (this->is_empty()) return false;
		Stu x;
		int n = this->getlength();
		int cur_index = this->front+1;
		for (int i = 1; i <= n; i++)
		{
			this->pop(x);
			if (data[cur_index].ID != id)
				this->push(x);
			cur_index++;
			//else
			//{
			//	st = data[i];
			//	//				st.F=x.F;
			//	//				st.S = x.S;
			//	//				st.ID = x.ID;
			//	//				st.pos = x.pos;

			//}
		}
		return true;
	}

};



int main()
{
	int time = 1;
	int n, n2 = 0;
	int F, S;
	Stu temp_st;
	CSqQueue solution;

	ifstream in_data("in.txt");
	if (!in_data.is_open()) {
		cerr << "Unable to open input file." << endl;
		return 1;
	}

	in_data >> n;


	for (int i = 0; i < n; i++)
	{
		in_data >> F >> S;
		solution.push(Stu(F, S, i + 1));
	}

	//cout<<solution.data[3].F;



	//时刻循环
	for (int i = 0; i < n; i++)
	{
		int position_max = -1;
		int ans_ID = 0;


		//便利循环查找
		int count = solution.front+1;
		int j = 0;
		n2 = solution.getlength();
		while (j != n2)
		{

			solution.data[count].calculate(time);

			if (solution.data[count].pos > position_max)
			{

				position_max = solution.data[count].pos;
				ans_ID = solution.data[count].ID;
			}
			count++;
			j++;
		}

		cout << ans_ID << " ";
		solution.popId(ans_ID);
		time++;
	}

	return 0;
}
