#include "std.h"
#include "App.h"
#include "Manager.h"

void init()
{
	system("cls");
	printf("**********************************\n");
	printf("* �ڷᱸ�� ���α׷� �ǽ�         *\n");
	printf("* ���� ����Ʈ ���α׷�           *\n");
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
	printf("[1] ����Ʈ �߰�            *\n");
	printf("[2] ����Ʈ ���            *\n");
	printf("[3] ����Ʈ �˻�            *\n");
	printf("[4] ����Ʈ ����            *\n");
	printf("[5] ����Ʈ ����            *\n");
	printf("[6] ���α׷� ����          *\n");
	printf("****************************\n");
}

void run()
{
	char ch;
	while(1)
	{
		system("cls");
		menu();
		printf("�޴��� �����Ͻÿ�. : ");
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
	printf("* ���α׷� ����                  *\n");
	printf("**********************************\n");
	system("pause");
}
