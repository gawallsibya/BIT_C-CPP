// fun.c
#include "std.h"

void fnTitle()
{
	printf("******************************\n");
	printf("*  ���� ���� Ư��            *\n");
	printf("*  ���α׷� �ǽ�             *\n");
	printf("*  �����뿩���α׷�          *\n");
	printf("*  2006.7.27                 *\n");
	printf("*  ���� ��� : ccm           *\n");
	printf("******************************\n");

	fnEnter();
}

void fnGoodBye()
{
	system("cls");
	printf("******************************\n");
	printf("* ���α׷��� �����մϴ�.     *\n");
	printf("******************************\n");

	fnEnter();

}

void fnInit()
{
	fnTitle();
	fnLoad(fileName);
}


void fnRun()
{
	char key;
	fnMenu();
	while( ( key = getch() ) != '9' )
	{
		switch( key) 
		{
		case '1' : fnPersonInput();		break;
		case '2' : fnPersonPrint();		break;
		case '3' : fnPersonSearch();	break;
		case '4' : fnBookInput();		break;
		case '5' : fnBookPrint();		break;
		case '6' : fnBookSearch();		break;
		case '7' : fnBookRent();		break;
		case '8' : fnBookReturn();		break;
		default: printf("�ٽ� ����\n"); break;
		}
		fnEnter();
		fnMenu();
	}
}

void fnExit()
{
	fnGoodBye();
	fnSave(fileName);
}

void fnMenu()
{
	system("cls");
	printf("********************************************************************************\n");
	printf("                                   [ main menu]\n\n");
	printf(" [1] ȸ�� ���� �Է�    [4] ���� ���� �Է�    [7] ���� �뿩    [9] ���α׷� ����\n");
	printf(" [2] ȸ�� ���� ���    [5] ���� ���� ���    [8] ���� �ݳ�\n");
	printf(" [3] ȸ�� ���� �˻�    [6] ���� ���� �˻�\n\n");
	printf("********************************************************************************\n");

}

void fnEnter()
{
	int n;
	printf("Press Any Key\n");
	n = getch();
}


void fnLoad(char *fn)
{/*
	Node *cur;
	FILE *fp;
	char name[20];
	int phone;

	system("cls");

	printf("Loading...\n");

	if((fp=fopen(fn,"r"))!=NULL)
	{
		while(fread(name,sizeof(name),1,fp))
		{
			cur = (Node*)malloc(sizeof(Node));
			
			fread(&phone,sizeof(int),1,fp);
			
			strcpy(cur->data.Name, name);
			cur->data.Phone = phone;
			cur->next = NULL;
			Insert(cur);
		}
		
		fclose(fp);
	}
	else
	{
		printf("ó���̱�!!\n");
	}
	fnEnter();
	*/
}


void fnSave(char *fn)
{/*
	Node *cur;
	FILE *fp;
	system("cls");

	printf("Saving...\n");


	if((fp=fopen(fn,"w"))!=NULL)
	{
		for(cur = start; cur; cur=cur->next)
		{
			fwrite(cur->data.Name,sizeof(cur->data.Name),1,fp);
			fwrite(&cur->data.Phone,sizeof(int),1,fp);
		}
		
		fclose(fp);
	}
	else
	{
		printf("�ڷ� ���� ����\n");
	}
	fnEnter();*/
}
