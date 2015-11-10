#include "std.h"
#include "manager.h"
void app_Init()
{	
	printf("==========================\n");
	printf("My_Stack_Link_List\n");
	printf("==========================\n");
	manager_slist_init();
	system("pause");
}

void app_Run()
{
	
	char i;
	while(1)
	{
		menu();
		printf("선택:");
		fflush(stdin);
		scanf("%c",&i);
		switch(i)
		{
		case '1':manager_push_front();break;
		case '2':manager_pop();break;
		default:return;
		}
		system("pause");//주의 
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
	printf("[1]push\n");
	printf("[2]pop\n");
	printf("==========================\n");	
	
}