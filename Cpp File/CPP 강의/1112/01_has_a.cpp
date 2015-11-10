// has a : º“¿Ø
#include <iostream>
using namespace std;

class CA
{
	int ca_num;
public:
	CA()	{ cout << "CA()" << endl; }
	CA(int n) : ca_num(n)  { cout << "CA(int)" << endl; }
	~CA()	{ cout << "~CA()" << endl; }

};

class CB
{
	CA	a;
	int cb_num;
public:
	CB()	{ cout << "CB()" << endl;	}
	CB(int n1, int n2) : a(10), cb_num(n2) 	{  cout << "CB(int, int)" << endl; }
	~CB()	{ cout << "~CB()" << endl; }
};


void main()
{
	CB		b(10, 20);
}
