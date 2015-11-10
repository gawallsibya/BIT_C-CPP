//bank.h
#ifndef _BANK_H_
#define _BANK_H_

#include "container.h"

class Bank
{
	Container con;
public:
	Bank(int size);

	void MakeAccount();				// 계좌 개설을 위한 함수
	void Deposit();					// 입 금
	void Withdraw();				// 출 금
	void Inquire();					// 잔액 조회
};

#endif /*_BANK_H_*/