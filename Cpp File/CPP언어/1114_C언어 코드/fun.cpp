#include "std.h"


void PrintMenu()				// 메뉴 출력
{
	cout << "---------------- MENU  --------------\n";
	cout << "1. 계좌 개설" << endl; 
	cout << "2. 입 금"     << endl;
	cout << "3. 출 금"	   << endl;
	cout << "4. 잔액조회"  << endl;
	cout << "5. 프로그램 종료" << endl; 
	cout << "-------------------------------------\n\n";

}
void MakeAccount()				// 계좌 개설을 위한 함수
{
	int		id;
	char	name[NAME_LEN];
	int		balance;

	cout << "계좌 개설 -----------------" << endl;
	cout << "계 좌 ID : ";		cin >> id;
	cout << "이    름 : ";		cin >> name;
	cout << "입 금 액 : ";		cin >> balance;

	pArray[index].id		= id;
	pArray[index].balance	= balance;
	strcpy(pArray[index].name, name);

	index++;
	fnEnter();
}

void Deposit()					// 입 금
{
	int		money;
	int		id;

	cout << "계 좌 ID : ";		cin >> id;
	cout << "입 금 액 : ";		cin >> money;

	for( int i=0; i<index; i++)
	{
		if( pArray[i].id == id)
		{
			pArray[i].balance	+= money;
			cout << "입금 완료" << endl;
			fnEnter();
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl; 
	fnEnter();
}


void Withdraw()				// 출 금
{
	int	money;
	int	id;

	cout << "계 좌 ID : ";		cin >> id;
	cout << "출 금 액 : ";		cin >> money;

	for( int i=0; i<index; i++)
	{
		if( pArray[i].id == id)
		{
			if( pArray[i].balance	< money )
			{
				cout << "잔액 부족 " << endl;
				fnEnter();
				return;
			}
			pArray[i].balance	-= money;
			cout << "출금 완료" << endl;
			fnEnter();
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl; 
	fnEnter();
}

void Inquire()					// 잔액 조회
{
	for( int i=0; i < index; i++)
	{
		cout << "계 좌 ID : "  << pArray[i].id << endl;
		cout << "이    름 : "  << pArray[i].name << endl;
		cout << "잔    액 : "  << pArray[i].balance << endl;
	}
	fnEnter();
}

void fnEnter()
{
	int temp = 0;
	printf("Press Any Key\n");
	getche();
}