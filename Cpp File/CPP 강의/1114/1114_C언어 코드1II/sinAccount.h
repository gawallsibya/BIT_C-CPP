//sinAccount.h
#ifndef _SINACCOUNT_H_
#define _SINACCOUNT_H_

#include "Account.h"

class SinAccount : public Account
{
public:
	SinAccount(int _id, int _b, char* _name);
	void AddMoney(int m);
};

#endif /*_SINACCOUNT_H_*/
