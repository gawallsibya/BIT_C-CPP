//sinAccount.cpp
#include "std.h"
#include "sinAccount.h"

SinAccount::SinAccount(int _id, int _b, char* _name)
:Account(_id, _b*1.1, _name)
{
}

void SinAccount::AddMoney(int m)
{
	Account::AddMoney(m*1.1);
}


