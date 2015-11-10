#include <stdio.h>

void foo( int (*parr)[3], int (*parr1)[3] );	// int arr[][3]
void woo( int *parr , int *parr1);		// int arr[]
void goo( int (*parr)[3], int (*parr1)[3]  ); // int arr[][3]
void hoo( int num  );	
void ooo( int *parr );		// int arr[]

void main()
{
	int arr[2][3];

	foo( arr, arr+1 );
	woo( arr[1], arr[2]);
	goo( &arr[1], &arr[0]);
	hoo( arr[2][2]);			// ......
	ooo( &arr[1][2]);			//
}
void foo( int (*parr)[3], int (*parr1)[3] )	// int arr[][3]
{
	parr[1][1]		= 5;
	parr1[0][-1]	= 3;
}

void woo( int *parr, int *parr1 )		// int arr[]
{
	parr[2]	= 6;
	parr1[-3]	= 4;
}

void goo( int (*parr)[3], int (*parr1)[3]   ) // int arr[][3]
{
	parr[-1][0]	= 1;
	parr1[0][1]	= 2;
}

void hoo( int num  )
{
}
void ooo( int *parr )		// int arr[]
{

}