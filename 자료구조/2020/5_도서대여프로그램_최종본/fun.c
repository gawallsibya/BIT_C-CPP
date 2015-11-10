// fun.c
#include "std.h"

void fnTitle()
{
	printf("******************************\n");
	printf("*  상지 방학 특강            *\n");
	printf("*  프로그램 실습             *\n");
	printf("*  도서대여프로그램          *\n");
	printf("*  2006.7.27                 *\n");
	printf("*  만든 사람 : ccm           *\n");
	printf("******************************\n");

	fnEnter();
}

void fnGoodBye()
{
	system("cls");
	printf("******************************\n");
	printf("* 프로그램을 종료합니다.     *\n");
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
		default: printf("다시 선택\n"); break;
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
	printf(" [1] 회원 정보 입력    [4] 도서 정보 입력    [7] 도서 대여    [9] 프로그램 종료\n");
	printf(" [2] 회원 정보 출력    [5] 도서 정보 출력    [8] 도서 반납\n");
	printf(" [3] 회원 정보 검색    [6] 도서 정보 검색\n\n");
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
		printf("처음이군!!\n");
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
		printf("자료 저장 실패\n");
	}
	fnEnter();*/
}
