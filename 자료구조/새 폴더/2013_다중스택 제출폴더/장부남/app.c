#include "std.h"
#include "app.h"
#include "stack.h"

void init()
{	

	system("cls");
	printf("**********************************\n"); 
	printf("* ��Ƽ���� ���� �ǽ�             *\n");
	printf("* 2012.12.13                     *\n");
	printf("**********************************\n");	
	system("pause");
	stack_init();

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
	printf("*********************************\n"); 
	printf("* [1] ���Է�a_push		  *\n"); 
	printf("* [2] a_pop		          *\n");
	printf("* [3] �Ʒ� �Է�b_push		  *\n"); 
	printf("* [4] b_pop		          *\n");
	printf("* [5] print		          *\n");
	printf("* [6] EXIT                        *\n");
	printf("*********************************\n");

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
			case '1':	a_push();			break;
			case '2':	a_pop();			break;
			case '3':	b_push();			break;
			case '4':	b_pop();			break;
			case '5':	printall();			break;
			case '6':   return;
		}		
		system("pause");
	}


}
