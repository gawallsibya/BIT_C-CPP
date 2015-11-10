//container.cpp
#include "std.h"
#include "container.h"

Container::Container(int size /*= 10*/)
:index(0), max(size)
{
	acc = (Account**)new int[size];
//	acc = (Account**)malloc(sizeof(int));
}

Container::~Container()
{
	delete [] acc;
}

bool Container::push_back(Account* _acc)
{
	if( 10 <=index)
		return false;
	else
	{
		acc[index++] = _acc;
		return true;
	}
}
