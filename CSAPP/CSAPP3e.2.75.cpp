#include<iostream>
using namespace std;
typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);   
    printf("\n");
}

void show_short(short x){
	show_bytes((byte_pointer)&x,sizeof(short)); 
}

void show_long(long x){
	show_bytes((byte_pointer)&x,sizeof(short)); 
}

void show_double(double x){
	show_bytes((byte_pointer)&x,sizeof(short)); 
}

int main(){
	short a = 12345;
	long b = 9876543210;
	double c = 3.14159;
	show_short(a);
	show_long(b);
	show_double(c); 
	
}
