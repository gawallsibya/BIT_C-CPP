#include "std.h"
#include "app.h"
#include "manager.h"
void init()
{
	printf("==================init()===================\n");
	system("pause");
}
 
void menu()
{
	printf("===========================================\n");
	printf("1:insert\n");
	printf("2:printall\n");
	printf("3:search\n");
	printf("4:update\n");
	printf("5:del\n");
	system("pause");
}

void run()
{
		char a;
		//int n;
	while(1)
	{
	system("cls");
	menu();
	
	//scanf("%d",&n);
	printf("choice:\n");
	fflush(stdin);
	a=getchar();
	switch(a)
	{
	case '1':  insert(14); break;
	case '2':  printall();break;
	case '3':  search('a');break;
	case '4':   update('a' );break;
	case '5':   dele( );break;
	case '6':  return;
	}
	system("pause");
	}
}