//fun.c
#include "std.h"

//1. int형 변수 x가 10보다 크고 20보다 작을 때 
//   true인 조건식
void fun_1()
{
	int x = 15;
	if( x > 10 && x < 20)
		printf("true\n");
}

// 2. char형 변수 ch가 공백이나 탭이 아닐 때 true인 조건식
void fun_2()
{
	char ch = '9';
	if( ch != ' ' || ch != '\t')
		printf("true\n");
}

// 3. char형 변수 ch가 ‘x' 또는 ’X'일 때 true인 조건식
void fun_3()
{
	char ch = 'X';
	if( ch == 'x' || ch == 'X')
		printf("true\n");
}

// 4. char형 변수 ch가 숫자(‘0’~‘9’)일 때 true인 조건식
void fun_4()
{
	char ch = '5';
	if( ch >= '0' && ch <= '9')
		printf("true\n");
}

// 5. char형 변수 ch가 영문자(대문자 또는 소문자)일 때 
//    true인 조건식
void fun_5()
{
	char ch = 't';
	if( (ch >= 'A' && ch <= 'Z') || (ch>='a' && ch<='z'))
		printf("true\n");
}

//6. int형 변수 year가 400으로 나눠떨어지거나 
//   또는 4로 나눠떨어지고 100으로
//	나눠떨어지지 않을 때 true인 조건식
void fun_6()
{
	int year = 8;

	if( year % 400 == 0 || year % 4 == 0 )
	{
		if( year % 100 != 0)
			printf("true\n");
	}
}

  


  
 
