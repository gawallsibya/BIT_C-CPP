//manager.h
#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "array.h"
#include "list.h"
#include "member.h"
class Manager
{
private:
	Array<Member*> array;
	List<Member*> list;
public:
	Manager();
	~Manager();

	void print();
	void order();
	void deletedata();
	void sideinfo();
};
#endif /*_MANAGER_H_*/