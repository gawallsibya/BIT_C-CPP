//container.h

#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include "menu.h"

class Container
{
	Menu**   m_data;
	int		 m_max;
	int		 m_size;

public:
	Container(int size = 10);
	~Container();

    int  GetSize() const	{ return m_size;		}
    int  GetMax()  const	{ return m_max;			}
    Menu*GetData(int idx)	{ return m_data[idx];	}

	bool push_back(Menu* acc);
	void insert(int idx, Menu* menu);
    Menu* erase(int idx);
};


#endif/*_CONTAINER_H_*/