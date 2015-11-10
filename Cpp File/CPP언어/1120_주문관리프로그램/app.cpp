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

void App::Menu()
{
	cout << "**********************************" << endl; 
	cout << "* [1] Menu                       *" << endl;
	cout << "* [2] Order                      *" << endl;
	cout << "* [3] Exit                       *" << endl;
	cout << "**********************************" << endl;
}


void App::run()
{
	m_order.GetMenuManager(&m_manager);
	while(true)
	{
		system("cls");
		Menu();
		char ch;
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	m_manager.run();		break;
		case '2':	m_order.run();		    break;
		case '3':	return;
		}
		system("pause");
	}
}