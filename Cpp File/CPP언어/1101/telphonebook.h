//telphonebook.h

#ifndef _TELPHONEBOOK_H_
#define _TELPHONEBOOK_H_
#include "person.h"

#define DATA_MAX	10

class TelPhoneBook
{
	Person phoneList[DATA_MAX];
	int    pidx;

public:
	TelPhoneBook()  : pidx(0) {}
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