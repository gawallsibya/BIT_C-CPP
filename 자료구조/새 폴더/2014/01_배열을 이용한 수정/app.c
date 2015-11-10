//app.c
#include "std.h"

void app_init()
{
	system("cls");
	printf( "**********************************\n" ); 
	printf( "* C ���α׷� �ǽ�                *\n" ); 
	printf( "* �迭�� ť �̿�                 *\n" );
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
		case MAKE:		ma_makeaccount();		break;
		case DEPOSIT:	ma_deposit();			break;
		case WITHDRAW:	ma_withdraw();			break;
		case INQUIRE:	ma_inquire();			break;
		case INFOR:		ma_information();		break;
		case EXIT:		return;
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
	printf( "* [1] ���� ����                  *\n" ); 
	printf( "* [2] �� ��                      *\n" ); 
	printf( "* [3] �� ��                      *\n" ); 
	printf( "* [4] �ܾ���ȸ                   *\n" ); 
	printf( "* [5] ����� ���� ��ȸ           *\n" ); 
	printf( "* [6] ���α׷� ����              *\n" );
	printf( "**********************************\n" );
}
