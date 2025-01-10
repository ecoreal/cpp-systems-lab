//version--1.0
//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<vector>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//	Node(int val):data(val),next(nullptr){};
//	
//};
//
//Node* create_circle(int M)
//{
//	Node* first = new Node(1);
//	Node* temp = first;
//	for(int i=2;i<=M;i++)
//	{
//		temp->next = new Node(i);
//		temp = temp->next; 
//	}
//	
//	temp->next=first;
//	
//	return first;
//	
//}
//
//void add_node(Node* final,int val)
//{
//	final->next = new Node(val);
//	final = final->next;
//
//} 
//Node* Joseph(Node* first,int code,int n)
//{
//	Node* ans = nullptr;
//	Node* cur;
//	Node* cur_next;
//	
//	for(int i=1;i<=n;i++)
//	{
//		cur = first;
//		int j = 1;
//		while(j!=code)
//		{
//			j++;
//			cur = cur->next; 
//		}
//		if(!ans)
//		{
//			ans = new Node(cur->data);
//			
//			Node* ans_first = ans;
//		}else {
//			ans->next = new Node(cur->data);
//			ans = ans->next;
//		}
//		
//		cur_next = cur->next;
//		cur->data = cur_next->data;
//		delete cur_next;
//		first = cur;
//		
//	}
//	
//	ans->next = ans_first;
//	
//	return ans_first;
//} 
//
//int main()
//{
//	ifstream in_data("in.txt");
//	if(!in_data.is_open())
//	{
//		cerr<<"Unable to open the file"<<endl;
//	}
//	string line;
//	getline(in_data,line);
//	stringstream ss(line);
//	
//	int M =0;
//	ss>>M;
//	
//	vector<int>codes;
//	int code;
//	while(ss>>code)
//	{
//		codes.push_back(code);
//	}
//	
//	Node* head=nullptr;
//	
//	head = create_circle(M);
//	
//	for(int i=0;i<(int)sizeof(codes);i++)
//	{
//		head = Joseph(head ,codes[i],M);
//	}
//	
//	cout<<head->data<<endl;
//	
//	Node* first = head;
//	head = head->next;
//	
//	while(head!=first)
//	{
//		cout<<head->data<<endl;
//	}
//}


//version--2.0(finish debug)
//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<vector>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//	Node(int val) :data(val), next(nullptr) {};
//
//};
//
//Node* create_circle(int M)
//{
//	Node* first = new Node(1);
//	Node* temp = first;
//	for (int i = 2; i <= M; i++)
//	{
//		temp->next = new Node(i);
//		temp = temp->next;
//	}
//
//	temp->next = first;
//
//	return first;
//
//}
//
//void add_node(Node* final, int val)
//{
//	final->next = new Node(val);
//	final = final->next;
//
//}
//Node* Joseph(Node* first, int code, int n)
//{
//	Node* ans = nullptr;
//	Node* cur = first;
//	Node* cur_next;
//	Node* ans_first = nullptr;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cur = first;
//		int j = 1;
//		while (j != code)
//		{
//			j++;
//			cur = cur->next;
//		}
//		if (!ans)
//		{
//			ans = new Node(cur->data);
//
//			ans_first = ans;
//		}
//		else {
//			ans->next = new Node(cur->data);
//			ans = ans->next;
//		}
//
//		cur_next = cur->next;
//		cur->data = cur_next->data;
//		cur->next = cur_next->next;
//		delete cur_next;
//		first = cur;
//
//	}
//
//	ans->next = ans_first;
//
//	return ans_first;
//}
//
//int main()
//{
////	ifstream in_data("in.txt");
////	if (!in_data.is_open())
////	{
////		cerr << "Unable to open the file" << endl;
////	}
////	
////	string line;
////	getline(in_data, line);
////	stringstream ss(line);
//
//	int M = 0;
////	ss >> M;
//    cin>>M;
//
//	vector<int>codes;
//	int code;
// 	while (cin >> code)
//	{
//		codes.push_back(code);
//	}
//
//	Node* head = nullptr;
//
//	head = create_circle(M);
//
//	for (int i = 0; i <(int)codes.size(); i++)
//	{
//		head = Joseph(head, codes[i], M);
//	}
//
//	cout << head->data <<" ";
//	
//	Node* first = head;
//	head = head->next;
//
//	while (head != first)
//	{
//		cout << head->data <<"  ";
//		head = head->next;
//	}
//}

