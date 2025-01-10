//#include<iostream>
//using namespace std;
//
//int main()
//{
////	int x = 8;
////	x = x>>3;
////	cout<<x;
//	int *p = NULL;
//	cout<<p<<endl;
//	
//}

//#include <stdio.h>
//int main()
//{
//	int *p = NULL;
//	printf("%p", p);
//	return 0;
//}

#include<iostream>
using namespace std;

union ele { 
    struct {
        long *p;
        long y; 
    } el;
    
    struct { 
        long x;
        union ele *next; 
    } e2;
};

int main()
{
	ele u1;
	cout<<(u1.e2.next)->e2.x;
	
}
