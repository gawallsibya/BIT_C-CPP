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


// ���� ����
void ma_makeaccount()
{
	ACCOUNT *acc = (ACCOUNT*)malloc(sizeof(ACCOUNT)); 

	printf("[ ���� ���� ]\n");
	printf("�� �� ID : ");		scanf("%d", &acc->id);
	fflush(stdin);
	printf("��    �� : ");		gets(acc->name);
	printf("�� �� �� : ");		scanf("%d", &acc->balance);

	if(con_insert(&g_arr, acc))			//<===================================
	{
		printf("���°� �����Ǿ����ϴ�..\n");
		put(&g_queue, acc);
	}
	else
	{
		printf("���� ���� ����...\n");
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

//�Ա�
void ma_deposit()	
{
	int		money;
	int		id;
	ACCOUNT *pData;
	ACCOUNT *pData1;

	printf("[ �� �� ]\n");
	printf("�� �� ID : ");		scanf("%d", &id);
	printf("�� �� �� : ");		scanf("%d", &money);
	
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

		printf("�Ա� �Ϸ�\n");
	}
	else
	{
		printf("���°� �� �� �Ǿ����ϴ�..");
	}
}

//���
void ma_withdraw()
{
	int		money;
	int		id;
	ACCOUNT *pData;
	ACCOUNT *pData1;

	printf("[ �� �� ]\n");
	printf("�� �� ID : ");		scanf("%d", &id);
	printf("�� �� �� : ");		scanf("%d", &money);
	
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

			printf("��� �Ϸ�\n");
		}
		else
		{
			printf("�ܾ� �����մϴ�..\n");
			
		}
	}
	else
	{
		printf("���°� �� �� �Ǿ����ϴ�..");
	}
}

// �ܾ� ��ȸ
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