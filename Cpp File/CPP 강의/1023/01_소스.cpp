//
/*
#include <stdio.h>		// ��ǥ h ���� 

void main()				// entry point function
{
	printf("Hello, World!\n");	// IO ����Լ�
}
*/

/*
//#include <iostream.h>	// 1997?
#include <iostream>

namespace AAA
{
	void foo()	{		printf("AAA::FOO\n");	}
	void woo()	{		printf("AAA::WOO\n");	}
}

namespace BBB
{
	void foo()
	{
		printf("BBB::FOO\n");
	}
}

using AAA::foo;
using AAA::woo;

using namespace AAA;
void main()
{
	foo();
	BBB::foo();
	woo();
	woo();
//	AAA::foo();
//	BBB::foo();
//	AAA::woo();
//	cout << "Hello, World\n";	// IO ��°�ü
}
*/

/*
#include <iostream>
using namespace std;

void main()
{
	cout << "TEST\n";		// cout  : ��� ��ü  << : ��� ������(�Լ�)

	cout << 10.1 << " : " << 'a' << 10 << endl; 

	int num;	cin  >> num;

	float f;	cin >> f;

	cout << num << " : " << f << endl; 
}
*/