#include "std.h"
#include "manager.h"

void app_Init()
{
	printf( "**********************************\n" ); 
	printf( "stack  list   chenjie \n");
	printf( "**********************************\n" );
	system("pause");
	Manager_Init();

}

void app_Run()
{
	while(true)
	{
		system("cls");
		menuprint();
		char ch;
		ch = getch();		
		switch(ch)
		{
		case '1':	Manager_Insert();		break;
		case '2':   Manager_Printall();		break;
		case '3':   return;
		}
		system("pause");
	}
}

void app_Exit()
{
	system("cls");
	printf( "**********************************\n" ); 
	printf( "* exit                           *\n" );
	printf( "**********************************\n" );
	system("pause");
}

void menuprint()
{
	printf( "**********************************\n" ); 
	printf( "* [1] push                       *\n" ); 
	printf( "* [2] pop                        *\n" );
	printf(	"* [3] exit                       *\n" ); 
	printf( "**********************************\n" );
}
