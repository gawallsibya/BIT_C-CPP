//menumanager.cpp
#include "std.h"
#include "menumanager.h"
#include "menu.h"

MenuManager::MenuManager(int size)
:con(size)
{
}


void MenuManager::menu_Print()
{
	cout << "****************************" << endl;
	cout << "[1] 메뉴 추가              *" << endl;
	cout << "[2] 메뉴 출력              *" << endl;
	cout << "[3] 메뉴 검색              *" << endl;
	cout << "[4] 메뉴 수정              *" << endl;
	cout << "[5] 메뉴 삭제              *" << endl;
	cout << "[6] 되돌아가기             *" << endl;
	cout << "****************************" << endl;
}


void MenuManager::run()
{
	while(true)
	{
		system("cls");
		menu_Print();
		char ch;
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	menu_Insert();		break;
		case '2':   menu_Printall();	break;
		case '3':   menu_Search();		break;
		case '4':   menu_Modify();		break;
		case '5':   menu_Delete();		break;
		case '6':   return;
		}
		system("pause");
	}
}

void MenuManager::menu_Insert()
{
	cout << "[ 메뉴 입력 ]" << endl;

	char name[20];
	int  price;
	cin.ignore();
	cout << "메뉴명 : ";  cin.getline(name, 20);
	cout << "가  격 : ";  cin >> price;
	Menu *p = new Menu(name, price);
	if(con.push_back(p) == true)
	{
		cout << "저장 되었습니다." << endl;
	}
	else
	{
		cout << "저장 에러 발생.." << endl;
	}
}

void MenuManager::menu_Printall()
{
	cout << "[ 메뉴판 ]" << endl;
	cout << "======================" <<endl;
	for(int i=0; i<con.GetMax(); i++)
	{
		Menu *p = (Menu*)con.GetData(i);
		if( p != NULL)
			cout << "[ " << i << "] " << p->GetName() <<"\t" << p->GetPrice() << "\t" <<
			p->GetCount() << endl;
	}
	cout << "======================" <<endl;
}


int MenuManager::NameToIdx(char *name)
{
	cout << "======================" <<endl;
	for(int i=0; i<con.GetMax(); i++)
	{
		Menu *p = (Menu*)con.GetData(i);
		if(p !=NULL &&  strcmp(p->GetName(), name) == 0)
			return i;
	}
	return -1;
}


void MenuManager::menu_Search()			// 메뉴의 이름
{
	cout << "[ 메뉴 검색 ]" << endl;

	char name[20];
	cin.ignore();
	cout << "메뉴명 : ";  cin.getline(name, 20);

	int idx = NameToIdx(name);
	if( idx != -1)
	{
		((Menu*)con.GetData(idx))->DataPrint();

	}
	else
	{
		cout << "해당 메뉴가 존재하지 않습니다.." << endl; 
	}
}


void MenuManager::menu_Modify()			// 메뉴의 이름
{
	cout << "[ 메뉴 수정 ]" << endl;

	char name[20];
	cin.ignore();

	cout << "메뉴명 : ";  cin.getline(name, 20);

	int idx = NameToIdx(name);
	if( idx != -1)
	{
		Menu *p = (Menu*)con.GetData(idx);
		char name[20];
		int  price;
		cout << "메뉴명 : ";	cin.getline(name, 20);
		cout << "가  격 : ";    cin >> price;
		p->SetName(name);
		p->SetPrice(price);
		cout << "변경 되었습니다..." << endl; 
	}
	else
	{
		cout << "해당 메뉴가 존재하지 않습니다.." << endl; 
	}
}

void MenuManager::menu_Delete()			// 메뉴의 이름  ==> (현재 위치 이동 하지 않기)};
{
	cout << "[ 메뉴 삭제 ]" << endl;

	char name[20];
	cin.ignore();
	cout << "메뉴명 : ";  cin.getline(name, 20);

	int idx = NameToIdx(name);
	if( idx != -1)
	{
		Menu *p = (Menu*)con.erase(idx);
		delete p;

		cout << "삭제 되었습니다..." << endl; 
	}
	else
	{
		cout << "해당 메뉴가 존재하지 않습니다.." << endl; 
	}
}

void MenuManager::Order(int menuidx, int count)
{
	Menu *p = (Menu*)con.GetData(menuidx);	
	p->AddCount(count);
}

void MenuManager::menu_Save()
{
	FILE *fp = fopen("menu.ccm", "wb");
	if( fp == NULL)
		return;
	int size = con.GetSize();
	int max	 = con.GetMax();
	fwrite(&size, sizeof(int), 1, fp);
	for(int i=0; i<max; i++)
	{
		Menu *p = (Menu*)con.GetData(i);
		if(p != NULL)
		{
			fwrite(&i, sizeof(int), 1, fp);
			fwrite(p, sizeof(Menu), 1, fp);
		}
	}
	fclose(fp);
}

void MenuManager::menu_Load()
{
	FILE *fp = fopen("menu.ccm", "rb");
	if( fp == NULL)
		return;
	int max;
	fread(&max, sizeof(int), 1, fp);
	// 버그 있는 코드 ??======================

	for(int i=0; i<max; i++)
	{
		Menu *p = new Menu();
		int idx;
		fread(&idx, sizeof(int), 1, fp);
		fread(p, sizeof(Menu), 1, fp);
		
		con.insert(idx, p); 
	}
	fclose(fp);
}
