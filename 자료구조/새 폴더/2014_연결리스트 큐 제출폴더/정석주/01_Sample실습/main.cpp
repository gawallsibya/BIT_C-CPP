#include "std.h"


Account		pArray[100];
int			index = 0;

int main()
{
	int choice;

	while(1)
	{
		system("cls");
		PrintMenu();
		cout << "선택 : ";
		cin >> choice;

		switch( choice)
		{
		case MAKE:		MakeAccount();		break;
		case DEPOSIT:	Deposit();			break;
		case WITHDRAW:	Withdraw();			break;
		case INQUIRE:	Inquire();			break;
		case EXIT:		return 0;
		default:
			cout << "잘못된 메뉴 입력 " << endl;
			break;
		}
	}
	return 0;
}