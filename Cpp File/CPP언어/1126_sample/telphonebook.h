//telphonebook.h

#ifndef _TELPHONEBOOK_H_
#define _TELPHONEBOOK_H_
#include "mycontainer.h"


class TelPhoneBook
{
	MyContainer con;

public:
	void Insert();
	void PrintAllData() const;
	void Search();
	void Delete();
	void Update();

	void file_save();
	void file_load();

private:
	int NameToIdx(const char* name);
};

#endif /*_TELPHONEBOOK_H_*/