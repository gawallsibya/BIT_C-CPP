#include <stdio.h>

// 2차원 배열 포인터
/*
void main()
{
	int arr[3][4]	= { {1,  2,  3,  4},
						{5,  6,  7,  8},
						{9, 10, 11, 12}	};		 

	int (*p)[4]		= arr;		// p는 포인터

	printf("%d : %d\n", arr, p);			// 1245008 : 1245008
	printf("%d : %d\n", arr+1, p+1);		// 1245024 : 1245024
	printf("%d : %d\n", arr[1]+1, p[1]+1);  // 1245028 : 1245028
	printf("%d : %d\n", arr[2]-6, p[2]-6);	// 1245016 : 1245016
	printf("%d : %d\n", *(*(arr+2)+ 3) , *(*(p+2)+ 3) );	// 12
	printf("%d : %d\n", arr[2][3], arr[2][3]);				// 12

//	int *parr = arr[1];
//	printf("%d\n", *parr);
//	int **pparr = arr;				
}
*/


// 1차원 배열 포인터
/*
void main()
{
	int arr[6]	= {1,2,3,4,5,6};		// arr  : 1245032번지
	int *parr	= arr+3;				// parr : 1245044번지 

	printf("%d : %d\n", arr, parr);	// 1245032 : 1245032

	printf("%d : %d\n", arr+1, parr+1);			// 1245036 : 1245048
	printf("%d : %d\n", arr[1], parr[1]);		// 2 : 5
	printf("%d : %d\n", *(arr+2), *(parr+2));	// 3 : 6
}
*/