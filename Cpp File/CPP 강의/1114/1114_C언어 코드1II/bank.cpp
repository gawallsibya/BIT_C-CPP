//bank.cpp
#include "std.h"
#include "bank.h"
#include "account.h"
#include "gibuaccount.h"
#include "sinaccount.h"

Bank::Bank(int size)
:con(size)
{
}

void Bank::MakeAccount()				// 계좌 개설을 위한 함수
{
	int		id;
	char	name[NAME_LEN];
	int		balance;
	int		flag;
	cout << "계좌 개설 -----------------" << endl;
	cout << "계 좌 ID : ";		cin >> id;
	cin.ignore();
	cout << "이    름 : ";		cin.getline(name, 20);
	cout << "입 금 액 : ";		cin >> balance;
	cout << "계좌종류[1]일반계좌 [2]기부계좌 [3]신용계좌 : "; cin >> flag;
	
	Account *p;
	switch(flag)
	{
	case 1:	p = new Account(id, balance, name);		break;
	case 2:	p = new GibuAccount(id, balance, name);	break;
	case 3: p = new SinAccount(id, balance, name);  break;
	}

	if(con.push_back(p))
	{
		cout << "저장.." << endl;
	}
	else
	{
		cout << "데이터 저장 오류..." << endl; 
	}	
}

void Bank::Deposit()					// 입 금
{
	int		money;
	int		id;

	cout << "계 좌 ID : ";		cin >> id;
	cout << "입 금 액 : ";		cin >> money;

	for( int i=0; i< con.GetIndex(); i++)
	{
		if( con.GetData(i)->GetId() == id)
		{
			con.GetData(i)->AddMoney(money);
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

	for( int i=0; i<con.GetIndex(); i++)
	{
		if( con.GetData(i)->GetId() == id)
		{
			if(con.GetData(i)->MinMoney(money))
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
	for( int i=0; i < con.GetIndex(); i++)
	{
		con.GetData(i)->DataPrint();
	}
}
