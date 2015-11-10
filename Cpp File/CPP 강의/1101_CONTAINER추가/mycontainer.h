//mycontainer.h

#ifndef _MYCONTAINER_H_
#define _MYCONTAINER_H_
#include "person.h"

#define DATA_MAX	10

class MyContainer
{
	Person* phoneList[DATA_MAX];
	int    pidx;
public:
	MyContainer() : pidx(0) {}
	bool insert( Person * data);

	// get method
	int  GetPidx() const			{ return pidx; }
	Person* GetData(int idx) const  { return phoneList[idx];}
    Person* DeleteData(int idx);
};

#endif /*_MYCONTAINER_H_*/