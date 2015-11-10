#include "app.h"
#include "std.h"
#include "manager.h"

void init()
{	
	system("cls");
	printf("**********************************\n"); 
	printf("*                                *\n");
	printf("**********************************\n");	
	system("pause");
	manager_Init();
}


void Exit()
{	
	system("cls");
	printf("**********************************\n"); 
	printf("* ���α׷� ����                  *\n");
	printf("**********************************\n");
	system("pause");
}

void menu()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* [ 1 ] ����                     *\n"); 
	printf("* [ 2 ] ���                     *\n");
	printf("* [ 3 ] �˻�                     *\n");
	printf("* [ 4 ] ����                     *\n");
	printf("* [ 5 ] ����                     *\n");
	printf("* [ 6 ] ����                     *\n");
	printf("**********************************\n");
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
			case '1':	Insert();			break;
			case '2':   Print();			break;
			case '3':	search();			break;
			case '4':	modify();			break;
			case '5':	del();				break;
			case '6':   return;
		}	
		system("pause");
	}
}







