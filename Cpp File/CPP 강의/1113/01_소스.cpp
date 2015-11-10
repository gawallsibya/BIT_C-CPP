//
#include <iostream>
using namespace std;

class CA
{
public:
	int a;
	int a1;
	void foo() { cout << "CA::FOO()" << endl; }
};

class CB	: public CA
{
public:
	int b;
	void foo()  { CA::foo(); cout << "CB::FOO()" << endl; }	// overriding:ÀçÁ¤ÀÇ
};

void main()
{
	CB		b;			cout << sizeof(b) << endl; 
	b.foo();		//b.a;
}
