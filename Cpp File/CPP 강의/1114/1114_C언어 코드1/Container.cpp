// Container.cpp: implementation of the CContainer class.
//
//////////////////////////////////////////////////////////////////////

#include "Container.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Container::Container(int size) : index(0), max(size)
{
	acc = (Account**)new int[size];
}

Container::~Container()
{
	delete [] acc;
}

bool Container::push_back(Account * _acc)
{
	if ( 10 <= index )
		return false;
	else
	{
		acc[index++] = _acc;
		return true;
	}
}
