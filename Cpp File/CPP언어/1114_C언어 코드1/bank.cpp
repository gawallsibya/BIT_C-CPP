//bank.cpp
#include "std.h"
#include "bank.h"

Bank::Bank() : index(0)
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

	acc[index]	= new Account(id, balance, name);

	index++;
}

void Bank::Deposit()					// �� ��
{
	int		money;
	int		id;

	cout << "�� �� ID : ";		cin >> id;
	cout << "�� �� �� : ";		cin >> money;

	for( int i=0; i<index; i++)
	{
		if( acc[i]->GetId() == id)
		{
			acc[i]->AddMoney(money);
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

	for( int i=0; i<index; i++)
	{
		if( acc[i]->GetId() == id)
		{
			if(acc[i]->MinMoney(money))
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
	for( int i=0; i < index; i++)
	{
		acc[i]->DataPrint();
	}
}
