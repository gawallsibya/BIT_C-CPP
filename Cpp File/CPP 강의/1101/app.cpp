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
	tb.file_load();
}


void App::exit()
{
	system("cls");
	cout << "**********************************" << endl; 
	cout << "* 프로그램 종료                  *" << endl;
	cout << "**********************************" << endl;
	system("pause");
	
	tb.file_save();
}


void App::menuprint()
{
	cout << "**********************************" << endl; 
	cout << "* [1] INSERT                     *" << endl; 
	cout << "* [2] PRINTALLDATA               *" << endl;
	cout << "* [3] SEARCH                     *" << endl;
	cout << "* [4] DELETE                     *" << endl;
	cout << "* [5] UPDATE                     *" << endl;
	cout << "* [6] EXIT                       *" << endl;
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
		case '1':	tb.Insert();			break;
		case '2':   tb.PrintAllData();		break;
		case '3':   tb.Search();			break;
		case '4':   tb.Delete();			break;
		case '5':   tb.Update();			break;
		case '6':   return;
		}
		system("pause");
	}
}