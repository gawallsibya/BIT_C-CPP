//menumanager.h
#ifndef _MENUMANAGER_H_
#define _MENUMANAGER_H_

#include "container.h"

class MenuManager
{
	Container con;

private:
	int NameToIdx(char *name);

public:
	MenuManager(int size);

	void menu_Print();
	void menu_Insert();
    void menu_Printall();
    void menu_Search();			// 메뉴의 이름
    void menu_Modify();			// 메뉴의 이름
    void menu_Delete();			// 메뉴의 이름  ==> (현재 위치 이동 하지 않기)};

	void menu_Save();
	void menu_Load();
};

#endif /*_MENUMANAGER_H_*/