#include "std.h"
#include "manager.h"
void Init()
{	
	printf("==========================\n");
	printf("MyList\n");
	printf("==========================\n");
	system("pause");
}

void Run()
{
	
	int i;
	while(1)
	{
		menu();
		printf("����:");
		fflush(stdin);
		scanf("%d",&i);
		switch(i)
		{
		case 1:push_front();break;
		case 2:printall();break;
		case 3:search();break;
		case 4:change();break;
		case 5:dele();break;
		default:return;
		}
	}
}

void Exit()
{
	system("cls");
	printf("==========================\n");
	printf("END\n");
	printf("==========================\n");
}

void menu()
{
	system("cls");
	printf("==========================\n");
	printf("[1]����\n");
	printf("[2]���\n");
	printf("[3]�˻�\n");
	printf("[4]����\n");
	printf("[5]����\n");
	printf("==========================\n");	
	
}