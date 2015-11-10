//manager.c
#include "std.h"

//#define MYARR MYLIST

LIST		g_arr;
MYQUEUE		g_queue;

void ma_init()
{
	con_init(&g_arr);	//dlist_init(&g_list);
	init_queue(&g_queue);
}


// 계좌 개설
void ma_makeaccount()
{
	ACCOUNT *acc = (ACCOUNT*)malloc(sizeof(ACCOUNT)); 

	printf("[ 계좌 개설 ]\n");
	printf("계 좌 ID : ");		scanf("%d", &acc->id);
	fflush(stdin);
	printf("이    름 : ");		gets(acc->name);
	printf("입 금 액 : ");		scanf("%d", &acc->balance);

	if(con_insert(&g_arr, acc))			//<===================================
	{
		printf("계좌가 개설되었습니다..\n");
		put(&g_queue, acc);
	}
	else
	{
		printf("계좌 개설 오류...\n");
	}
}

ACCOUNT* idtoaccount(LIST *parr, int id)
{
	int i;
	for(i=0; i< con_size(parr); i++)//<=========================
	{ 
		ACCOUNT *pData=con_getdata(parr,i);//<=========================
		if(pData->id	== id)
			return pData;
	}
	return NULL;
}

//입금
void ma_deposit()	
{
	int		money;
	int		id;
	ACCOUNT *pData;
	ACCOUNT *pData1;

	printf("[ 입 금 ]\n");
	printf("계 좌 ID : ");		scanf("%d", &id);
	printf("입 금 액 : ");		scanf("%d", &money);
	
	pData = idtoaccount(&g_arr, id);	
	if( pData != NULL)
	{
		acc_addmoney(pData, money);
	
		//=============================================
		pData1 = (ACCOUNT*)malloc(sizeof(ACCOUNT));
		strcpy(pData1->name, pData->name);
		pData1->id	= id;
		pData1->balance	= money;
		put(&g_queue, pData1);
		//============================================

		printf("입금 완료\n");
	}
	else
	{
		printf("계좌가 잘 못 되었습니다..");
	}
}

//출금
void ma_withdraw()
{
	int		money;
	int		id;
	ACCOUNT *pData;
	ACCOUNT *pData1;

	printf("[ 출 금 ]\n");
	printf("계 좌 ID : ");		scanf("%d", &id);
	printf("출 금 액 : ");		scanf("%d", &money);
	
	pData = idtoaccount(&g_arr, id);		
	if( pData != NULL)
	{
		if(acc_minmoney(pData, money))
		{
			//=============================================
			pData1 = (ACCOUNT*)malloc(sizeof(ACCOUNT));
			strcpy(pData1->name, pData->name);
			pData1->id	= id;
			pData1->balance	= money;
			put(&g_queue, pData1);
			//============================================

			printf("출금 완료\n");
		}
		else
		{
			printf("잔액 부족합니다..\n");
			
		}
	}
	else
	{
		printf("계좌가 잘 못 되었습니다..");
	}
}

// 잔액 조회
void ma_inquire()
{
	int i;
	for(i=0; i < con_size(&g_arr); i++)		//<====================
	{
		
		ACCOUNT *pData = con_getdata(&g_arr,i);
		acc_dataprint(pData);
	}
}


void ma_information()
{
	ACCOUNT *pData;
	while(pData = get(&g_queue))
	{
		acc_dataprint(pData);
	//	free(pData);
	}
}