// ���� / ���� 
#include <stdio.h>

int num	= 10;	// ��������(������ ������ �� �ִ� ����)
void foo();
void main()
{
	int num;	// ��������(�ش� ���ȿ����� ������ �� �ִ� ����)
	printf("%d\n", num);
//	int num;
	foo();
}

void foo()
{
	int num;
}
