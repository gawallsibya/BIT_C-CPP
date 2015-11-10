#include"std.h"
#include"app.h"
#include"manager.h"
void app_init()
{
	printf("===========================\n");
	printf("  stack  chenjie           \n");
	printf("===========================\n");
	manager_init();
	system("pause");
}
void app_run()
{
	char c;
	while(1)
	{
		system("cls");
		menu();
		printf("choice:\n");
		fflush(stdin);
		c=getchar();
		switch(c)
		{
		case '1':manager_front_push();break;
		case '2':manager_back_push();break;
		case'3': manager_front_pop();break;
		case '4':manager_back_pop();break;
		case '5':return;
		}
		system("pause");
	}

	
}
void app_exit()
{
	system("cls");
	printf("===========================\n");
	printf("  exit                     \n");
	printf("===========================\n");
}
void menu()
{
	printf("===========================\n");
	printf("1 front_push\n");
	printf("2 back_push\n");
	printf("3 front_pop\n");
	printf("4 back_pop\n");
	printf("5 exit\n");
	printf("===========================\n");
}