//app.cpp
#include "App.h"
#include "conio.h"
#include"std.h"
#include<stdlib.h>

LIST list;	
void init()
{
	system("cls");
	printf("**********************************\n" );
	printf("* CPP 프로그램 실습1             *\n" ); 
	printf("* 자료구조                     *\n" );
	printf("* 2012.12.11                      *\n" );
	printf("* CCM                            *\n" );
	printf("**********************************\n" );
	system("pause");
	
}


void Exit()
{
	system("cls");
	printf("**********************************\n" );
	printf("* 프로그램 종료                  *\n" );
	printf("**********************************\n" );
	system("pause");
}


void menuprint()
{
	printf("**********************************\n" );
	printf("* [1] INSERT                     *\n" ); 
	printf("* [2] PRINTALLDATA               *\n" );
	printf("* [3] SEARCH                     *\n" );
	printf("* [4] UPDATE                      *\n" );
	printf("* [5] DELETE                     *\n" );
	printf("* [6] EXIT                       *\n" );
	printf("**********************************\n" );
}

void run()
{
	char ch;
	while(1)
	{
		system("cls");
		menuprint();
	
		ch = getch();		//#include "conio.h"
		switch(ch)
		{
		case '1':	insert(list);			break;
		case '2':   printall(list);		break;
		case '3':
			printall(list);	
			printf("\n문자 검색 :");
						scanf("%c",&ch);
						fflush(stdin);
						search(ch);			break;
		case '4':
			printall(list);	
			updata();	
			printall(list);	break;
		case '5':  printall(list); del();	printall(list);		break;
		case '6':   return;
		}
		system("pause");
	}
}
