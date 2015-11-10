//menu.cpp
#include "std.h"
#include "menu.h"

Menu::Menu(char* name, int price)
:m_price(price), m_count(0)
{
	strcpy(m_name, name);
}

void Menu::DataPrint() const
{
	cout << "�޴� �̸� : " << m_name << endl;
	cout << "�޴� ���� : " << m_price << endl;
	cout << "�Ǹ� ���� : " << m_count << endl; 
}

