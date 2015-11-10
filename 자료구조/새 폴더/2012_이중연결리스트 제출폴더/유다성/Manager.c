#include "Manager.h"
#include "std.h"

LIST list;

void Manager_init()
{
	Mylist_init(&list);
}

void Manager_Insert()
{
	int i;

	char arr[256];

	printf("문자 입력 : ");
	fflush(stdin);
	gets(arr);

	for(i = 0; i < (int)strlen(arr); i++)
	{
		Mylist_push_back(&list, arr[i]);		
	}
	printf("입력 결과 : 총 %d개의 문자가 리스트에 저장되었습니다.\n", list.count);
}

void Manager_printall()
{
	NODE *cur = list.head;
	printf("문자 갯수 : %d\n", list.count);
	printf("문자 출력 : ");
	while(cur != NULL)
	{
		printf("%c", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void Manager_search()
{
	char arr;
	NODE *cur;
	Manager_printall();
	printf("문자 입력 : ");
	fflush(stdin);
	scanf("%c", &arr);
	cur = CharToNode(arr);
	if(cur == NULL)
	{
		printf("찾지 못했습니다.\n");
	}
	else
	{
		printf("검색 결과 : 주소값 : %d, 데이터 : %c, 다음 노드의 주소값 : %d\n", &cur->data, cur->data, &cur->next);	
	}
}

void Manager_modify()
{
	char arr;
	NODE *cur;
	Manager_printall();
	printf("문자 입력 : ");
	fflush(stdin);
	scanf("%c", &arr);
	cur = CharToNode(arr);
	if(cur == NULL)
	{
		printf("찾지 못했습니다.\n");
		return;
	}
	else
	{
		if(cur->data >= 'A' && cur->data <= 'Z')
		{
			cur->data += 32; 
		}
		else if(cur->data >= 'a' && cur->data <= 'z')
		{
			cur->data -= 32;
		}
	}
	printf("수정 후...\n");
	Manager_printall();
}

void Manager_dele()
{
	char arr;
	NODE *cur;
	Manager_printall();
	printf("문자 입력 : ");
	fflush(stdin);
	scanf("%c", &arr);
	cur = CharToNode(arr);
	if(cur == NULL)
	{
		printf("찾지 못했습니다.\n");
		return;
	}
	else
	{
		NODE *prev;
		prev = cur->prev;
		if(cur == list.head)
		{
			list.head = cur->next;
		}
		else if(cur == list.tail)
		{
			prev->next = NULL;
			list.tail = prev;
		}
		else
		{
			prev->next = cur->next;
			cur->next->prev = prev;
		}
		free(cur);
		list.count--;
		printf("삭제 후...\n");
		Manager_printall();
	}
}

NODE* CharToNode(char arr)
{
	int i;
	NODE *cur = list.head;
	for(i = 0; i < list.count; i++)
	{
		if(cur->data == arr)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

