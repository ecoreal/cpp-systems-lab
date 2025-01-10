//////#include<iostream>
////////#include<string>
//////using namespace std;
//////
//////int main()
//////{
//////	/*string s = "a+b=12\n";
//////	char c[] = "a+b=12\n";
//////	cout << "sizeof s is:" << s.length()<< endl;
//////	cout << "sizeof c is:" << sizeof(c)<< endl;
//////	cout << "sizeof s is:" <<strlen(c)<< endl;*/
//////
//////	/*const M = 10;
//////	const char ch;*/
//////
//////	int x = 2;
//////	int y = 3;
//////	int z = 0;
//////	//x = ++y;
//////	//x += y++;
//////	//++x = ++y;
//////
//////
//////
//////
//////	//x = 5; y = 8; 
//////	////z = ++x * y;
//////	//z = x * y++;
//////	//cout << "x: " << x << "  " << "y: " << y << "  " << "z: " << z << endl;
//////
//////	/*const char* STRING = "This is a string";
//////	cout << STRING << sizeof(STRING) << endl;
//////	char c[] = "This is a string";
//////	cout << c << endl;*/
//////	int a = 8;
//////	a >>= 2;
//////	cout << a << endl;
//////	system("pause"); return 0;
//////}
////
//////
//////#include<iostream>
//////#define OUT cout<<"Hello World! "<<std::endl;
//////using namespace std;
//////class A
//////{
//////public:
//////	A() { cout << "Constructor" << endl; }
//////	A(const A&) { cout << "Copy Constructor" << endl; }
//////	//A(const A&&)noexcept { cout << "Move Constructor" << endl; }
//////	~A() {}
//////};
//////
//////A getA(){
//////	A a;
//////	return a;
//////}
//////
//////int main(){
//////	A a = getA();// getA()是一个右值
//////	OUT
//////	system("pause");
//////	return 0;
//////}
////
////
//////
//////#include<iostream>
//////using namespace std;
//////
//////int main()
//////{
//////	char p[] = "string";
//////	/*cout << p + 3 << endl;
//////	cout << &p << endl;
//////	cout << (void*)p << endl;*/
//////	
//////	int b[10]={0}, * pb = b;
//////	*++pb = 24;
//////
//////	for (int i = 0; i < 10; i++)
//////	{
//////		cout << b[i] << " ";
//////	}
//////	cout << endl;
//////
//////	cout << "______________________" << endl;
//////
//////	/*string s = "string";
//////	cout << s << endl;
//////	cout << &s << endl;
//////	cout << (void*)s << endl;*/
//////
//////
//////
//////	return 0;
//////}
//////
//////#include<iostream>
//////using namespace std;
//////
//////int main()
//////{
//////	long int* p1, * p2;
//////	short score[10] = { 84,65,77,60,88,86,92,93,70,66 };
//////	p1 = (long int*)&score[0];
//////	p2 = (long int*)(score + 4);
//////	cout << p2 - p1 << endl;
//////
//////	return 0;
//////}
////
//////
//////
//////#include<iostream>#include<iterator>
//////using namespace std;
//////
//////class Time
//////{
//////public:
//////	Time(int i):b(i) {};
//////	friend Time& operator++(Time& t);
//////	friend Time operator++(Time& t, int);
//////	friend ostream& operator<<(ostream& out, Time t);
//////	int b;
//////};
//////
//////ostream& operator<<(ostream& out, Time t)
//////{
//////	out << t.b ;
//////	return out;
//////}
//////
//////Time operator++(Time& t, int)
//////{
//////	Time temp = t;
//////	++t;
//////	return temp;
//////}
//////
//////Time& operator++( Time& t)
//////{
//////	++t.b;
//////	return t;
//////}
//////
//////
//////int main()
//////{
//////	Time t(10);
//////	cout << t++ << endl;
//////	cout << ++t << endl;
//////	
//////
//////	return 0;
//////}
////
//////
//////
//////#include <iostream>
//////using namespace std;
//////class Base
//////{
//////public:
//////	void Display()
//////	{
//////		cout << "Display in Base"<< endl;
//////	}
//////	virtual void Print()
//////	{
//////		cout << "Print in Base "<< endl;
//////	}
//////};
//////
//////class Derived : public Base
//////{
//////public:
//////	void Display()
//////	{
//////		cout << "“Display in Derived”" << endl;
//////	}
//////	virtual void Print()
//////	{
//////		cout << "“Print in Derived” "<< endl;
//////	}
//////};
//////int main()
//////{
//////
//////	Base* b = new Base();
//////	Derived* d = new Derived();
//////	b->Display();
//////	d->Display();
//////	b->Print();
//////	d->Print();
//////	b = d;
//////	b->Display();
//////	d->Display();
//////	b->Print();
//////	d->Print();
//////	return 0;
//////
//////}
////
////
////#include<iostream>
////#include<vector>
////using namespace std;
////
////int main()
////{
////	int w, x, h, q, ans;
////	cin >> w >> x >> h >> q;
////	int v1[21][21][21] = {0};
////
////	while (q--)
////	{
////		int x1, y1, z1, x2, y2, z2;
////		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
////		for (int i = min(x1, x2); i <= max(x1, x2); i++)
////		{
////			for(int j=min(y1,y2);j<=max(y1,y2);j++)
////		}
////	}
////
////
////	for (int i = 0; i < w; i++)
////	{
////		for (int j = 0; j < x; j++)
////		{
////			for (int k = 0; k < h; k++)
////			{
////				v1[i][j][k] = 1;
////			}
////		}
////	}
////	int q;
////	cin >> q;
////	vector<int>v_pop;
////	for (int i = 0; i < q * 6; i++)
////	{
////		cin >> v_pop[i];
////	}
////
////	for (int i = 0; i < q * 6; i++)
////	{
////		v1[v_pop[i]][v_pop[i + 1]][v_pop[i + 2]] = 0;
////	}
////	return 0;
////}
//
////#include<iostream>
////#include<vector>
////using namespace std;
////
////int main()
////{
////	short a = 10;
////
////	a >>= 8;
////	cout<<sizeof()
////
////	return 0;
////
////}
//
//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<vector>
//
//using namespace std;
//
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode(int x) :val(x), next(NULL) {};
//};
//
//void reorderList(ListNode* head)
//{
//	if (head == nullptr) return;
//	vector<ListNode*>List_vector;
//	ListNode* s = head;
//	while (s != nullptr)
//	{
//		List_vector.push_back(s);
//		s = s->next;
//	}
//
//	int i = 0, j = List_vector.size() - 1;
//	while (i < j)
//	{
//	
//
//		List_vector[i]->next = List_vector[j];
//		i++;
//
//		if (i == j) break;
//
//		List_vector[j]->next = List_vector[i];
//		j--;
//
//		if (i == j) break;
//
//	}
//	List_vector[i]->next = nullptr;
//
//}
//
//int main()
//{
//	fstream in_data("in.txt");
//
//	if (!in_data.is_open())
//	{
//		cout << "Error Opening The File" << endl;
//	}
//
//	string line;
//	getline(in_data, line);
//	istringstream input(line);
//
//	int num = 0;
//	vector<int>nums;
//
//	while (input >> num)
//	{
//		nums.push_back(num);
//	}
//
//	ListNode* head = new ListNode(nums[0]);
//	ListNode* s;
//	ListNode* r;
//	r = head;
//
//	for (int i = 1; i < nums.size(); i++)
//	{
//		s = new ListNode(nums[i]);
//		r->next = s;
//		r = s;
//	}
//	r->next = nullptr;
//
//	reorderList(head);
//
//	while (head != nullptr)
//	{
//		cout << head->val << endl;
//		head = head->next;
//	}
//
//}
//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//
//	unsigned int x = 0xFFFFFF00;
//	char* point = (char*)&x;
//
//	for (int i = 0; i < 3; i++)
//	{
//		char a = (*point) ;
//		cout << a << endl;
//	}
//}

