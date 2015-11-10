#include "std.h"

void init()
{
	system("cls");
	printf("**********************************\n");
	printf("* �ڷᱸ�� ���α׷� �ǽ�         *\n");
	printf("**********************************\n");
	stack_init();
	system("pause");
}

void menu()
{
	system("cls");
	printf("****************************\n");
	printf("[1] Stack 1 Push     *\n");
	printf("[2] Stack 1 Pop      *\n");
	printf("[3] Stack 2 Push   *\n");
	printf("[4] Stack 2 Pop    *\n");
	printf("[5] ���α׷� ����          *\n");
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
		case '1':	stack1_push();			break;
		case '2':   stack1_pop();			break;
		case '3':   stack2_push();			break;
		case '4':   stack2_pop();			break;
		case '5':   return;
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
