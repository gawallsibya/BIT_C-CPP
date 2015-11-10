#include "manager.h"
LIST list;
NODE* CharToNode(LIST pdlist, char data)
{
	NODE *cur = pdlist.head;
	while(cur != NULL)
	{
		if(cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void manager_init()
{
	mylist_init(&list);
}
void manager_insert()
{	
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	char Data[256];
	int i=0;
	printf("문자 입력 : ");	
	gets(Data);
	
	while(Data[i] != 0)
	{
		push_back(&list, Data[i]);
	//	push_front(&list, Data[i]);
		i++;
	}
	printf("총 %d개의 데이터가 저장되었습니다.\n",list.count);
}
void manager_printall()
{
	NODE *cur = list.head;
	printf("문자의 개수 : %d\n",list.count);
	printf("문자 출력 : ");
	while(cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void manager_Search()
{
	char Data;
	NODE *cur;
	manager_printall();
	printf("검색문자 입력 : ");		

	scanf("%c" , &Data);
	fflush(stdin);
	cur = CharToNode(list, Data);
	if(cur != NULL)
	{
		printf("검색 결과 : 주소값 : %p, 데이터 : %c, 다음 주소값 : %p\n",cur, cur->data, cur->next);
	}
	else
	{
		printf("못찾음..\n" ) ;	
	}
}	
void manager_Modify()
{
	char Data;
	NODE *cur;
	manager_printall();
	printf("수정문자 입력 : ");		

	scanf("%c" , &Data);
	fflush(stdin);	
	cur = CharToNode(list, Data);
	if(cur != NULL)
	{
		if(Data>64 && Data<97)
		{
			cur->data = cur->data+32;
		}
		else
		{
			cur->data	= cur->data-32;
		}
	}
	else
	{
		printf("데이터를 찾지 못했습니다...\n");
	}
	printf("\n");
	manager_printall();
}
void manager_Dele()
{
	NODE * cur;
	char Data;
	manager_printall();
	printf("삭제 문자 : ");  scanf("%c", &Data);
	fflush(stdin);
	cur = CharToNode(list, Data);
	if(cur != NULL)
	{
		NODE *del;
		NODE *prev;
		del = cur;
		prev = cur->prev;
		if(cur == list.head)
		{
			list.head = del->next;
		
		}
		else if(cur == list.tail)
		{
			prev->next = NULL;
			list.tail = prev;
			
		}
		else
		{
			prev->next = del->next;
			del->next->prev = prev;
			
		}
		free(del);
		list.count--;
	}
	else
	{
		printf("데이터가 없습니다...\n");
	}
}