#include "app.h"

void init()
{	
	system("cls");
	printf("**********************************\n"); 
	printf("* CPP ���α׷� �ǽ�1             *\n");
	printf("* Ŭ���� ���� �ǽ�               *\n");
	printf("* 2012.11.1                      *\n");
	printf("* CCM                            *\n");
	printf("**********************************\n");	
	system("pause");
}

void menu()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* [1] INSERT                     *\n"); 
	printf("* [2] PRINTALLDATA               *\n");
	printf("* [3] SEARCH                     *\n");
	printf("* [4] DELETE                     *\n");
	printf("* [5] MODIFY                     *\n");
	printf("* [6] EXIT                       *\n");
	printf("**********************************\n");

}


void Exit()
{	
	system("cls");
	printf("**********************************\n"); 
	printf("* ���α׷� ����                  *\n");
	printf("**********************************\n");
	system("pause");
}

void run()
{
	char ch;	

	while(1)
	{	
		menu();	
		ch=getch();			
		switch(ch)
		{
			case '1':	insert();					break;
			case '2':  printall();					break;
			case '3':	search();					break;
			case '4':	dele();						break;
			case '5':	modify();					break;
			case '6':  return;
		}		
		system("pause");
	}
}