//version--3.0(change format)

//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<vector>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//	Node(int val) :data(val), next(nullptr) {};
//
//};
//class 
//Node* create_circle(int M)
//{
//	Node* first = new Node(1);
//	Node* temp = first;
//	for (int i = 2; i <= M; i++)
//	{
//		temp->next = new Node(i);
//		temp = temp->next;
//	}
//
//	temp->next = first;
//
//	return first;
//
//}
//
//void add_node(Node* final, int val)
//{
//	final->next = new Node(val);
//	final = final->next;
//
//}
//Node* Joseph(Node* first, int code, int n)
//{
//	Node* ans = nullptr;
//	Node* cur = first;
//	Node* cur_next;
//	Node* ans_first = nullptr;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cur = first;
//		int j = 1;
//		while (j != code)
//		{
//			j++;
//			cur = cur->next;
//		}
//		if (!ans)
//		{
//			ans = new Node(cur->data);
//
//			ans_first = ans;
//		}
//		else {
//			ans->next = new Node(cur->data);
//			ans = ans->next;
//		}
//
//		cur_next = cur->next;
//		cur->data = cur_next->data;
//		cur->next = cur_next->next;
//		delete cur_next;
//		first = cur;
//
//	}
//
//	ans->next = ans_first;
//
//	return ans_first;
//}
//
//int main()
//{
////	ifstream in_data("in.txt");
////	if (!in_data.is_open())
////	{
////		cerr << "Unable to open the file" << endl;
////	}
////	
////	string line;
////	getline(in_data, line);
////	stringstream ss(line);
//
//	int M = 0;
////	ss >> M;
//    cin>>M;
//
//	vector<int>codes;
//	int code;
// 	while (cin >> code)
//	{
//		codes.push_back(code);
//	}
//
//	Node* head = nullptr;
//
//	head = create_circle(M);
//
//	for (int i = 0; i <(int)codes.size(); i++)
//	{
//		head = Joseph(head, codes[i], M);
//	}
//
////	cout << head->data <<" ";
////	
////	Node* first = head;
////	head = head->next;
////
////	while (head != first)
////	{
////		cout << head->data <<"  ";
////		head = head->next;
////	}
//
//    for (int i = 0; i < M; i++) 
//	{
//        printf("%4d", head->data);
//        head = head->next;
//    }
//	
//}


































//version--4.0(To Module)

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val) :data(val), next(nullptr) {};

};

class Joseph
{
public:
	Node* first = nullptr;
	int M = 0;
	vector<int>codes;
	
	
	Joseph (int m, vector<int>codes);
	Node* create_circle(int M);
	Node* my_sort(Node* first, int code, int n);
	
		
};

Joseph::Joseph (int m,vector<int>codes) : M(m),codes(codes)
{
    
	first = create_circle(M);

    for (int i = 0; i <(int)codes.size(); i++)
    {
    	first = my_sort(first, codes[i], M);
    }
    
}
Node* Joseph::create_circle(int M)
{
	Node* first = new Node(1);
	Node* temp = first;
	for (int i = 2; i <= M; i++)
	{
		temp->next = new Node(i);
		temp = temp->next;
	}

	temp->next = first;

	return first;

}

Node* Joseph::my_sort(Node* first, int code, int n)
{
	Node* ans = nullptr;
	Node* cur = first;
	Node* cur_next;
	Node* ans_first = nullptr;

	for (int i = 1; i <= n; i++)
	{
		cur = first;
		int j = 1;
		while (j != code)
		{
			j++;
			cur = cur->next;
		}
		if (!ans)
		{
			ans = new Node(cur->data);

			ans_first = ans;
		}
		else {
			ans->next = new Node(cur->data);
			ans = ans->next;
		}

		cur_next = cur->next;
		cur->data = cur_next->data;
		cur->next = cur_next->next;
		delete cur_next;
		first = cur;

	}

	ans->next = ans_first;

	return ans_first;
}

int main()
{
	int M =0, code =0;
	cin>>M;
	vector<int>v;
	
 	while (cin >> code)
	{
		v.push_back(code);
	}
	
	Joseph solution(M,v);


    for (int i = 0; i < solution.M; i++) 
	{
        printf("%4d", solution.first->data);
        solution.first = solution.first->next;
    }
	
}


