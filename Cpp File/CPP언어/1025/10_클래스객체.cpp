#include <iostream>
using namespace std;

/*
class CA
{
public:
	int num;	
	static int s_num;		// static ¸É¹ö 
};

int CA::s_num = 0;

void main()
{
	CA::s_num = 100;
	cout << CA::s_num << endl; 

	CA a;		//a.s_num = 200;		
	CA b;		//b.s_num = 300;

	cout << a.s_num << endl;		// 300
}
*/

/*
class SCV
{
	static int mineral;
	static int gas;
public:
//	SCV()  { mineral = 50; gas = 0; }
};

int SCV::mineral = 50;
int SCV::gas = 0;

void main()
{
	SCV  scv[5];
}
*/

class DD
{
	int num;
public:
	static void foo() { cout << "S_FOO()" << endl;  
//						woo();			// ??
						}
	void woo()  { num = 1200;   cout << "WOO" << endl; }
};

void main()
{
	DD::foo();

	DD		d;			d.woo();		//d.foo();
}
