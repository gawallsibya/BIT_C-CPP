#include "std.h"
#include "manager.h"
void Init()
{	
	printf("�١١١١١١١١١١١١١�\n");
	printf("�ڷᱸ�� �ܼ����� ����Ʈ\n");
	printf("�١١١١١١١١١١١١١�\n");
	system("pause");
	init();
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
		case 1:insert();break;
		case 2:printall();break;
		case 3:search();break;
		case 4:modify();break;
		case 5:dele();break;
		default:return;
		}
	}
}

void Exit()
{
	system("cls");
	printf("�١١١١١١١١١١١١١�\n");
	printf("����!!!!!!\n");
	printf("�١١١١١١١١١١١١١�\n");
}

void menu()
{
	system("cls");
	printf("�١١١١١١١١١١١١١�\n");
	printf("[1]����\n");
	printf("[2]���\n");
	printf("[3]�˻�\n");
	printf("[4]����\n");
	printf("[5]����\n");
	printf("�١١١١١١١١١١١١١�\n");
	
}