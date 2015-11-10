#include "std.h"
#include "app.h"
#include "Manager.h"

void App_Init()
{
	printf("*********************\n");
	printf("* CPP ���α׷� �ǽ� *\n");
	printf("* ��Ƽ ����         *\n");
	printf("* 2012.12.13        *\n");
	printf("* CCM               *\n");
	printf("*********************\n");
	init_stack();
	system("pause");
	
}
void App_Run()
{
	int i;
	while(1)
	{
		App_Menu();
		printf("(1,2,3,4,5,6)���� : ");
		fflush(stdin);
		scanf("%d",&i);
		switch(i)
		{
			case 1:	top1_push_stack();	break;
			case 2:	top1_pop_stack();	break;
			case 3:	top2_push_stack();	break;
			case 4:	top2_pop_stack();	break;
			case 5:	stack_printall();	break;
			case 6:return;
		}
		system("pause");
	}
}
void App_Exit()
{
	system("cls");
	printf("**********************************\n");
	printf("**********���α׷� ����***********\n");
	printf("**********************************\n");
	system("pause");		
}
void App_Menu()
{
	system("cls");
	printf("**********************************\n");
	printf("* 1 top1_push   ******************\n");
	printf("* 2 top1_pop    ******************\n");
	printf("* 3 top2_push   ******************\n");
	printf("* 4 top2_pop    ******************\n");
	printf("* 5 ����ϱ�    ******************\n");
	printf("* 6 EXIT        ******************\n");
	printf("**********************************\n");
	system("pause");
}
