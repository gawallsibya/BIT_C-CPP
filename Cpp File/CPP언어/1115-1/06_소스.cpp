// ����ȯ
#include <iostream>
using namespace std;

class CA
{
	int num1;

public:
explicit	CA(int _n1) : num1(_n1){}		// ��ȯ ������ ���� 
	CA() {}
	void DataPrint() { cout << num1 << endl; }

	operator int()		// ��ȯ ������ 
	{
		return num1;
	}
};

void main()
{
	CA		a(10);
//	CA		b = 20;	// CA b = CA(20)	

//	a	= 20;		// CA == int ==> a = CA(20)

	int num		= a;		// int = CA
}
