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
	cout<< "[1]예약 출력                     *"	  <<endl;
	cout<< "[2]예약 확인                     *"	  <<endl;
	cout<< "[3]예약 취소                     *"	  <<endl;
	cout<< "[4]좌석별 예약 정보 확인         *"	  <<endl;
	cout<< "[5]종료                          *"	  <<endl;
	cout<< "**********************************"   <<endl;
}

void App::Init()
{
	system("cls");
	cout<< "**********************************"<<endl; 
	cout<< "* 좌석 예약 CPP                  *"<<endl;
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
	cout<< "* 프로그램 종료                 *"<<endl;
	cout<< "*********************************"<<endl;
	system("pause");
}