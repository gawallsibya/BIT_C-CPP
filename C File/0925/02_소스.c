//void*

//1. 무었을 저장 ?
//2. 어떻게 사용 ?
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