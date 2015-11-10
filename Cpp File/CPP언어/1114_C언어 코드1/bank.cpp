//bank.cpp
#include "std.h"
#include "bank.h"

Bank::Bank() : index(0)
{
}

void Bank::MakeAccount()				// 계좌 개설을 위한 함수
{
	int		id;
	char	name[NAME_LEN];
	int		balance;

	cout << "계좌 개설 -----------------" << endl;
	cout << "계 좌 ID : ";		cin >> id;
	cin.ignore();
	cout << "이    름 : ";		cin.getline(name, 20);
	cout << "입 금 액 : ";		cin >> balance;

	acc[index]	= new Account(id, balance, name);

	index++;
}

void Bank::Deposit()					// 입 금
{
	int		money;
	int		id;

	cout << "계 좌 ID : ";		cin >> id;
	cout << "입 금 액 : ";		cin >> money;

	for( int i=0; i<index; i++)
	{
		if( acc[i]->GetId() == id)
		{
			acc[i]->AddMoney(money);
			cout << "입금 완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl; 
}


void Bank::Withdraw()				// 출 금
{
	int	money;
	int	id;

	cout << "계 좌 ID : ";		cin >> id;
	cout << "출 금 액 : ";		cin >> money;

	for( int i=0; i<index; i++)
	{
		if( acc[i]->GetId() == id)
		{
			if(acc[i]->MinMoney(money))
			{
				cout << "출금 완료" << endl;
				return;
			}
			else
			{
				cout << "잔액 부족 "  << endl;
				return;
			}
			
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl; 
}


void Bank::Inquire()					// 잔액 조회
{
	for( int i=0; i < index; i++)
	{
		acc[i]->DataPrint();
	}
}
