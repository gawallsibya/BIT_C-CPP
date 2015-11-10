//main.c
#include <stdio.h>
#include "exam.h"

void main()
{
	int arr[5] = {1,2,3,4,5};
	int *pArr[5];
	int i;

	foo(pArr, arr);			//pArr[0] = &arr[0]
	woo(&pArr[1], arr);		//pArr[1] = &arr[1]
	goo(pArr+2, arr+4);		//pArr[2] = &arr[2]
	hoo(pArr, arr+2);		//pArr[3] = &arr[3]
	eoo(&pArr[2], arr);		//pArr[4] = &arr[4]


	for(i=0; i<5; i++)
	{
		printf("[%d] = %d\n", i, *pArr[i]);
	}
}