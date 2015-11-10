// 전역 / 지역 
#include <stdio.h>

int num	= 10;	// 전역변수(누구라도 접근할 수 있는 변수)
void foo();
void main()
{
	int num;	// 지역변수(해당 블럭안에서만 접근할 수 있는 변수)
	printf("%d\n", num);
//	int num;
	foo();
}

void foo()
{
	int num;
}
