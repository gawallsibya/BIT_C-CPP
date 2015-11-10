//app.c
#include "app.h"
#include "std.h"
#include "manager.h"

void init()
{
	system("cls");
	printf("*******************************\n");
	printf("* 멀티 스텍                   *\n");
	printf("*******************************\n");
	manager_init();
	system("pause");
}

void select()
{
	system("cls");
	printf("**********************\n");
	printf("*[1] push_front      *\n");
	printf("*[2] push_back       *\n");
	printf("*[3] printall        *\n");
	printf("*[4] end             *\n");
	printf("**********************\n");
}

void choice()
{
	char ch;
	while(1)
	{
		system("cls");
		select();
		ch = getch();
		switch(ch)
		{
		case '1':push_front_run();		break;
		case '2':push_back_run();		break;
		case '3':manager_printall();	break;
		case '4':return;				
		}
		system("pause");
	}
}

void push_front()
{
	system("cls");
	printf("**********************\n");
	printf("*[1] insert          *\n");
	printf("*[2] push_pop        *\n");
	printf("*[3] front_printall  *\n");
	printf("*[4] page up         *\n");
	printf("**********************\n");
}

void push_front_run()
{
	char ch;
	while(1)
	{
		system("cls");
		push_front();
		ch = getch();
		switch(ch)
		{
		case '1':manager_push_front_insert();		; break;
		case '2':manager_push_front_push_pop();		; break;
		case '3':manager_push_front_printall();		; break;
		case '4':return;			
		}
		system("pause");
	}
}

void end()
{
	system("cls");
	printf("**********************\n");
	printf("*      bye bye       *\n");
	printf("**********************\n");
	return;
}

void push_back()
{
	system("cls");
	printf("**********************\n");
	printf("*[1] insert          *\n");
	printf("*[2] push_pop        *\n");
	printf("*[3] back_printall   *\n");
	printf("*[4] page up         *\n");
	printf("**********************\n");
}

void push_back_run()
{
	char ch;
	while(1)
	{
		system("cls");
		push_back();
		ch = getch();
		switch(ch)
		{
		case '1':manager_push_back_insert();		break;
		case '2':manager_push_back_push_pop();		break;
		case '3':manager_push_back_printall();		break;
		case '4':return;					
		}
		system("pause");
	}
}