#include<iostream> 
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void quick_sort(vector<int>& s, int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x)
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x)
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1);
		quick_sort(s, i + 1, r);
	}
}

vector<int> integrate(vector<int>arr1, vector<int>arr2)
{
	quick_sort(arr1, 0, (int)arr1.size() - 1);
	quick_sort(arr2, 0, (int)arr2.size() - 1);
	//sort(arr1.begin(),arr1.end());
	//sort(arr2.begin(),arr2.end());
	int i = 0, j = 0;
	vector<int>ans;

	while (i < (int)arr1.size() && j < (int)arr2.size())
	{
		if (arr1[i] < arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
		}
		else if (arr1[i] == arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
		else
		{
			ans.push_back(arr2[j]);
			j++;
		}
	}

	while (i < (int)arr1.size())
	{
		ans.push_back(arr1[i]);
		i++;
	}

	while (j < (int)arr2.size())
	{
		ans.push_back(arr2[j]);
		j++;
	}
	return ans;
}
int main()
{
	ifstream in_data("in.txt");
	if (!in_data.is_open())
	{
		cerr << "Unable to open input file." << endl;
	}

	string line;
	getline(in_data, line);
	stringstream ss0(line);;
	int num1, num2, temp;

	
	ss0 >> num1;
	ss0 >> num2;

	vector<int>nums1, nums2, ans;

	getline(in_data, line);
	stringstream ss1(line);
	while (ss1 >> temp)
	{
		nums1.push_back(temp);
	}

	getline(in_data, line);
	stringstream ss2(line);
	while (ss2 >> temp)
	{
		nums2.push_back(temp);
	}

	ans = integrate(nums1, nums2);

	for (int i = 0; i < (int)ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

}

