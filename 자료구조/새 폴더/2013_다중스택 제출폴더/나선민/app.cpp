#include "app.h"
#include "manager.h"
void app_init()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* CPP ���α׷� �ǽ�1             *\n");
	printf("* Ŭ���� ���� �ǽ�               *\n");
	printf("* 2012.12.12                     *\n");
	printf("* CCM                            *\n");
	printf("**********************************\n");	
	system("pause");
	manager_init();
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
	printf("* [1] 1������	            *\n"); 
	printf("* [2] 2������		       	*\n");
	printf("* [3] EXIT		        *\n");
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
			case '1':	manager_printstack1();					break;
			case '2':	manager_printstack2();					break;		
			case '3':   return;				
		}		
		system("pause");
	}
}

