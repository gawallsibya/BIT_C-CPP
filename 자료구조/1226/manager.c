//manager.c

#include "std.h"


Arr		g_arr;
List	g_list;

void ma_init()
{
	init_arr(&g_arr);	//dlist_init(&g_list);
	init_list(&g_list);
	srand(time(NULL));
}


// 예약
void ma_reserve()
{
	int i;
	
	Member *res = (Member*)malloc(sizeof(Member)); 
	arr_info(&g_arr);
	
	while(1)
	{
		printf("예약매수 입력: ");		scanf("%d",&res->count);
		if(res->count > 0 && res->count < 6)
			break;
		else
			printf("재입력...\n");
	}
	for(i=0; i < res->count; i++)
	{
		printf("좌석 입력 : ");		scanf("%d",&res->seat[i]);
		if(g_arr.data[res->seat[i]-1] != NULL)
		{
			printf("재입력...\n");
			i -= 1;
			continue;
		}
	}
	fflush(stdin);
	printf("전화번호 입력 : ");		gets(res->phone);
	for(i=0; i<5; i++)
	{
		res->number[i]=rand()%10+48;
		if(i==4)
			res->number[i+1]='\0';
	}
	for(i=0; i < res->count; i++)
	{
		arr_insert(&g_arr, res,res->seat[i]);			//<===================================		
	}
	list_insert(&g_list, res);
	printf("예약이 완료 되었습니다..\n");
	printf("예약번호: %s\n",res->number); 
}

/*
ACCOUNT* idtoaccount(MYARR *parr, int id)
{
	int i;
	for(i=0; i< con_size(parr); i++)//<=========================
	{
		ACCOUNT *pData = con_getdata(parr, i);//<=========================
		if(pData->id	== id)
			return pData;
	}
	return NULL;
}
*/

void ma_check()	
{
	int num;
	char num1[20];
	Member* cur;
	printf("[1] 전화번호 [2] 예약 번호\n");
	
	while(1)
	{
		scanf("%d",&num);
		if(num==1)
		{
			printf("전화번호 입력: "); 
			fflush(stdin);
			gets(num1);
			cur=list_search(&g_list,num1);
			break;
		}
		else if(num==2)
		{
			printf("예약번호 입력: "); 
			fflush(stdin);
			gets(num1);
			cur=list_search(&g_list,num1);
			break;
		}
		else
		{
			printf("다시 입력하세요..\n");
			continue;
		}
	}
	if(cur != NULL)
		list_print(cur);
	else
	{
		printf("예약정보를 찾을수 없음..\n");
		return;
	}
}

//출금
void ma_cancel()
{
	int num,i;
	char ch;
	char num1[20];
	Member* cur;
	printf("[1] 전화번호 [2] 예약 번호\n");
	
	while(1)
	{
		scanf("%d",&num);
		if(num==1)
		{
			printf("전화번호 입력: "); 
			fflush(stdin);
			gets(num1);
			cur=list_search(&g_list,num1);
			break;
		}
		else if(num==2)
		{
			printf("예약번호 입력: "); 
			fflush(stdin);
			gets(num1);
			cur=list_search(&g_list,num1);
			break;
		}
		else
		{
			printf("다시 입력하세요..\n");
			continue;
		}
	}
	if(cur != NULL)
		list_print(cur);
	else
	{
		printf("예약정보를 찾을수 없음..\n");
		return;
	}
	printf("\n위 예약을 취소할까요? : (y, n)");	
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y')
	{
		free(cur);
		for(i=0; i < cur->count ;i++);
		g_arr.data[cur->seat[i]-1]=NULL;
	}
	else
	return;
}
/*
// 잔액 조회
void ma_inquire()
{
	int i;
	for(i=0; i < con_size(&g_arr); i++)		//<====================
	{
		ACCOUNT *pData = con_getdata(&g_arr, i);

		acc_dataprint(pData);
	}
}


void ma_information()
{
	ACCOUNT *pData;
	while(pData = get(&g_queue))
	{
		acc_dataprint(pData);
		free(pData);
	}
}*/