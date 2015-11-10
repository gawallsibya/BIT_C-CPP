#include <iostream>
using namespace std;

// 대입연산
class CA
{
	int num1;
	int num2;
private:
//	void operator=(CA & a){}
public:
	CA(int _n1, int _n2 ) : num1(_n1), num2(_n2) {}
	CA() {}
	void DataPrint() { cout << num1 << " : " << num2 << endl; }
	
//	void operator=(CA & a)
//	{
//		num1	= a.num1;
///		num2	= a.num2;
//	}
};


void main()
{
	CA	a(10, 20);
	CA  b;

	b	= a;		// b.operator=(a)

	b.DataPrint();
}