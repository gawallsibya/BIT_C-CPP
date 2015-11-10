//gibuAccount.h
#ifndef _GIBUACCOUNT_H_
#define _GIBUACCOUNT_H_

#include "Account.h"

class GibuAccount : public Account
{
	int gibu;
public:
	GibuAccount(int _id, int _b, char* _name);
	void AddMoney(int m);
	void DataPrint();
};

#endif /*_GIBUACCOUNT_H_*/
