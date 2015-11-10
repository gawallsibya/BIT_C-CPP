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


// ����
void ma_reserve()
{
	int i;
	
	Member *res = (Member*)malloc(sizeof(Member)); 
	arr_info(&g_arr);
	
	while(1)
	{
		printf("����ż� �Է�: ");		scanf("%d",&res->count);
		if(res->count > 0 && res->count < 6)
			break;
		else
			printf("���Է�...\n");
	}
	for(i=0; i < res->count; i++)
	{
		printf("�¼� �Է� : ");		scanf("%d",&res->seat[i]);
		if(g_arr.data[res->seat[i]-1] != NULL)
		{
			printf("���Է�...\n");
			i -= 1;
			continue;
		}
	}
	fflush(stdin);
	printf("��ȭ��ȣ �Է� : ");		gets(res->phone);
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
	printf("������ �Ϸ� �Ǿ����ϴ�..\n");
	printf("�����ȣ: %s\n",res->number); 
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
	printf("[1] ��ȭ��ȣ [2] ���� ��ȣ\n");
	
	while(1)
	{
		scanf("%d",&num);
		if(num==1)
		{
			printf("��ȭ��ȣ �Է�: "); 
			fflush(stdin);
			gets(num1);
			cur=list_search(&g_list,num1);
			break;
		}
		else if(num==2)
		{
			printf("�����ȣ �Է�: "); 
			fflush(stdin);
			gets(num1);
			cur=list_search(&g_list,num1);
			break;
		}
		else
		{
			printf("�ٽ� �Է��ϼ���..\n");
			continue;
		}
	}
	if(cur != NULL)
		list_print(cur);
	else
	{
		printf("���������� ã���� ����..\n");
		return;
	}
}

//���
void ma_cancel()
{
	int num,i;
	char ch;
	char num1[20];
	Member* cur;
	printf("[1] ��ȭ��ȣ [2] ���� ��ȣ\n");
	
	while(1)
	{
		scanf("%d",&num);
		if(num==1)
		{
			printf("��ȭ��ȣ �Է�: "); 
			fflush(stdin);
			gets(num1);
			cur=list_search(&g_list,num1);
			break;
		}
		else if(num==2)
		{
			printf("�����ȣ �Է�: "); 
			fflush(stdin);
			gets(num1);
			cur=list_search(&g_list,num1);
			break;
		}
		else
		{
			printf("�ٽ� �Է��ϼ���..\n");
			continue;
		}
	}
	if(cur != NULL)
		list_print(cur);
	else
	{
		printf("���������� ã���� ����..\n");
		return;
	}
	printf("\n�� ������ ����ұ��? : (y, n)");	
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
// �ܾ� ��ȸ
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