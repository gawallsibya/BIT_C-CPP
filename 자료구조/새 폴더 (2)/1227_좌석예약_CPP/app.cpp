//app.cpp
#include "std.h"
#include "app.h"
App::App()
{

}

App::~App()
{

}

void App::menu()
{
	cout<< "**********************************"	  <<endl;
	cout<< "[1]���� ���                     *"	  <<endl;
	cout<< "[2]���� Ȯ��                     *"	  <<endl;
	cout<< "[3]���� ���                     *"	  <<endl;
	cout<< "[4]�¼��� ���� ���� Ȯ��         *"	  <<endl;
	cout<< "[5]����                          *"	  <<endl;
	cout<< "**********************************"   <<endl;
}

void App::Init()
{
	system("cls");
	cout<< "**********************************"<<endl; 
	cout<< "* �¼� ���� CPP                  *"<<endl;
	cout<< "**********************************"<<endl;
	system("pause");
}

void App::Run()
{
	char ch;
	while(1)
	{
		system("cls");
		menu();
		cin>>ch;		
		switch(ch)
		{
		case '1':manager.print();			break;
		case '2':manager.order();			break;
		case '3':manager.deletedata();		break;
		case '4':manager.sideinfo();		break;
		default :			return;
		}
		system("pause");
	}
}

void App::Exit()
{
	system("cls");
	cout<< "*********************************"<<endl; 
	cout<< "* ���α׷� ����                 *"<<endl;
	cout<< "*********************************"<<endl;
	system("pause");
}