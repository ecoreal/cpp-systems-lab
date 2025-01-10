//version 1.0
//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<unordered_map>
//#include<vector>
//using namespace std;
//int book[1001] = {0};
//
//class Member
//{
//public:
//	int ID;
//	Member *next;
//	Member():ID(0),next(nullptr){};
//	Member(int id):ID(id),next(nullptr){};
//	
//};
//
//class Queue
//{
//public:
//	Member* front;
//	Member* rear;
//	Queue()
//	{
//		front = rear = nullptr;
//	}
//	
//	~Queue()
//	{
//		Member* temp = front;
//		while(front!= nullptr)
//		{
//			
//			front = front->next;
//			delete temp;
//			temp = front;
//		}
//		rear = nullptr;
//	}
//	
//	bool is_empty()
//	{
//		return front == nullptr;
//	}
//	
//	void enqueue(Member m)
//	{
//		Member* new_member = new Member(m.ID);
//		if(rear != nullptr)
//		{
//			rear->next = new_member;
//		}
//		rear = new_member;
////		
//		if(front == nullptr)
//		{
//			front = new_member;
//		}
//	}
//	
//	
//	
//	Member dequeue()
//	{
//		if(!is_empty())
//		{
//			Member ans = Member(front->ID);
//			Member* p = front;
//			front = front ->next;
//			if(front = nullptr)
//			{
//				rear = nullptr;
//			}
//			delete p;
//			return ans;
//		}
//		else
//		{
//			cerr<<"Queue is empty"<<endl;
//			return Member(-1);
//		}
//	}
//	
//	
//};
//
//
//
//int main()
//{
//
//	ifstream in_data("in.txt");
//	if (!in_data.is_open()) 
//	{
//		cerr << "Unable to open input file." << endl;
//		return 1;
//    }
//    
//	int num_team;
//	int member;
//	in_data>>num_team;
//
//	unordered_map<int,int>team;
//	//initialize data;
//	for(int i = 0;i<num_team;i++)
//	{
//		int num_member;
//		in_data>>num_member;
//		for(int j = 0;j<num_member;j++)
//		{
//			int member;
//			in_data>>member;
//			//key值对应团队编号 
//			team[member] = j;
//		}
//	}
//	
//	vector<Queue> Queues(num_team);
//	vector<int> team_order;
//	int team_order_index = 0;
//	unordered_map<int,bool> is_in_queues; 
//	for(int i = 0;i<num_team;i++)
//	{
//		is_in_queues[i] = false;
//	}
//	
//	Member ans = Member(-1);
//	int team_id = -1;
//	int member_id = -1;;
//	//initialize  command;
//	string command;
//	while(in_data>>command && command != "STOP")
//	{
//		if(command == "ENQUEUE")
//		{
//			//enter queue 
//			in_data>>member_id;
//			team_id = team[member_id];
//			if(!is_in_queues[team_id])
//			{
//				team_order.push_back(team_id);
//				is_in_queues[team_id] == true;
//			}
//			Queues[team_id].enqueue(Member(member_id));
//
//		}
//		else if(command == "DEQUEUE") 
//		{
//			//pop && delete
//			team_id = team_order[team_order_index];
//			ans = Queues[team_id].dequeue();
//			cout<<ans.ID<<endl;
//			if(Queues[team_id].is_empty())
//			{
//				team_order_index++;
//				is_in_queues[team_id] == false;
//			}
//
//		}
//		
//	}	
//}


#include<iostream>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include<vector>
using namespace std;
//int book[1001] = { 0 };

class Member
{
public:
	int ID;
	Member* next;
	Member() :ID(0), next(nullptr) {};
	Member(int id) :ID(id), next(nullptr) {};

};

class Queue
{
public:
	Member* front;
	Member* rear;
	Queue()
	{
		front = rear = nullptr;
	}

	~Queue()
	{
		Member* temp = front;
		while (front != nullptr)
		{

			front = front->next;
			delete temp;
			temp = front;
		}
		rear = nullptr;
	}

	bool is_empty()
	{
		return front == nullptr;
	}

	void enqueue(Member m)
	{
		Member* new_member = new Member(m.ID);
		if (rear != nullptr)
		{
			rear->next = new_member;
		}
		rear = new_member;
		//		
		if (front == nullptr)
		{
			front = new_member;
		}
	}



	bool dequeue(Member &ans)
	{
		if (!is_empty())
		{
			 ans = Member(front->ID);
			Member* p = front;
			front = front->next;
			if (front == nullptr)
			{
				rear = nullptr;
			}

			delete p;

			return true;
    	}
		else
		{
			cerr << "Queue is empty" << endl;
			return false;
		}
		
	}


};



int main()
{

	ifstream in_data("in.txt");
	if (!in_data.is_open())
	{
		cerr << "Unable to open input file." << endl;
		return 1;
	}

	int num_team;
	int member;
	in_data >> num_team;

	unordered_map<int, int>team;
	//initialize data;
	for (int i = 0; i < num_team; i++)
	{
		int num_member;
		in_data >> num_member;
		for (int j = 0; j < num_member; j++)
		{
			in_data >> member;
			//key值对应团队编号 
			team[member] = i;
		}
	}



	vector<Queue> Queues(num_team);
	vector<int> team_order;
	int team_order_index = 0;
	unordered_map<int, bool> is_in_queues;

	for (int i = 0; i < num_team; i++)
	{
		is_in_queues[i] = false;
	}

	Member ans = Member(-1);
	int team_id = -1;
	int member_id = -1;;
	//initialize  command;
	string command;
	while (in_data >> command && command != "STOP")
	{
		if (command == "ENQUEUE")
		{
			//enter queue 
			in_data >> member_id;
			team_id = team[member_id];
			if (!is_in_queues[team_id])
			{
				team_order.push_back(team_id);
				is_in_queues[team_id] = true;
			}
			Queues[team_id].enqueue(Member(member_id));

		}

		else if (command == "DEQUEUE")
		{
			//pop && delete
			team_id = team_order[team_order_index];
			Queues[team_id].dequeue(ans);
			cout << ans.ID << endl;
			if (Queues[team_id].is_empty())
			{
				team_order_index++;
				is_in_queues[team_id] = false;
			}

		}

	}

	return 0;

}
