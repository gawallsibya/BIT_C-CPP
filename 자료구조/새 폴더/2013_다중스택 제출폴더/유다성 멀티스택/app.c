#include "std.h"
#include "app.h"


void app_init()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* �ڷᱸ�� ���α׷� �ǽ�         *\n");
	printf("* ����                           *\n");
	printf("* 2012.12.13                     *\n");
	printf("* CCM                            *\n");
	printf("**********************************\n");
	manager_init();
	system("pause");
}


void app_run()
{
	int choice;

	while(1)
	{
		system("cls");
		menu_Print();

		scanf("%d", &choice);
			
		switch(choice)
		{
			case 1:	manager_up_insert();		break;
			case 2:	manager_down_insert();		break;
			case 3:	manager_up_delete();		break;
			case 4:	manager_down_delete();		break;
			case 5:		return;
			default:
				printf("�߸��� �޴� �Է� \n");
				break;
		}
		system("pause");
	}
}


void menu_Print()
{
	printf("**********************************\n"); 
	printf("* [1] PUSH_UP                    *\n");
	printf("* [2] PUSH_DOWN                  *\n");
	printf("* [3] POP_UP                     *\n");
	printf("* [4] POP_DOWN                   *\n");
	printf("* [5] Exit                       *\n");
	printf("**********************************\n");
}


void app_Exit()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* ���α׷� ����                  *\n");
	printf("**********************************\n");
}