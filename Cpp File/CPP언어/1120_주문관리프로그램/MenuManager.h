//menumanager.h
#ifndef _MENUMANAGER_H_
#define _MENUMANAGER_H_

#include "menu.h"
#include "container.h"

class MenuManager
{
	Container<Menu*> con;

public:
	int NameToIdx(char *name);

public:
	MenuManager(int size);

	void run();
	void menu_Print();
	void menu_Insert();
    void menu_Printall();
    void menu_Search();			// �޴��� �̸�
    void menu_Modify();			// �޴��� �̸�
    void menu_Delete();			// �޴��� �̸�  ==> (���� ��ġ �̵� ���� �ʱ�)};

	void Order(int menuidx, int count);

	void menu_Save();
	void menu_Load();
};

#endif /*_MENUMANAGER_H_*/