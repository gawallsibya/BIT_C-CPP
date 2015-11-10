//°´Ã¼ »ý¼º
#include <iostream>
using namespace std;

class CA
{
	int a;
public:
	CA() { cout << "CA()" << endl; }
	CA(int _a) : a(_a) { cout << "CA(INT)" << endl; }
};

class CB	: public CA
{
	int b;
public:
	CB(int _a, int _b) : b(_b), CA(_a)
	{ cout << "CB(INT, INT)" << endl; }
};

void main()
{
	CB b(10, 20);
}
