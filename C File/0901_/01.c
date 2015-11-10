//01.c

#include <stdio.h>

void foo();
void woo();

// main 함수는 프로그램의 시작과 끝
void main()
{
	printf("main\n");		// 함수의 호출 

	foo();
	woo();
}

void foo()
{
	return;
	printf("foo\n");
//	foo();
}

void woo()
{
	printf("WOO\n");
}
