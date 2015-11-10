//container.h

#ifndef _CONTAINER_H_
#define _CONTAINER_H_

template <typename T>	// void** ==> T   void* ==> T
class Container
{
	T*   m_data;
	int		 m_max;
	int		 m_size;

public:
	Container(int size = 10);
	~Container();

    int  GetSize() const	{ return m_size;		}
    int  GetMax()  const	{ return m_max;			}
    T GetData(int idx)	{ return m_data[idx];	}

	bool push_back(T acc);
	void insert(int idx, T menu);
    T erase(int idx);
};


template<typename T>
Container<T>::Container(int size /*= 10*/)
:m_size(0), m_max(size)
{
	m_data = (T*)new int[size];
	
	memset(m_data, 0, sizeof(int)*size);
}

template<typename T>
Container<T>::~Container()
{
	delete [] m_data;
}

template<typename T>
bool Container<T>::push_back(T _data)
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

template<typename T>
void Container<T>::insert(int idx, T menu)
{
	m_data[idx] = menu;
	++m_size;
}

template<typename T>
T Container<T>::erase(int idx)
{
	T p = m_data[idx];

	m_data[idx] = NULL;
	--m_size;
	return p;
}

#endif/*_CONTAINER_H_*/