#include "std.h"
#include "app.h"
#include "Manager.h"

void App_Init()
{
	system("cls");
	printf("**********************************\n");
	printf("* CPP ���α׷� �ǽ�              *\n");
	printf("* ���� ���� ����Ʈ               *\n");
	printf("* 2012.12.11                     *\n");
	printf("* CCM                            *\n");
	printf("**********************************\n");
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
			case 1:Manager_Insert();		break;
			case 2:Manager_PrintAll();		break;
			case 3:Manager_Search();		break;
			case 4:Manager_Modify();		break;
			case 5:Manager_Erase();			break;
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
	//system("pause");		
}
void App_Menu()
{
	system("cls");
	printf("**********************************\n");
	printf("* 1 �Է� *************************\n");
	printf("* 2 ��� *************************\n");
	printf("* 3 �˻� *************************\n");
	printf("* 4 ���� *************************\n");
	printf("* 5 ���� *************************\n");
	printf("* 6 ���� *************************\n");
	printf("**********************************\n");
	system("pause");
}
