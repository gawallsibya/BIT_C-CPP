// 1. ���� �Լ��� �����Ͻÿ�.
#include <stdio.h>
#include "exam.h"

void main()
{
	int arr[5];
	int i;
	int *pArr = arr+3;

	foo(arr);			// arr[0] = 10
	woo(arr+2);		    // arr[1] = 20
	goo(&arr[3]);		// arr[2] = 30
	hoo(pArr+2);		// arr[3] = 40
	ooo(pArr-1, 50);	// arr[4] = 50(���޵� 50���ڸ� ����)

	for(i=0; i<5; i++)
	{
		printf("[%d] %d\n", i, arr[i]);
	}
}

