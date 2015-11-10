#include "app.h"
#include "std.h"
#include "manager.h"

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
	manager_myinit();
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
	printf("* [1] INSERT                     *\n"); 
	printf("* [2] PRINTALLDATA               *\n");
	printf("* [3] SEARCH                     *\n");
	printf("* [4] DELETE                     *\n");
	printf("* [5] MODIFY                     *\n");
	printf("* [6] EXIT                       *\n");
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
			case '1':	manager_insert();					break;
			case '2':   manager_printall();					break;
			case '3':	manager_search();					break;
			case '4':	manager_dele();						break;
			case '5':	manager_modify();					break;
			case '6':   return;
		}		
		system("pause");
	}
}

