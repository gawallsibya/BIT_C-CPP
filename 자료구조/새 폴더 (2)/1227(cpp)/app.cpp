//app.cpp
#include "std.h"

void App::Init()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* CPP ���α׷� �ǽ�1             *" << endl; 
	cout << "* Ŭ���� ���� �ǽ�               *" << endl;
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
	cout << "* ���α׷� ����                  *" << endl;
	cout << "**********************************" << endl;
	system("pause");
}

void App::menuprint()
{
	cout << "**********************************" << endl; 
	cout << "* [1] ����                       *" << endl; 
	cout << "* [2] ���� Ȯ��                  *" << endl;
	cout << "* [3] ���� ���                  *" << endl;
	cout << "* [4] �¼��� ���� ���� Ȯ��      *" << endl;
	cout << "* [5] ����                       *" << endl;
	cout << "**********************************" << endl;
}
