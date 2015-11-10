//account.cpp
#include "std.h"
#include "account.h"

Account::Account(int _id, int _b, char* _name) : id(_id), balance(_b)
{
	strcpy(name, _name);
}
 
void Account::AddMoney(int m)
{
	balance += m;
}

bool Account::MinMoney(int m)
{
	if( balance >= m )
	{
		balance -= m;
		return true;
	}
	else
		return false;
}

void Account::DataPrint()
{
	cout << "================================" << endl;
	cout << "���� ��ȣ : " << id << endl;
	cout << "��     �� : " << name << endl;
	cout << "��     �� : " << balance << endl;
	cout << "=================================" << endl;
}