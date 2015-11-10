#include "std.h"
#include "manager.h"

void init()
{
	system("cls");
	printf("*******************************\n");
	printf("* 단일 연결리스트             *\n");
	printf("*******************************\n");
	system("pause");
}
/*
void exit()
{
	system("cls");
	printf("*******************************\n");
	printf("* 프로그램 종료               *\n");
	printf("*******************************\n");
	system("pause");
}
*/
void menu()
{
	system("cls");
	printf("*******************************\n");
	printf("* [1]입력                     *\n");
	printf("* [2]검색                     *\n");
	printf("* [3]수정                     *\n");
	printf("* [4]삭제                     *\n");
	printf("* [5]출력                     *\n");
	printf("* [6]종료                     *\n");
	printf("*******************************\n");
}

void run()
{
	char ch;
	while(1)
	{
		system("cls");
		menu();
		ch=getch();

		switch(ch)
		{
		case '1':	manager_insert();		break;
		case '2':	manager_search();		break;
		case '3':	manager_modify();		break;
		case '4':	manager_del();			break;
		case '5':	manager_printall();		break;
		case '6':	return;
		}
		system("pause");
	}
}