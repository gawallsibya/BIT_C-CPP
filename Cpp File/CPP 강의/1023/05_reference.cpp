//reference : 참조자, 별칭
#include <iostream>
using namespace std;

/*
void main()
{
	int num;
	int & r = num;

	num = 100;
	r   = 10;

	printf("%d : %d\n", num, r);
}
*/

// 활용예1)
/*
void foo( int n )	{		n++;	}
void goo(int *pn)	{    (*pn)++;	}
void woo(const int & n)   {  n++;			}

void main()
{
	int num = 10;
//	foo(num);		cout << num << endl;	// call by value

	goo(&num);		cout << num << endl;	// call by address
	woo(num);		cout << num << endl;	// call by reference
}
*/
// 활용예2)
/*
int arr[2] = {1,2};
int& foo()
{
	return arr[0];
}

void main()
{
	foo() = 10;		// 1 = 10		: 참조자 리턴 arr[0] = 10

	int num = foo();	// num = 1;               num = arr[0];

	cout << arr[0] << endl;		// 10
}
*/

// 주의할 점
int& foo()
{
	int num = 10;
	return num;			// 참조자 리턴 : 지역변수 참조자 리턴 금지
}
void main()
{
	int n = foo();
	cout << n << endl;
}