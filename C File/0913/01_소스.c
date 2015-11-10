#include <stdio.h>

/*
void main()
{
	int num1 = 1;
	int num2 = 1;
	int num3 = 0;

	int num4 =  num1 || ( num2  && num3 );	// 1 || 0 

	printf("%d : %d : %d : %d\n", num1, num2, num3, num4);	//1
}
*/

/*
void main()
{
	int num1 = 1;
	int num2 = 0;
	int num3 = 1;

//	int num4 =  num1 && ++num2  || num3++;
//	int num4 =  num1 && num2++  || num3++;

	printf("%d : %d : %d : %d\n", num1, num2, num3, num4);	// 1 : 1 : 1 : 1
}
*/


/*
void main()
{
	int num		= 10;
	int num1	= num++;

	printf("%d : %d\n", num, num1);		// 11 : 10

	num1		= ++num;
	printf("%d : %d\n", num, num1);		// 12 : 12
}
*/

/*
// T : 0을 제외한 모든수
void main()
{
	int num		= 10;
	int num1	= -10;		

	int num2	= num && num1;		// T && T

	printf("%d\n", num2);			// 1
}
*/