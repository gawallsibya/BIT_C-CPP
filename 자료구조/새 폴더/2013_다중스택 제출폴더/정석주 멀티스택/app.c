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
	printf("* 프로그램 종료                  *\n");
	printf("**********************************\n");
	system("pause");
}

void menu()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* [ 1 ] 앞부터 삽입              *\n"); 
	printf("* [ 2 ] 뒤부터 삭제              *\n");
	printf("* [ 3 ] 뒤부터 삽입              *\n");
	printf("* [ 4 ] 앞부터 삭제              *\n");	
	printf("* [ 5 ] 출       력              *\n");
	printf("* [ 6 ] 종       료              *\n");
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