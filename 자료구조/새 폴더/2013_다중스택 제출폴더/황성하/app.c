#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "app.h"
#include "sta.h"

void app_init()
{	
	system("cls");
	printf("**********************************\n"); 
	printf("* CPP ���α׷� �ǽ�1             *\n");
	printf("* Ŭ���� ���� �ǽ�               *\n");
	printf("* 2012.11.1                      *\n");
	printf("* CCM                            *\n");
	printf("**********************************\n");	
	system("pause");
	stack_init();
}

void app_Exit()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* ���α׷� ����                  *\n");
	printf("**********************************\n");
	system("pause");
}

void app_menu()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* [1] front push                 *\n"); 
	printf("* [2] back push                  *\n");
	printf("* [3] front pop                  *\n");
	printf("* [4] back pop                   *\n");
	printf("* [5] EXIT                       *\n");
	printf("**********************************\n");

}

void app_run()
{
	char ch;	

	while(1)
	{	
		app_menu();	
		ch=getch();			
		switch(ch)
		{
			case '1':	front_push();				break;
			case '2':	back_push();				break;
			case '3':	front_pop();				break;
			case '4':	back_pop();					break;
			case '5':   return;
		}		
		system("pause");
	}
}
