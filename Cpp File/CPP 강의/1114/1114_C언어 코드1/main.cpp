#include "std.h"
#include "bank.h"

int main()
{
	Bank bank(10);
	int choice;

	while(1)
	{
		system("cls");
		bank.PrintMenu();
		cout << "선택 : ";
		cin >> choice;

		switch( choice)
		{
		case 1 :		bank.MakeAccount();		break;
		case 2 :		bank.Deposit();			break;
		case 3 :		bank.Withdraw();		break;
		case 4 :		bank.Inquire();			break;
		case 5 :		return 0;
		default:
			cout << "잘못된 메뉴 입력 " << endl;
			break;
		}
		system("pause");
	}
	return 0;
}