//app.cpp
#include "std.h"
#include "app.h"


void App::init()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* CPP 프로그램 실습1             *" << endl; 
	cout << "* 클래스 구현 실습               *" << endl;
	cout << "* 2012.11.1                      *" << endl;
	cout << "* CCM                            *" << endl;
	cout << "**********************************" << endl;
	system("pause");

	m_cal.init();
//	tb.file_load();
}


void App::exit()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* 프로그램 종료                  *" << endl;
	cout << "**********************************" << endl;
	system("pause");
	
//	tb.file_save();
}


void App::menuprint()
{
	cout << "**********************************" << endl; 
	cout << "* [1] 문제 생성                  *" << endl; 
	cout << "* [2] 문제 풀이                  *" << endl;
	cout << "* [3] 결과 보기                  *" << endl;
	cout << "* [4] EXIT                       *" << endl;
	cout << "**********************************" << endl;
}

void App::run()
{
	while(true)
	{
		system("cls");
		menuprint();
		char ch;
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	m_cal.ExamInit();		break;
		case '2':   m_cal.RunExam();		break;
//		case '3':   tb.Search();			break;
		case '4':   return;
		}
		system("pause");
	}
}