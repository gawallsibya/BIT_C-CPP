//fun1.c
//[¿¬»êÀÚ]

#include "std.h"

void fun1_1()
{
	int a = -1, b = 20, c = 30;

	int x;

	x = ++a || ++b && ++c;

	printf("%d %d %d %d\n", x, a, b, c );//1 0 21 31		
}

void fun1_2()
{

	int a = -1, b = 20, c = 30;

	int x;

	x = ++a || ++b || ++c;

	printf("%d %d %d %d\n", x, a, b, c );//1 0 21 30
}


void fun1_3()
{
	int a = 5, b = 6, c = 5, d =1;
	int x; 

	x = a < b || a < c && c < d;

	printf("%d\n", x);		//1
}

void fun1_4()
{
	int x =2, y = 0, z = 2, k;

	k = ++x && ++y || ++z;

	printf("%d %d %d %d\n", x, y, z, k);//3 1 2 1	
}


void fun1_5()
{
	int x = 1, y = 2, z = 3, k;
	k = ++x || ++y && ++z;
	printf("%d %d %d %d\n", k, x, y, z);	// 1 2 2 3 
}