//main.c
#include <stdio.h>
#include "exam.h"

void main()
{
	int arr[2][3];
	int i,j;

	foo(arr, 10);				//arr[0][0] = 10
	woo(arr+1, 20);				//arr[0][1] = 20
	goo(arr[1], 30);			//arr[0][2] = 30
	hoo(&arr[1][1], 40);		//arr[1][0] = 40
	eoo((*arr)+1, 50);			//arr[1][1] = 50
	aoo(arr[0], 60);			//arr[1][2] = 60

	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
		}
	}
}