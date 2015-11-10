//order.h

#ifndef _ORDER_H_
#define _ORDER_H_
#include "container.h"
#include "orderelem.h"

// 주문에 대한 정보를 저장
class Order
{
	Container<OrderElem*> *pcon;

	Order(const Order &)				{}
	Order operator=(const Order &)		{ return *this; }
public:
	Order(int count)		{ pcon = new Container<OrderElem*>(count); }
	~Order()				{ delete pcon;				   }

	bool insert( OrderElem* p)		{ return pcon->push_back(p);  }


};

#endif /*_ORDER_H_*/
