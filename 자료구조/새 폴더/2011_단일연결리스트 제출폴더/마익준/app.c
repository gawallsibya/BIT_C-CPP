#include "std.h"
#include "manager.h"
void app_Init()
{	
	printf("==========================\n");
	printf("MyList\n");
	printf("==========================\n");
	manager_init();
	system("pause");
}

void app_Run()
{
	
	char i;
	while(1)
	{
		menu();
		printf("����:");
		fflush(stdin);
		scanf("%c",&i);
		switch(i)
		{
		case '1':manager_push_front();break;
		case '2':manager_printall();break;
		case '3':manager_search();break;
		case '4':manager_change();break;
		case '5':manager_dele();break;
		case '6':return;
		}
		system("pause");
	}
}

void app_Exit()
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