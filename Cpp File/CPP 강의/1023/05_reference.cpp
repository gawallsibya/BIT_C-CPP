//reference : ������, ��Ī
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

// Ȱ�뿹1)
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
// Ȱ�뿹2)
/*
int arr[2] = {1,2};
int& foo()
{
	return arr[0];
}

void main()
{
	foo() = 10;		// 1 = 10		: ������ ���� arr[0] = 10

	int num = foo();	// num = 1;               num = arr[0];

	cout << arr[0] << endl;		// 10
}
*/

// ������ ��
int& foo()
{
	int num = 10;
	return num;			// ������ ���� : �������� ������ ���� ����
}
void main()
{
	int n = foo();
	cout << n << endl;
}