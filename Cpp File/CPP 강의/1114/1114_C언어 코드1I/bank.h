//bank.h
#ifndef _BANK_H_
#define _BANK_H_

#include "container.h"

class Bank
{
	Container con;
public:
	Bank(int size);

	void MakeAccount();				// ���� ������ ���� �Լ�
	void Deposit();					// �� ��
	void Withdraw();				// �� ��
	void Inquire();					// �ܾ� ��ȸ
};

#endif /*_BANK_H_*/