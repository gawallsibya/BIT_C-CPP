#include "app.h"
#include "std.h"
#include "stack.h"

void init()
{	
	system("cls");
	printf("**********************************\n"); 
	printf("*                                *\n");
	printf("**********************************\n");	
	system("pause");
	stinit();
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
	printf("* [ 1 ] �պ��� ����              *\n"); 
	printf("* [ 2 ] �ں��� ����              *\n");
	printf("* [ 3 ] �ں��� ����              *\n");
	printf("* [ 4 ] �պ��� ����              *\n");	
	printf("* [ 5 ] ��       ��              *\n");
	printf("* [ 6 ] ��       ��              *\n");
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
			case '1':	push_down(); 	    break;
			case '2':   pop_down();			break;
			case '3':	push_up();			break;
			case '4':	pop_up();			break;			
			case '5':	printall();			break;
			case '6':   return;
		}	
		system("pause");
	}
}