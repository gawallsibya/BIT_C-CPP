//app.cpp
#include "std.h"
#include "app.h"


void CApp::Init()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* CPP ���α׷� �ǽ�3             *" << endl; 
	cout << "* Ŭ���� ���� �ǽ�               *" << endl;
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
	cout << "* ���α׷� ����                  *" << endl;
	cout << "**********************************" << endl;
	system("pause");
	
}


void CApp::MenuPrint()
{
	cout << "**********************************" << endl; 
	cout << "* [1] ���� �Է�                  *" << endl; 
	cout << "* [2] �ùķ��̼�                 *" << endl;
	cout << "* [3] �������                   *" << endl;
	cout << "* [4] ���α׷� ����              *" << endl;
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