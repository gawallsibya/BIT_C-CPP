//bank.cpp
#include "std.h"
#include "bank.h"
#include "Account.h"
#include "GibuAccoiunt.h"
#include "SinAccoiunt.h"

Bank::Bank(int size) : con(size) {}

void Bank::PrintMenu()				// �޴� ���
{
	cout << "---------------- MENU  --------------\n";
	cout << "1. ���� ����" << endl; 
	cout << "2. �� ��"     << endl;
	cout << "3. �� ��"	   << endl;
	cout << "4. �ܾ���ȸ"  << endl;
	cout << "5. ���α׷� ����" << endl; 
	cout << "-------------------------------------\n\n";
}

void Bank::MakeAccount()				// ���� ������ ���� �Լ�
{
	int		id;
	char	name[NAME_LEN];
	int		balance;
	int		temp;

	cout << "���� ���� -----------------" << endl;
	cout << "�� �� ID : ";		cin >> id;
	cin.ignore();
	cout << "��    �� : ";		cin.getline(name, 20);
	cout << "�� �� �� : ";		cin >> balance;
	cout << "�Ա� ���� ����. [1]�Ϲݰ���. [2]��ΰ���. [3]�ſ����."; cin >> temp;

	Account * p;
	switch(temp)
	{
	case 1 : p = new Account(id, balance, name);		break;
	case 2 : p = new GibuAccount(id, balance, name);	break;
	case 3 : p = new SinAccount(id, balance, name);		break;
	}

	if (con.push_back(p))
	{
		cout << "����." << endl;
	}
	else
	{
		cout << "���� ����." << endl;
	}v
}

void Bank::Deposit()					// �� ��
{
	int		money;
	int		id;

	cout << "�� �� ID : ";		cin >> id;
	cout << "�� �� �� : ";		cin >> money;

	for( int i=0; i<con.GetIndex(); i++)
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

void Bank::fnEnter()
{
	int temp = 0;
	printf("Press Any Key\n");
	getche();
}