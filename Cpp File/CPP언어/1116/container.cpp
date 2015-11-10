//container.cpp
#include "std.h"
#include "container.h"

Container::Container(int size /*= 10*/)
:m_size(0), m_max(size)
{
	m_data = (Menu**)new int[size];
	
	memset(m_data, 0, sizeof(int)*size);
}

Container::~Container()
{
	delete [] m_data;
}

bool Container::push_back(Menu* _data)
{
	if( m_max <= m_size)
		return false;
	else
	{
		for(int i=0; i< m_max; i++)
		{
			if( m_data[i] == NULL)
			{
				m_data[i] = _data;
				++m_size;
				return true;
			}
		}
	}
	return true;
}

void Container::insert(int idx, Menu* menu)
{
	m_data[idx] = menu;
	++m_size;
}

Menu* Container::erase(int idx)
{
	Menu * p = m_data[idx];

	m_data[idx] = NULL;
	--m_size;
	return p;
}
