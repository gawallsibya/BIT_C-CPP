//void*

//1. ������ ���� ?
//2. ��� ��� ?
#include <stdio.h>

void main()
{
	int num	= 10;
	char ch	= 'a';
	int *p;
	void *pv;

	p		= &num;			printf("*p : %d\n", *p);
//	p		= &ch;		// error..

	pv		= &num;			printf("*pv : %d\n", *(int*)pv);
	pv		= &ch;
}