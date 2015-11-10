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

void fnEnter()
{
	int temp = 0;
	printf("Press Any Key\n");
	getche();
}