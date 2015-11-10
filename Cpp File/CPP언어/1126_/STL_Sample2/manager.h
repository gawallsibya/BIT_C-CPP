//manager.h

#ifndef _MANAGER_H_
#define _MANAGER_H_


class Manager
{
	vector<Data*> vec;

	void* DataSearch(const char*name, bool b =true);
public:
	void Insert();
	void PrintAll();
	void Search();
	void Modify();
	void Delete();
};

#endif /*_MANAGER_H_*/