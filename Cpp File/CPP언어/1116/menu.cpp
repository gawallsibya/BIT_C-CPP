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
	cout << "메뉴 이름 : " << m_name << endl;
	cout << "메뉴 가격 : " << m_price << endl;
	cout << "판매 수량 : " << m_count << endl; 
}

