//fun.c
#include "std.h"

//1. int�� ���� x�� 10���� ũ�� 20���� ���� �� 
//   true�� ���ǽ�
void fun_1()
{
	int x = 15;
	if( x > 10 && x < 20)
		printf("true\n");
}

// 2. char�� ���� ch�� �����̳� ���� �ƴ� �� true�� ���ǽ�
void fun_2()
{
	char ch = '9';
	if( ch != ' ' || ch != '\t')
		printf("true\n");
}

// 3. char�� ���� ch�� ��x' �Ǵ� ��X'�� �� true�� ���ǽ�
void fun_3()
{
	char ch = 'X';
	if( ch == 'x' || ch == 'X')
		printf("true\n");
}

// 4. char�� ���� ch�� ����(��0��~��9��)�� �� true�� ���ǽ�
void fun_4()
{
	char ch = '5';
	if( ch >= '0' && ch <= '9')
		printf("true\n");
}

// 5. char�� ���� ch�� ������(�빮�� �Ǵ� �ҹ���)�� �� 
//    true�� ���ǽ�
void fun_5()
{
	char ch = 't';
	if( (ch >= 'A' && ch <= 'Z') || (ch>='a' && ch<='z'))
		printf("true\n");
}

//6. int�� ���� year�� 400���� �����������ų� 
//   �Ǵ� 4�� ������������ 100����
//	������������ ���� �� true�� ���ǽ�
void fun_6()
{
	int year = 8;

	if( year % 400 == 0 || year % 4 == 0 )
	{
		if( year % 100 != 0)
			printf("true\n");
	}
}

  


  
 
