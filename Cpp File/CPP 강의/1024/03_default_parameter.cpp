#include <iostream>
using namespace std;


void foo(int num, char ch = 'A') 
{
	cout << num << " : " << ch << endl; 
}
//void foo(int num) {}

void main()
{
	foo(10, 'a');
	foo(10);
//	foo();			// error...
}

/*
void foo(int num , char ch = 'A') { cout << num << " : " << ch << endl; }

// 뒤에서 부터....
//void woo(int num = 10, char ch );    { cout << num << " : " << ch << endl; }

void main()
{
	foo(10, 'a');		foo(10);//		foo();			

//	woo('A');		
}*/