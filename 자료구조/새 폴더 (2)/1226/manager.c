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


Member* numtores(List *plist, int id)
{
	int i;
	Node* cur=plist->head;
	while(cur != NULL)
	{
		for(i=0; i< cur->data->count; i++)
		{
			if(cur->data->seat[i] == id)
			return cur->data;
		}
		cur=cur->next;
	}
	return NULL;
}


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

//취소
void ma_cancel()
{
	int num,i;
	char ch;
	char num1[20];
	Member* cur;
//	Arr* del;
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
		
		for(i=0; i < cur->count ;i++)
		g_arr.data[cur->seat[i]-1]=NULL;
		free(cur);
	}
	else
	return;
}

// 조회
void ma_info()
{
	int num;
	Member* cur;
	while(1)
	{
		printf("원하는 좌석을 입력하시오..(0을 입력시 종료)");
		scanf("%d",&num);
		if(num==0)
		return;
		cur = numtores(&g_list,num);
		if(cur==NULL)
		printf("예약되지 않음...\n");
		else
		list_print(cur);
	}
}

