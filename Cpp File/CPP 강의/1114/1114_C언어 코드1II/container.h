//container.h

#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include "account.h"

class Container
{
//	Account*	acc[10];
	Account**   acc;
	int			index;
	int			max;
public:
	Container(int size = 10);
	~Container();

	bool push_back(Account* acc);

	int GetIndex() const		{ return index;		}
	Account* GetData(int idx)   { return acc[idx];	}

};


#endif/*_CONTAINER_H_*/