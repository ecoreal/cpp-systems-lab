	//#include<iostream>
	//#include<fstream>
	//#include<sstream>
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
	//Node* split(Node* head)
	//{
	//	//假如链表内没有数据或者只有一个数据 
	//	if (!head || !head->next) return head;
	//
	//	Node* slow = head;
	//	Node* fast = head->next;
	//
	//	while (fast && fast->next)
	//	{
	//		slow = slow->next;
	//		fast = fast->next->next;
	//	}
	//	Node* right = slow->next;
	//	//切断
	//	slow->next = nullptr;
	//	return right;
	//	
	//}
	//
	//Node* merge(Node* left,Node* right)
	//{
	//	
	////	if(!left) 
	////	{
	////		return right;
	////	}
	////	if(!right)
	////	{
	////		return left
	////	} 
	////	
	////	Node* merged =nullptr;
	////	if(left->data<=right->data)
	////	{
	////		merged =left;
	////		merged->next =merge(left->next,right);
	////	}else{
	////		merged =right;
	////		merged->next =merge(left,right->next);	
	////    } 
	////    return merged
	//    Node* ans = new Node(-1);
	//	Node* temp = ans;
	//
	//	while (left != nullptr && right != nullptr)
	//	{
	//		if (left->data < right->data)
	//		{
	//			temp->next = left;
	//			left = left->next;
	//			temp = temp->next;
	//		}
	//		else
	//		{
	//			temp->next = right;
	//			right = right->next;
	//			temp = temp->next;
	//		}
	//	}
	//	
	//	while (left != nullptr)
	//	{
	//		temp->next = left;
	//		left = left->next;
	//		temp = temp->next;
	//	}
	//	while (right != nullptr)
	//	{
	//		temp->next = right;
	//		right = right->next;
	//		temp = temp->next;
	//	}
	//
	//	return ans;
	//}
	//
	//
	//Node* BiSort(Node* head)
	//{
	//	if (!head || !head->next) return head;
	//
	//	Node* right = split(head);
	//	Node* left = head;
	//	
	//	left =BiSort(left);
	//	right =BiSort(right);
	//	
	//	return merge(left,right);
	//
	//
	//}
	//
	//
	//int main()
	//{
	//	ifstream in_data("in.txt");
	//	ofstream out_put("out.txt", ofstream::out | ofstream::trunc);
	//
	//	if (!in_data.is_open())
	//	{
	//		cerr << "Unable to open the input file" << endl;
	//	}
	//
	//	if (!out_put.is_open())
	//	{
	//		cerr << "Unable to create the output file" << endl;
	//	}
	//
	//	int num;
	//	string line;
	//	getline(in_data, line);
	//	stringstream ss(line);
	//	
	//	ss >> num;
	//	Node* head = new Node(num);
	//	Node* ans = nullptr;
	//	Node* temp = head;
	//
	//	while (ss >> num)
	//	{
	//		temp->next = new Node(num);
	//		temp = temp->next;
	//	}
	//
	//	ans = BiSort(head);
	//	
	//	while (ans != nullptr)
	//	{
	//		out_put << ans->data << " ";
	//		ans = ans->next;
	//	}
	//
	//}
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val) :data(val), next(nullptr) {};

};

Node* split(Node* head)
{
	//假如链表内没有数据或者只有一个数据 
	if (!head || !head->next) return head;

	Node* slow = head;
	Node* fast = head->next;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	Node* right = slow->next;
	//切断
	slow->next = nullptr;
	return right;

}

Node* merge(Node* left, Node* right)
{
	if(!left) 
	{
		return right;
	}
	if(!right)
	{
		return left; 
	} 
	
	Node* merged =nullptr;
	if(left->data<=right->data)
	{
		merged =left;
		merged->next =merge(left->next,right);
	}else{
		merged =right;
		merged->next =merge(left,right->next);	
	} 
	return merged;
	
//	Node* ans = nullptr;
//	if (left->data < right->data)
//	{
//		ans = left;
//		left = left->next;
//		ans = ans->next;
//	}
//	else
//	{
//		ans = right;
//		right = right->next;
//		ans = ans->next;
//	}
//
//	Node* temp = ans;
//
//	while (left != nullptr && right != nullptr)
//	{
//		if (left->data < right->data)
//		{
//			temp = left;
//			left = left->next;
//			temp = temp->next;
//		}
//		else
//		{
//			temp = right;
//			right = right->next;
//			temp = temp->next;
//		}
//	}
//	while (left != nullptr)
//	{
//		temp = left;
//		left = left->next;
//		temp = temp->next;
//	}
//	while (right != nullptr)
//	{
//		temp = right;
//		right = right->next;
//		temp = temp->next;
//	}
//
//
//	return ans;

}


Node* BiSort(Node* head)
{
	if (!head || !head->next) return head;

	Node* right = split(head);
	Node* left = head;

	left = BiSort(left);
	right = BiSort(right);

	return merge(left, right);


}


int main()
{
	ifstream in_data("in.txt");
	ofstream out_put("out.txt", ofstream::out | ofstream::trunc);

	if (!in_data.is_open())
	{
		cerr << "Unable to open the input file" << endl;
	}

	if (!out_put.is_open())
	{
		cerr << "Unable to create the output file" << endl;
	}

	int num;
	string line;
	getline(in_data, line);
	stringstream ss(line);

	ss >> num;
	Node* head = new Node(num);
	Node* ans = nullptr;
	Node* temp = head;

	while (ss >> num)
	{
		temp->next = new Node(num);
		temp = temp->next;
	}

	ans = BiSort(head);


	while (ans != nullptr)
	{
		out_put << ans->data << " ";
		ans = ans->next;
	}

}
