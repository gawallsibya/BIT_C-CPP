// GibuAccount.cpp: implementation of the GibuAccount class.
//
//////////////////////////////////////////////////////////////////////

#include "std.h"
#include "GibuAccount.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GibuAccount::GibuAccount(int _id, int _b, char* _name)
:Account(_id, _b*0.99, _name)
{
	gibu = _b*0.01;
}

void GibuAccount::AddMoney(int m)
{
	gibu += m*0.01;
	Account::AddMoney(m*0.99);
}

void GibuAccount::DataPrint()
{
	Account::DataPrint();
	cout << "±âºÎ±Ý ÃÑ¾× : " << gibu << endl;
}