#include <stdio.h>

void foo (int arr[] ); // 1. ∆˜¿Œ≈Õ 
void woo ( int arr[]);
void goo ( int num );
void main()
{
	int arr[3] = { 1,3,5};			
	int i;
	foo( arr );		// 2. call by reference
	woo( arr + 1);
	goo( arr[1]);	// call by value

	for(i=0; i<3; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}
void goo ( int num )
{

}
void woo ( int arr[])
{
	arr[-1]  = 200;		
}
void foo( int arr[] )		
{
	arr[2] = 100;
}