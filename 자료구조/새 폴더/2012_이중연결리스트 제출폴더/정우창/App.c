#include "std.h"
#include "App.h"
#include "Manager.h"

void init()
{
	system("cls");
	printf("**********************************\n");
	printf("* 자료구조 프로그램 실습         *\n");
	printf("* 연결 리스트 프로그램           *\n");
	printf("* 2012.12.11                     *\n");
	printf("* JWC                            *\n");
	printf("**********************************\n");
	manager_init();
	system("pause");
}

void menu()
{
	system("cls");
	printf("****************************\n");
	printf("[1] 리스트 추가            *\n");
	printf("[2] 리스트 출력            *\n");
	printf("[3] 리스트 검색            *\n");
	printf("[4] 리스트 수정            *\n");
	printf("[5] 리스트 삭제            *\n");
	printf("[6] 프로그램 종료          *\n");
	printf("****************************\n");
}

void run()
{
	char ch;
	while(1)
	{
		system("cls");
		menu();
		printf("메뉴룰 선택하시오. : ");
		fflush(stdin);
		scanf("%c", &ch);
		switch(ch)
		{
		case '1':	Insert();		break;
		case '2':   Printall();		break;
		case '3':   Search();		break;
		case '4':   Modify();		break;
		case '5':   Del();			break;
		case '6':   return;
		}
		system("pause");
	}
}

void Exit()
{
	system("cls");
	printf("**********************************\n");
	printf("* 프로그램 종료                  *\n");
	printf("**********************************\n");
	system("pause");
}
