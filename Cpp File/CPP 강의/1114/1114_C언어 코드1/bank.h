//bank.h
#ifndef _BANK_H_
#define _BANK_H_

#include "Container.h"

class Bank
{
	Container con;
public:
	Bank(int size);

	void PrintMenu();				// �޴� ���
	void MakeAccount();				// ���� ������ ���� �Լ�
	void Deposit();					// �� ��
	void Withdraw();				// �� ��
	void Inquire();					// �ܾ� ��ȸ
	void fnEnter();
};

#endif /*_BANK_H_*/