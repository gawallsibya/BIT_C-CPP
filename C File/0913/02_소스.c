// 비트 논리 연산자
#include <stdio.h>

int x = 5;
int y = 3;

void main()
{
	short num = 0;
	num		  = num | y;	// 0000 0011
	num		  = num << 4;	// 0011 0000
	
	num		  = num | x;	// 0011 000
							// 0000 0101 ==> 0011 0101
	printf("압축 : %d\n", num);	// 53
	//===========================================
	{
		int re		= num;			// 0011 0101

		int re_x    = num & 0xf;	// 0000 1111	==> 0000 0101
		int re_y	= num & 0xf0;	// 1111 0000    ==> 0011 0000

		re_y		= re_y >> 4;	// 0000 0011
		printf("X : %d y : %d\n", re_x, re_y);
//		printf("%d\n", re_x);

	}
	
	

}

/*
void main()
{
	short result = 7;	// 0000 0111
	// 2bit 상태
	int num	 = result & 2;	// 0000 0111		// 비트마스크 
							// 0000 0010	
	printf("%d\n", num);	// 2
}
*/

/*
void main()
{
	short result = 0;		// 0000 0000 

	result		= result | 1;	// 0000 0001	// 비트 켜기 
	printf("%d\n" , result);

	result		= result | 4;	// 0000 0001
								// 0000 0100	==> 0000 0101
	printf("%d\n", result);

	result		= result & ~4;	// 0000 0101	// 비트 끄기 
								// 1111 1011
	printf("%d\n", result); 	// 0000 0001
}
*/