// GibuAccount.h: interface for the GibuAccount class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GIBUACCOUNT_H__3702A335_EC98_4910_BE9B_CF50B1BAC917__INCLUDED_)
#define AFX_GIBUACCOUNT_H__3702A335_EC98_4910_BE9B_CF50B1BAC917__INCLUDED_

#include "account.h"

class GibuAccount : public Account 
{
	int gibu;
public:
	GibuAccount(int _id, int _b, char* _name);

	void AddMoney(int m);
	void DataPrint();
};

#endif // !defined(AFX_GIBUACCOUNT_H__3702A335_EC98_4910_BE9B_CF50B1BAC917__INCLUDED_)
