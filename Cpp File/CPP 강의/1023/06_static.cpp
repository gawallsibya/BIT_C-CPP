//static :  C ����

#include <iostream>
using namespace std;


void foo( )
{
	int num = 1;
	static int s_num = 1;		// ������������

	num++;
	s_num++;
	printf("%d : %d\n", num, s_num);
}

extern int g_num;

void main()
{
	g_num = 100;

	for(int i=0; i<10; i++)
	{
		foo();
	}
}