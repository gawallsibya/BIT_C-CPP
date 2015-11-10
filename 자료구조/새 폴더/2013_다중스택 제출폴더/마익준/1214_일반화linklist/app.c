#include "std.h"
#include "manager.h"
void app_Init()
{	
	printf("==========================\n");
	printf("My_Void*_Link_List\n");
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
		printf("����:");
		fflush(stdin);
		scanf("%c",&i);
		switch(i)
		{
		case '1':manager_push_front();		break;
		case '2':manager_printall(MyPrint);	break;
		case '3':manager_Search();			break;
		case '4':manager_ChangeData();		break;
		case '5':manager_delete();			break;
		case '6':manager_update();			break;
		default:return;
		}
		system("pause");//���� 
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
	printf("[6]�ڿ� ����\n");
	printf("==========================\n");	
	
}