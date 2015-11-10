//OrderManager.h

#ifndef _ORDERMANAGER_H_
#define _ORDERMANAGER_H_

#include "container.h"
#include "menumanager.h"
#include "order.h"

class OrderManager
{
	Container<Order*> con;
	MenuManager *pManager;
public:
	void run();
	void order_Print();

	void GetMenuManager(MenuManager* p) {pManager = p;}

	void order_insert();

};

#endif /*_ORDERMANAGER_H_*/