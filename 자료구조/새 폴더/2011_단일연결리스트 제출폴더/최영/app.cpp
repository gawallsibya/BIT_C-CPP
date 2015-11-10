#include "app.h"
#include "std.h"
#include "manager.h"
extern Manager mm;
void Init()
{
	system("cls");
	printf( "**********************************\n" ); 
	printf( "* CPP 프로그램 실습1             *\n" ); 
	printf( "* 클래스 구현 실습               *\n" );
	printf( "* 2012.11.6                      *\n" );
	printf( "* C Y                            *\n" );
	printf( "**********************************\n" );
	system("pause");
	List_init(&mm.li);
}

void Run()
{
	while(true)
	{
		system("cls");
		menuprint();
		char ch;
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	Manager_Insert();		break;
		case '2':   Manager_Printall();		break;
		case '3':   Manager_Search();	break;
		case '4':   Manager_Update();	break;
		case '5':   Manager_Delete();	break;
		case '6':   return;
		}
		system("pause");
	}
}

void Exit()
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
	printf( "* [1] 입력                       *\n" ); 
	printf( "* [2] 출력                       *\n" );
	printf( "* [3] 검색                       *\n" );
	printf( "* [4] 수정                       *\n" );
	printf( "* [5] 삭제                       *\n" );
	printf( "* [6] 종료                       *\n" );
	printf( "**********************************\n" );
}
