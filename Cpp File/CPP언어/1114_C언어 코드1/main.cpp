#include "std.h"
#include "bank.h"

int main()
{
	Bank bank;
	int choice;

	while(1)
	{
		system("cls");
		PrintMenu();
		cout << "���� : ";
		cin >> choice;

		switch( choice)
		{
		case MAKE:		bank.MakeAccount();		break;
		case DEPOSIT:	bank.Deposit();			break;
		case WITHDRAW:	bank.Withdraw();			break;
		case INQUIRE:	bank.Inquire();			break;
		case EXIT:		return 0;
		default:
			cout << "�߸��� �޴� �Է� " << endl;
			break;
		}
		system("pause");
	}
	return 0;
}