//app.cpp

#include "std.h"

void App::Menu()
{
	cout << "[�޴�]" << endl;
	cout << "[1] INSERT" << endl; 
	cout << "[2] PRINTALL" << endl; 
	cout << "[3] SEARCH" << endl; 
	cout << "[9] EXIT" << endl; 
}

void App::Init()
{
	// �ʱ�ȭ
}
void App::Run()
{
	int idx;
	while(1)
	{
		system("cls");
		Menu();
		cin >> idx;
		switch(idx)
		{
		case 1: ma.Insert(); break;
		case 2: ma.PrintAll(); break;
		case 3: ma.Search(); break;
		case 9: return;
		}
		system("pause");
		
	}
}
void App::Exit()
{
	//����ó��
}