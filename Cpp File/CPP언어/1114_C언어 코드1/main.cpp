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
		cout << "선택 : ";
		cin >> choice;

		switch( choice)
		{
		case MAKE:		bank.MakeAccount();		break;
		case DEPOSIT:	bank.Deposit();			break;
		case WITHDRAW:	bank.Withdraw();			break;
		case INQUIRE:	bank.Inquire();			break;
		case EXIT:		return 0;
		default:
			cout << "잘못된 메뉴 입력 " << endl;
			break;
		}
		system("pause");
	}
	return 0;
}