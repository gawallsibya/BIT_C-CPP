//app.c
#include "std.h"

void app_init()
{
	system("cls");
	printf( "**********************************\n" ); 
	printf( "* C ���α׷� �ǽ�                *\n" ); 
	printf( "* �迭�� ����Ʈ �̿�             *\n" );
	printf( "* 2012.12.14                     *\n" );
	printf( "* C C M                          *\n" );
	printf( "**********************************\n" );
	system("pause");
	ma_init();
}

void app_run()
{
	char ch;
	while(1)
	{
		system("cls");
		menuprint();
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':ma_reserve();			break;
		case '2':ma_check();			break;
		case '3':ma_cancel();			break;
		case '4':ma_info();				break;
		case '5':		return;
		}
		system("pause");
	}
}


void app_exit()
{
	system("cls");
	printf( "**********************************\n" ); 
	printf( "* ���α׷� ����                  *\n" );
	printf( "**********************************\n" );
	system("pause");
}


void menuprint()
{
	printf( "**********************************\n" ); 
	printf( "* [1] ����                       *\n" ); 
	printf( "* [2] ���� Ȯ��                  *\n" ); 
	printf( "* [3] ���� ���                  *\n" ); 
	printf( "* [4] �¼��� ���� ���� Ȯ��      *\n" ); 
	printf( "* [5] ���α׷� ����              *\n" );
	printf( "**********************************\n" );
}