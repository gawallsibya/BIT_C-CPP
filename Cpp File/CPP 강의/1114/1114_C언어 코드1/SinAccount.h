// SinAccount.h: interface for the SinAccount class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINACCOUNT_H__D68C9EFB_9E78_4B89_8D46_C202C97293DC__INCLUDED_)
#define AFX_SINACCOUNT_H__D68C9EFB_9E78_4B89_8D46_C202C97293DC__INCLUDED_

#include "account.h"

class SinAccount : public Account
{
public:
	SinAccount(int _id, int _b, char* _name);

	void AddMoney(int m);
};


#endif // !defined(AFX_SINACCOUNT_H__D68C9EFB_9E78_4B89_8D46_C202C97293DC__INCLUDED_)
