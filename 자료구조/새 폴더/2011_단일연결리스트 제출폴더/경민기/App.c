#include "std.h"
#include "manager.h"
void Init()
{	
	printf("』』』』』』』』』』』』』』\n");
	printf("切戟姥繕 舘授尻衣 軒什闘\n");
	printf("』』』』』』』』』』』』』』\n");
	system("pause");
	init();
}

void Run()
{
	
	int i;
	while(1)
	{
		menu();
		printf("識澱:");
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
	printf("』』』』』』』』』』』』』』\n");
	printf("曽戟!!!!!!\n");
	printf("』』』』』』』』』』』』』』\n");
}

void menu()
{
	system("cls");
	printf("』』』』』』』』』』』』』』\n");
	printf("[1]諮脊\n");
	printf("[2]窒径\n");
	printf("[3]伊事\n");
	printf("[4]呪舛\n");
	printf("[5]肢薦\n");
	printf("』』』』』』』』』』』』』』\n");
	
}