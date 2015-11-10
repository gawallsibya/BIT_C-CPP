//mycontainer.cpp
#include "std.h"
#include "mycontainer.h"

bool MyContainer::insert( Person * data)
{
	if( pidx >= DATA_MAX)
		return false;
	
	phoneList[pidx] = data;
	pidx++;
	return true;
}

Person* MyContainer::DeleteData(int idx)
{
	Person *p = phoneList[idx];
	for(int i= idx; i<pidx; i++)
	{
		phoneList[i] = phoneList[i+1];
	}
	pidx--;	
	return p;
}