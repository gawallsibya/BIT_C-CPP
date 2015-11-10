//bank.cpp
#include "std.h"
#include "bank.h"

Bank::Bank(int size)
:con(size)
{
}

void Bank::MakeAccount()				// ���� ������ ���� �Լ�
{
	int		id;
	char	name[NAME_LEN];
	int		balance;

	cout << "���� ���� -----------------" << endl;
	cout << "�� �� ID : ";		cin >> id;
	cin.ignore();
	cout << "��    �� : ";		cin.getline(name, 20);
	cout << "�� �� �� : ";		cin >> balance;

	if(con.push_back(new Account(id, balance, name)))
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
