//bank.cpp
#include "std.h"
#include "bank.h"
#include "Account.h"
#include "GibuAccoiunt.h"
#include "SinAccoiunt.h"

Bank::Bank(int size) : con(size) {}

void Bank::PrintMenu()				// 메뉴 출력
{
	cout << "---------------- MENU  --------------\n";
	cout << "1. 계좌 개설" << endl; 
	cout << "2. 입 금"     << endl;
	cout << "3. 출 금"	   << endl;
	cout << "4. 잔액조회"  << endl;
	cout << "5. 프로그램 종료" << endl; 
	cout << "-------------------------------------\n\n";
}

void Bank::MakeAccount()				// 계좌 개설을 위한 함수
{
	int		id;
	char	name[NAME_LEN];
	int		balance;
	int		temp;

	cout << "계좌 개설 -----------------" << endl;
	cout << "계 좌 ID : ";		cin >> id;
	cin.ignore();
	cout << "이    름 : ";		cin.getline(name, 20);
	cout << "입 금 액 : ";		cin >> balance;
	cout << "입금 계좌 선택. [1]일반계좌. [2]기부계좌. [3]신용계좌."; cin >> temp;

	Account * p;
	switch(temp)
	{
	case 1 : p = new Account(id, balance, name);		break;
	case 2 : p = new GibuAccount(id, balance, name);	break;
	case 3 : p = new SinAccount(id, balance, name);		break;
	}

	if (con.push_back(p))
	{
		cout << "저장." << endl;
	}
	else
	{
		cout << "저장 오류." << endl;
	}v
}

void Bank::Deposit()					// 입 금
{
	int		money;
	int		id;

	cout << "계 좌 ID : ";		cin >> id;
	cout << "입 금 액 : ";		cin >> money;

	for( int i=0; i<con.GetIndex(); i++)
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

void Bank::fnEnter()
{
	int temp = 0;
	printf("Press Any Key\n");
	getche();
}