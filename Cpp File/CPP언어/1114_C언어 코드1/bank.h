//bank.h
#ifndef _BANK_H_
#define _BANK_H_

#include "account.h"

class Bank
{
	Account*	acc[10];
	int			index;
public:
	Bank();

	void MakeAccount();				// ���� ������ ���� �Լ�
	void Deposit();					// �� ��
	void Withdraw();				// �� ��
	void Inquire();					// �ܾ� ��ȸ
};

#endif /*_BANK_H_*/