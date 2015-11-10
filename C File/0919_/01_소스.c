#include <stdio.h>
/*
void foo(int n,  int* n1);

void main()
{
	int num = 10;

	foo(num, &num);

	printf("%d\n", num);
}

void foo(int n,  int* n1)
{
	n	= 20;
	*n1	= 20;	// ??
}
*/

void MySwap( int *n1, int *n2);

void main()
{
	int num1 = 10, num2 = 20;

	printf("%d : %d\n", num1, num2);

	MySwap( &num1, &num2 );				// ???

	printf("%d : %d\n", num1, num2);
}

void MySwap( int *n1, int *n2)
{
	int temp;
	temp		= *n1;
	*n1			= *n2;
	*n2			= temp;
}