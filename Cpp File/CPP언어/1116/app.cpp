//app.cpp
#include "std.h"
#include "app.h"


void App::init()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* CPP 프로그램 실습              *" << endl; 
	cout << "* 주문 관리 프로그램             *" << endl;
	cout << "* 2012.11.16                     *" << endl;
	cout << "* CCM                            *" << endl;
	cout << "**********************************" << endl;
	system("pause");
	m_manager.menu_Load();
}


void App::exit()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* 프로그램 종료                  *" << endl;
	cout << "**********************************" << endl;
	system("pause");
	
	m_manager.menu_Save();
}


void App::run()
{
	while(true)
	{
		system("cls");
		m_manager.menu_Print();
		char ch;
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	m_manager.menu_Insert();		break;
		case '2':   m_manager.menu_Printall();		break;
		case '3':   m_manager.menu_Search();		break;
		case '4':   m_manager.menu_Modify();		break;
		case '5':   m_manager.menu_Delete();		break;
		case '6':   return;
		}
		system("pause");
	}
}