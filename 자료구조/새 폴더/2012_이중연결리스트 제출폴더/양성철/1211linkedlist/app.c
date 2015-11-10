#include "std.h"
#include "app.h"
#include "Manager.h"

void App_Init()
{
	system("cls");
	printf("**********************************\n");
	printf("* CPP 프로그램 실습              *\n");
	printf("* 단일 연결 리스트               *\n");
	printf("* 2012.12.11                     *\n");
	printf("* CCM                            *\n");
	printf("**********************************\n");
	system("pause");
}
void App_Run()
{
	int i;
	while(1)
	{
		App_Menu();
		printf("(1,2,3,4,5,6)선택 : ");
		fflush(stdin);
		scanf("%d",&i);
		switch(i)
		{
			case 1:Manager_Insert();		break;
			case 2:Manager_PrintAll();		break;
			case 3:Manager_Search();		break;
			case 4:Manager_Modify();		break;
			case 5:Manager_Erase();			break;
			case 6:return;
		}
		system("pause");
	}
}
void App_Exit()
{
	system("cls");
	printf("**********************************\n");
	printf("**********프로그램 종료***********\n");
	printf("**********************************\n");
	//system("pause");		
}
void App_Menu()
{
	system("cls");
	printf("**********************************\n");
	printf("* 1 입력 *************************\n");
	printf("* 2 출력 *************************\n");
	printf("* 3 검색 *************************\n");
	printf("* 4 수정 *************************\n");
	printf("* 5 삭제 *************************\n");
	printf("* 6 종료 *************************\n");
	printf("**********************************\n");
	system("pause");
}
