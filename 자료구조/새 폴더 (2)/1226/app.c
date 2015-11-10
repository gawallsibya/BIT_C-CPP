//app.c
#include "std.h"

void app_init()
{
	system("cls");
	printf( "**********************************\n" ); 
	printf( "* C 프로그램 실습                *\n" ); 
	printf( "* 배열과 리스트 이용             *\n" );
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
	printf( "* 프로그램 종료                  *\n" );
	printf( "**********************************\n" );
	system("pause");
}


void menuprint()
{
	printf( "**********************************\n" ); 
	printf( "* [1] 예약                       *\n" ); 
	printf( "* [2] 예약 확인                  *\n" ); 
	printf( "* [3] 예약 취소                  *\n" ); 
	printf( "* [4] 좌석별 예약 정보 확인      *\n" ); 
	printf( "* [5] 프로그램 종료              *\n" );
	printf( "**********************************\n" );
}