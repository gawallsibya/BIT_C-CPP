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

void Bank::MakeAccount()				// ���� ������ ���� �Լ�
{
	int		id;
	char	name[NAME_LEN];
	int		balance;
	int		flag;
	cout << "���� ���� -----------------" << endl;
	cout << "�� �� ID : ";		cin >> id;
	cin.ignore();
	cout << "��    �� : ";		cin.getline(name, 20);
	cout << "�� �� �� : ";		cin >> balance;
	cout << "��������[1]�Ϲݰ��� [2]��ΰ��� [3]�ſ���� : "; cin >> flag;
	
	Account *p;
	switch(flag)
	{
	case 1:	p = new Account(id, balance, name);		break;
	case 2:	p = new GibuAccount(id, balance, name);	break;
	case 3: p = new SinAccount(id, balance, name);  break;
	}

	if(con.push_back(p))
	{
		cout << "����.." << endl;
	}
	else
	{
		cout << "������ ���� ����..." << endl; 
	}	
}

void Bank::Deposit()					// �� ��
{
	int		money;
	int		id;

	cout << "�� �� ID : ";		cin >> id;
	cout << "�� �� �� : ";		cin >> money;

	for( int i=0; i< con.GetIndex(); i++)
	{
		if( con.GetData(i)->GetId() == id)
		{
			con.GetData(i)->AddMoney(money);
			cout << "�Ա� �Ϸ�" << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl; 
}


void Bank::Withdraw()				// �� ��
{
	int	money;
	int	id;

	cout << "�� �� ID : ";		cin >> id;
	cout << "�� �� �� : ";		cin >> money;

	for( int i=0; i<con.GetIndex(); i++)
	{
		if( con.GetData(i)->GetId() == id)
		{
			if(con.GetData(i)->MinMoney(money))
			{
				cout << "��� �Ϸ�" << endl;
				return;
			}
			else
			{
				cout << "�ܾ� ���� "  << endl;
				return;
			}
			
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl; 
}


void Bank::Inquire()					// �ܾ� ��ȸ
{
	for( int i=0; i < con.GetIndex(); i++)
	{
		con.GetData(i)->DataPrint();
	}
}
