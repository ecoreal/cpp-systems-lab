// version 1.0
////#include <iostream>
////#include <fstream>
////#include <vector>
////
////using namespace std;
////
////class Matrix 
////{
////public:
////    vector<vector<int>> data;
////    Matrix(int rows, int cols) {
////        data.resize(rows, vector<int>(cols));
////    }
////
////    // 读取矩阵数据
////    void readMatrix(istream& in) {
////        for (int i = 0; i < data.size(); ++i) {
////            for (int j = 0; j < data[0].size(); ++j) {
////                in >> data[i][j];
////            }
////        }
////    }
////     Matrix equalityJoin(const Matrix& other, int col1, int col2) {
////        Matrix result(data.size(), data[0].size() + other.data[0].size());
////        for (int i = 0; i < data.size(); ++i) {
////            for (int j = 0; j < data[0].size(); ++j) {
////                result.data[i][j] = data[i][col1 - 1]; // 减1是因为序号从1开始
////            }
////            for (int j = 0; j < other.data[0].size(); ++j) {
////                result.data[i][data[0].size() + j] = other.data[i][col2 - 1];
////            }
////        }
////        return result;
////    }
////
////    // 输出矩阵数据
////    void printMatrix(ostream& out) const {
////        for (const auto& row : data) {
////            for (int val : row) {
////                out << val << " ";
////            }
////            out << endl;
////        }
////    }
////    
////};
////
////
////int main() {
////    ifstream inFile("in.txt");
////    ofstream outFile("abc.out");
////
////    // 读取第一个矩阵的大小和数据
////    int m1, n1;
////    inFile >> m1 >> n1;
////    Matrix R(m1, n1);
////    R.readMatrix(inFile);
////
////    // 读取第二个矩阵的大小和数据
////    int m2, n2;
////    inFile >> m2 >> n2;
////    Matrix S(m2, n2);
////    S.readMatrix(inFile);
////
////    // 读取列序号
////    int a1, a2;
////    inFile >> a1 >> a2;
////
////    // 进行等值联接运算
////    Matrix C = R.equalityJoin(S, a1, a2);
////
////    // 将结果写入文件
////    C.printMatrix(outFile);
////
////    inFile.close();
////    outFile.close();
////
////    return 0;
////}
////    
//
//
//#include<iostream>
//#include<fstream>
//using namespace std;
//
//struct LinkNode
//{
//	int value;
//	LinkNode *next;
//	
//	LinkNode(int v):value(v),next(nullptr){};
////	LinkNode():next(nullptr){};
//	
//};
//
//class LinkList
//{
//public:
//	LinkNode *head;
//	LinkNode *tail;
//	
//	LinkList():head(nullptr),tail(nullptr){};
//	
//	void append(int val)
//	{
//		LinkNode *NewNode = new LinkNode(val);
//		if(!head)
//		{
//			head = NewNode;
//			tail = NewNode;
//		}
//		else
//		{
//			tail->next = NewNode;
//			tail = NewNode;
//		}
//		
//	}
//	
//	~LinkList()
//	{
//        LinkNode* current = head;
//        while (current) {
//            LinkNode* temp = current;
//            current = current->next;
//            delete temp;
//        }
//        head = nullptr;
//        tail = nullptr;
//        
//    }
//    
//};
//
//class Matrix 
//{
//public:
//	LinkList *rows;
//	int num_row;
//	int num_column;
//	
//	Matrix(int m,int n):num_row(m),num_column(n)
//	{
//		rows = new LinkList[m];
//	}
//	
//	void initialize(istream& in_data)
//	{
//		int val;
//		for(int i = 0;i<num_row;i++)
//		{
//			for(int j = 0;j<num_column;j++)
//			{
//				in_data>>val;
//				rows[i].append(val);
//			}
//		} 
//	}
//	
////	void out(ostream& out)
////	{
////		for(int i = 0;i<num_row;i++)
////		{
////			LinkNode *p = rows[i].head;
////			while(p)
////			{
////				out<<p->value<<" ";
////				p = p->next;
////			}
////		}
////	}
//    void out()
//    {
//    	for(int i = 0;i<num_row;i++)
//		{
//			LinkNode *p = rows[i].head;
//			while(p)
//			{
//				cout<<p->value<<" ";
//				p = p->next;
//			}
//		}
//	}
//
//	
//	Matrix equivalent_joins(Matrix &other,int column1,int column2)
//	{
//		Matrix ans(this->num_row*other.num_row,this->num_column*other.num_column);
//		int ans_row = 0;
//		
//		//第一个矩阵 
//		for(int i = 0;i<this->num_row;i++)
//		{
//			int count1 = 1;
//			bool is_euqal = false;
//			LinkNode *current1 = rows[i].head;
//			while(count1<column1)
//			{
//				current1 = current1->next;
//				count1++;
//			}
//			int val1 = current1->value;
//			
//			//第二个矩阵 
//			for(int j = 0;j<other.num_row;j++)
//			{
//				int count2 = 1;
//				LinkNode *current2 = rows[j].head;
//				while(count2<column2)
//				{
//					current2 = current2->next;
//					count2++;
//				}
//				int val2 = current1->value; 
//				if(val1==val2)
//				{
//					//?
//					ans.rows[ans_row].head = current1;
//					current1->next = current2;
//					ans_row++;
//				}
//			} 
//		
//		}
//		return ans;
//		
//	}
//	
//};
//int main()
//{
//	ifstream in_data("in.txt");
////	ofstream out_data("abc.out");
//	
//	if(!in_data.is_open())
//	{
//		cerr<<"Unable to open the file"<<endl;
//	}
//	int r1,c1;
//	in_data>>r1>>c1;
//	Matrix R(r1,c1);
//	R.initialize(in_data);
//	
//	int r2,c2;
//	in_data>>r2>>c2;
//	Matrix S(r2,c2);
//	S.initialize(in_data);
//	
//	int column1,column2;
//	in_data>>column1>>column2;
//	
//	Matrix C = R.equivalent_joins(S,column1,column2);
////	C.out(out_data);
//    C.out();
//	return 0;
//	
//}


