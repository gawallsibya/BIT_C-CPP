#include "app.h"
#include "manager.h"
void app_init()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* CPP 프로그램 실습1             *\n");
	printf("* 클래스 구현 실습               *\n");
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
	printf("* 프로그램 종료                  *\n");
	printf("**********************************\n");
	system("pause");
}
void app_menu()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* [1] 1번스택	            *\n"); 
	printf("* [2] 2번스택		       	*\n");
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

