//app.cpp
#include "std.h"

void App::Init()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* CPP 프로그램 실습1             *" << endl; 
	cout << "* 클래스 구현 실습               *" << endl;
	cout << "* 2012.11.6                      *" << endl;
	cout << "* J W C                          *" << endl;
	cout << "**********************************" << endl;
	system("pause");
	srand(time(NULL));
}

void App::Run()
{
	while(true)
	{
		system("cls");
		menuprint();
		char ch;
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	mm.ma_reserve();		break;
		case '2':   mm.ma_check();		break;
		case '3':   mm.ma_cancel();	break;
		case '4':   mm.ma_info();	break;
		case '5':   return;
		
		}
		system("pause");
	}
}

void App::Exit()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* 프로그램 종료                  *" << endl;
	cout << "**********************************" << endl;
	system("pause");
}

void App::menuprint()
{
	cout << "**********************************" << endl; 
	cout << "* [1] 예약                       *" << endl; 
	cout << "* [2] 예약 확인                  *" << endl;
	cout << "* [3] 예약 취소                  *" << endl;
	cout << "* [4] 좌석별 예약 정보 확인      *" << endl;
	cout << "* [5] 종료                       *" << endl;
	cout << "**********************************" << endl;
}
