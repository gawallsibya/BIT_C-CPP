#include <iostream>
using namespace std;

/*
class CA
{
public:
	CA()			  { cout << "CA()" << endl;			  }
	~CA()			  { cout << "~CA():" << endl;         }
};

void main()
{
//	CA	 a;								// �ν��Ͻ� : 1
//	CA   b(a);
//	CA  a1[10];							// �ν��Ͻ� : 10

	CA *pA = new CA();		// new CA
	delete pA;

//	CA *pa = (CA*)malloc(sizeof(CA));		// ������ �Ҹ��� ȣ��.XXXX
//	free(pa);
}
*/

class CA
{
	int num;
	char *p;
public:
	CA(int _num)	 
	{
		num = _num;
		p = new char[10];
		p[0] = 'a';
		cout << p[0] << endl;
		cout << "CA()" << endl;
		delete [] p;
	}

	~CA()
	{
		cout << "~CA():" << endl;
	}
};

void main()
{
	CA  a(10);
}