#include "std.h"
#include "app.h"


void app_init()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* 자료구조 프로그램 실습         *\n");
	printf("* 단일 연결 리스트               *\n");
	printf("* 2012.12.12                     *\n");
	printf("* CCM                            *\n");
	printf("**********************************\n");
	Manager_init();
	system("pause");
}


void app_run()
{
	int choice;

	while(1)
	{
		system("cls");
		menu_Print();

		scanf("%d", &choice);
			
		switch(choice)
		{
			case 1:		Manager_Insert();		break;
			case 2:		Manager_printall();		break;
			case 3:		Manager_search();		break;
			case 4:		Manager_modify();		break;
			case 5:		Manager_dele();			break;
			case 6:		return;
			default:
				printf("잘못된 메뉴 입력 \n");
				break;
		}
		system("pause");
	}
}


void menu_Print()
{
	printf("**********************************\n"); 
	printf("* [1] 입력                       *\n");
	printf("* [2] 출력                       *\n");
	printf("* [3] 검색                       *\n");
	printf("* [4] 수정                       *\n");
	printf("* [5] 삭제                       *\n");
	printf("* [6] 종료                       *\n");
	printf("**********************************\n");
}


void app_Exit()
{
	system("cls");
	printf("**********************************\n"); 
	printf("* 프로그램 종료                  *\n");
	printf("**********************************\n");
	system("pause");
}