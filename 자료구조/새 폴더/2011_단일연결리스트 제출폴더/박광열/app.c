#include "std.h"
#include "manager.h"

void init()
{
	system("cls");
	printf("*******************************\n");
	printf("* ���� ���Ḯ��Ʈ             *\n");
	printf("*******************************\n");
	system("pause");
}
/*
void exit()
{
	system("cls");
	printf("*******************************\n");
	printf("* ���α׷� ����               *\n");
	printf("*******************************\n");
	system("pause");
}
*/
void menu()
{
	system("cls");
	printf("*******************************\n");
	printf("* [1]�Է�                     *\n");
	printf("* [2]�˻�                     *\n");
	printf("* [3]����                     *\n");
	printf("* [4]����                     *\n");
	printf("* [5]���                     *\n");
	printf("* [6]����                     *\n");
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