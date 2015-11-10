//fun2.c
#include "std.h"

// 16 부호 연산자 
void fun2_1()
{
	int i = -10;
	i     = +i;		 // -10

	i     = -10;	// -10

	i     = -i;		// 10

}

// 17 논리 부정 연산자 
void fun2_2()
{
	short s = 10;
	printf("%d\n", !s);		// 0

	s = -1;
	printf("%d\n", !s);		// 0

	s = 0;
	printf("%d\n", !s);		// 1
}

//18   비트 연산자
//    10을 -10으로 변경하려면?
void fun2_3()
{
	short s = 10;
	
	short s1 =  ~s;		// -11

	short s2 =  ~s + 1;	// -10
}


//19   시프트 연산자
// int형의 앞의 상위 8bit와 뒤의 하위 8bit를 바꾸는 프로그램		 
// 단 int는 16bit로 가정
void fun2_4()
{
	int x = 10;		// x : 0000 0000 0000 1010
	char temp;

	temp = x >> 8 ;	// temp : 0000 0000 0000 0000
	x = x << 8;		// x    : 0000 1010 0000 0000

	x = x | (unsigned char)temp;// x : 0000 1010 0000 0000	

	printf("%d\n", x);		//2560
}