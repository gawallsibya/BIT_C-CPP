//
/*
#include <stdio.h>		// 대표 h 파일 

void main()				// entry point function
{
	printf("Hello, World!\n");	// IO 출력함수
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
//	cout << "Hello, World\n";	// IO 출력객체
}
*/

/*
#include <iostream>
using namespace std;

void main()
{
	cout << "TEST\n";		// cout  : 출력 객체  << : 출력 연산자(함수)

	cout << 10.1 << " : " << 'a' << 10 << endl; 

	int num;	cin  >> num;

	float f;	cin >> f;

	cout << num << " : " << f << endl; 
}
*/