#include<iostream>
#include<fstream>
using namespace std;
int ans_row = 0;

struct LinkNode
{
	int value;
	LinkNode* next;

	LinkNode(int v) :value(v), next(nullptr) {};
	//	LinkNode():next(nullptr){};

};

class LinkList
{
public:
	LinkNode* head;
	LinkNode* tail;

	LinkList() :head(nullptr), tail(nullptr) {};

	void append(int val)
	{
		LinkNode* NewNode = new LinkNode(val);
		if (!head)
		{
			head = NewNode;
			tail = NewNode;
		}
		else
		{
			tail->next = NewNode;
			tail = NewNode;
		}

	}

	~LinkList()
	{
		LinkNode* current = head;
		while (current) {
			LinkNode* temp = current;
			current = current->next;
			delete temp;
		}
		head = nullptr;
		tail = nullptr;

	}

};

class Matrix
{
public:
	LinkList* rows;
	int num_row;
	int num_column;

	Matrix(int m, int n) :num_row(m), num_column(n)
	{
		rows = new LinkList[m];
	}

	void initialize(istream& in_data)
	{
		int val;
		for (int i = 0; i < num_row; i++)
		{
			for (int j = 0; j < num_column; j++)
			{
				in_data >> val;
				rows[i].append(val);
			}
		}
	}

		void out(ostream& out)
		{
			for(int i = 0;i<num_row;i++)
			{
				LinkNode *p = rows[i].head;
				while(p)
				{
					out<<p->value<<" ";
					p = p->next;
				}
				out<<endl;
			}
		}
//	void out()
//	{
//		for (int i = 0; i <ans_row; i++)
//		{
//			LinkNode* p = rows[i].head;
//			while (p)
//			{
//				cout << p->value << " ";
//				p = p->next;
//			}
//			cout << endl;
//		}
//	}


	Matrix equivalent_joins(Matrix& other, int column1, int column2)
	{
		Matrix ans(this->num_row * other.num_row, this->num_column * other.num_column);
		//第一个矩阵 
		for (int i = 0; i < this->num_row; i++)
		{
			int count1 = 1;
			//bool is_euqal = false;
			LinkNode* current1 = rows[i].head;
			while (count1 < column1)
			{
				current1 = current1->next;
				count1++;
			}
			int val1 = current1->value;

			//第二个矩阵 
			for (int j = 0; j < other.num_row; j++)
			{
				int count2 = 1;
				LinkNode* current2 = other.rows[j].head;
				while (count2 < column2)
				{
					current2 = current2->next;
					count2++;
				}
				int val2 = current2->value;
				if (val1 == val2)
				{
					//?
					ans.rows[ans_row].head = this->rows[i].head;
					LinkNode* p = this->rows[i].head;
					for (int k = 1; k < this->num_column; k++)
					{
						p = p->next;
					}

					p->next = other.rows[j].head;
					ans_row++;
				}
			}

		}
		return ans;

	}

};
int main()
{
	ifstream in_data("in.txt");
	ofstream out_data("abc.out");

	if (!in_data.is_open())
	{
		cerr << "Unable to open the file" << endl;
	}
	int r1, c1;
	in_data >> r1 >> c1;
	Matrix R(r1, c1);
	R.initialize(in_data);

	int r2, c2;
	in_data >> r2 >> c2;
	Matrix S(r2, c2);
	S.initialize(in_data);

	int column1, column2;
	in_data >> column1 >> column2;

	Matrix C = R.equivalent_joins(S, column1, column2);
	C.out(out_data);
	//C.out();
	return 0;

}

