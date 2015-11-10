#include"std.h"
#include"app.h"
#include"manager.h"
void app_init()
{
	printf("====================================\n");
	printf("            mylist  chenjie         \n");
	printf("====================================\n");
	manager_init();
	system("pause");
}
void menu()
{
	printf("====================================\n");
	printf("1:insert()\n");
	printf("2:printall()\n");
	printf("3:search()\n");
	printf("4:update()\n");
	printf("5:delete()\n");
	printf("6:exit()\n");
	printf("====================================\n");

}

void app_run()
{
	char c;
	while(1)
	{
		system("cls");
		menu();
		printf("선택하세요:\n");
		fflush(stdin);
		c=getchar();
		switch(c)
		{
		case '1':manager_insert();break;
		case '2':manager_printall();break;
		case '3':manager_search();break;
		case '4':manager_update();break;
		case '5':manager_delete();break;
		case '6':return;
		}
		system("pause");
	}
	
}

void app_exit()
{
	system("cls");
	printf("==========================\n");
	printf("            end           \n");
	printf("==========================\n");
}