//fun2.c
#include "std.h"

// 16 ��ȣ ������ 
void fun2_1()
{
	int i = -10;
	i     = +i;		 // -10

	i     = -10;	// -10

	i     = -i;		// 10

}

// 17 �� ���� ������ 
void fun2_2()
{
	short s = 10;
	printf("%d\n", !s);		// 0

	s = -1;
	printf("%d\n", !s);		// 0

	s = 0;
	printf("%d\n", !s);		// 1
}

//18   ��Ʈ ������
//    10�� -10���� �����Ϸ���?
void fun2_3()
{
	short s = 10;
	
	short s1 =  ~s;		// -11

	short s2 =  ~s + 1;	// -10
}


//19   ����Ʈ ������
// int���� ���� ���� 8bit�� ���� ���� 8bit�� �ٲٴ� ���α׷�		 
// �� int�� 16bit�� ����
void fun2_4()
{
	int x = 10;		// x : 0000 0000 0000 1010
	char temp;

	temp = x >> 8 ;	// temp : 0000 0000 0000 0000
	x = x << 8;		// x    : 0000 1010 0000 0000

	x = x | (unsigned char)temp;// x : 0000 1010 0000 0000	

	printf("%d\n", x);		//2560
}