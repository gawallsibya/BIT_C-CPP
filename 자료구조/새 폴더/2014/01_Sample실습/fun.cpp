#include "std.h"


void PrintMenu()				// �޴� ���
{
	cout << "---------------- MENU  --------------\n";
	cout << "1. ���� ����" << endl; 
	cout << "2. �� ��"     << endl;
	cout << "3. �� ��"	   << endl;
	cout << "4. �ܾ���ȸ"  << endl;
	cout << "5. ���α׷� ����" << endl; 
	cout << "-------------------------------------\n\n";

}
void MakeAccount()				// ���� ������ ���� �Լ�
{
	int		id;
	char	name[NAME_LEN];
	int		balance;

	cout << "���� ���� -----------------" << endl;
	cout << "�� �� ID : ";		cin >> id;
	cout << "��    �� : ";		cin >> name;
	cout << "�� �� �� : ";		cin >> balance;

	pArray[index].id		= id;
	pArray[index].balance	= balance;
	strcpy(pArray[index].name, name);

	index++;
	fnEnter();
}

void Deposit()					// �� ��
{
	int		money;
	int		id;

	cout << "�� �� ID : ";		cin >> id;
	cout << "�� �� �� : ";		cin >> money;

	for( int i=0; i<index; i++)
	{
		if( pArray[i].id == id)
		{
			pArray[i].balance	+= money;
			cout << "�Ա� �Ϸ�" << endl;
			fnEnter();
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl; 
	fnEnter();
}


void Withdraw()				// �� ��
{
	int	money;
	int	id;

	cout << "�� �� ID : ";		cin >> id;
	cout << "�� �� �� : ";		cin >> money;

	for( int i=0; i<index; i++)
	{
		if( pArray[i].id == id)
		{
			if( pArray[i].balance	< money )
			{
				cout << "�ܾ� ���� " << endl;
				fnEnter();
				return;
			}
			pArray[i].balance	-= money;
			cout << "��� �Ϸ�" << endl;
			fnEnter();
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl; 
	fnEnter();
}

void Inquire()					// �ܾ� ��ȸ
{
	for( int i=0; i < index; i++)
	{
		cout << "�� �� ID : "  << pArray[i].id << endl;
		cout << "��    �� : "  << pArray[i].name << endl;
		cout << "��    �� : "  << pArray[i].balance << endl;
	}
	fnEnter();
}

void fnEnter()
{
	int temp = 0;
	printf("Press Any Key\n");
	getche();
}