//app.c
#include "std.h"

void app_init()
{
	system("cls");
	printf( "**********************************\n" ); 
	printf( "* C 프로그램 실습                *\n" ); 
	printf( "* 배열과 큐 이용                 *\n" );
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
	printf( "* 프로그램 종료                  *\n" );
	printf( "**********************************\n" );
	system("pause");
}


void menuprint()
{
	printf( "**********************************\n" ); 
	printf( "* [1] 계좌 개설                  *\n" ); 
	printf( "* [2] 입 금                      *\n" ); 
	printf( "* [3] 출 금                      *\n" ); 
	printf( "* [4] 잔액조회                   *\n" ); 
	printf( "* [5] 입출금 내역 조회           *\n" ); 
	printf( "* [6] 프로그램 종료              *\n" );
	printf( "**********************************\n" );
}
