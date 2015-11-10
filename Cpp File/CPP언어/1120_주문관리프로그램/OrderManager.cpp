//OrderManager.cpp
#include "std.h"
#include "ordermanager.h"
#include "orderelem.h"
#include "order.h"

void OrderManager::order_Print()
{
	cout << "****************************" << endl;
	cout << "[1] 주문하기               *" << endl;
	cout << "[2] 되돌아가기             *" << endl;
	cout << "****************************" << endl;
}

void OrderManager::run()
{
	while(true)
	{
		system("cls");
		order_Print();
		char ch;
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	order_insert();		break;
		case '2':	return;
		}
		system("pause");
	}
}


void OrderManager::order_insert()
{
	cout << "[주 문]" << endl;

	//1. 메뉴판 출력 
	pManager->menu_Printall();

	//2. 메뉴 선택 
	int count;
	int num,size;
	cout << "품목 수량 : ";		cin >> count;
	Order *pOrder = new Order(count);
	for(int i=0; i<count; i++)
	{
		cout << "  메뉴번호 : ";   cin >> num;
		cout << "  수  량   : ";   cin >> size;

		pManager->Order(num, size);

		// OrderElem객체 생성
		OrderElem *p = new OrderElem( num, size);
		pOrder->insert(p);
	}
	con.push_back(pOrder);
}