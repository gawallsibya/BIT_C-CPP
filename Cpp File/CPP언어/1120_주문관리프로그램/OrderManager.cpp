//OrderManager.cpp
#include "std.h"
#include "ordermanager.h"
#include "orderelem.h"
#include "order.h"

void OrderManager::order_Print()
{
	cout << "****************************" << endl;
	cout << "[1] �ֹ��ϱ�               *" << endl;
	cout << "[2] �ǵ��ư���             *" << endl;
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
	cout << "[�� ��]" << endl;

	//1. �޴��� ��� 
	pManager->menu_Printall();

	//2. �޴� ���� 
	int count;
	int num,size;
	cout << "ǰ�� ���� : ";		cin >> count;
	Order *pOrder = new Order(count);
	for(int i=0; i<count; i++)
	{
		cout << "  �޴���ȣ : ";   cin >> num;
		cout << "  ��  ��   : ";   cin >> size;

		pManager->Order(num, size);

		// OrderElem��ü ����
		OrderElem *p = new OrderElem( num, size);
		pOrder->insert(p);
	}
	con.push_back(pOrder);
}