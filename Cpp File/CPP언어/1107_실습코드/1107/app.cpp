//app.cpp
#include "std.h"
#include "app.h"


void CApp::Init()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* CPP 프로그램 실습3             *" << endl; 
	cout << "* 클래스 구현 실습               *" << endl;
	cout << "* 2012.11.7                      *" << endl;
	cout << "* CCM                            *" << endl;
	cout << "**********************************" << endl;
	system("pause");
	
	m_simul.Init();

}


void CApp::Exit()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* 프로그램 종료                  *" << endl;
	cout << "**********************************" << endl;
	system("pause");
	
}


void CApp::MenuPrint()
{
	cout << "**********************************" << endl; 
	cout << "* [1] 정보 입력                  *" << endl; 
	cout << "* [2] 시뮬레이션                 *" << endl;
	cout << "* [3] 결과보기                   *" << endl;
	cout << "* [4] 프로그램 종료              *" << endl;
	cout << "**********************************" << endl;
}

void CApp::Run()
{
	while(true)
	{
		system("cls");
		MenuPrint();
		char ch;
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	m_simul.InitData();		break;
		case '2':   m_simul.RunData();		break;
		case '3':   m_simul.Result();		break;
		case '4':   return;
		}
		system("pause");
	}
}