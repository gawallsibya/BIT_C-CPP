//01.c

#include <stdio.h>

void foo();
void woo();

// main �Լ��� ���α׷��� ���۰� ��
void main()
{
	printf("main\n");		// �Լ��� ȣ�� 

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
