#include "std.h"
#include "app.h"


void app_init()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* �ڷᱸ�� ���α׷� �ǽ�         *\n");
	printf("* ���� ���� ����Ʈ               *\n");
	printf("* 2012.12.12                     *\n");
	printf("* CCM                            *\n");
	printf("**********************************\n");
	Manager_init();
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
			case 1:		Manager_Insert();		break;
			case 2:		Manager_printall();		break;
			case 3:		Manager_search();		break;
			case 4:		Manager_modify();		break;
			case 5:		Manager_dele();			break;
			case 6:		return;
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
	printf("* [1] �Է�                       *\n");
	printf("* [2] ���                       *\n");
	printf("* [3] �˻�                       *\n");
	printf("* [4] ����                       *\n");
	printf("* [5] ����                       *\n");
	printf("* [6] ����                       *\n");
	printf("**********************************\n");
}


void app_Exit()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* ���α׷� ����                  *\n");
	printf("**********************************\n");
	system("pause");
}