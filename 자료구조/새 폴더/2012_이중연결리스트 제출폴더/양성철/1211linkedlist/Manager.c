#include "Manager.h"
#include "std.h"

LIST list;	//변수의 초기화는 항상 소스파일에서 해야 한다.

void Manager_myinit()
{
	mylist_init(&list);
}

void Manager_Insert()	//push_back
{
	int i = 0;
	char a[MAX];
	fflush(stdin);
	printf("문자 입력 : ");		
	gets(a);
	fflush(stdin);
	while(a[i] != 0)
	{
		push_back(&list,a[i]);
//		push_front(&list,a[i]);
		i++;
	}
	printf("입력 결과 : 총 %d개의 데이터가 저장되었습니다.\n",list.count);
	fflush(stdin);
}
void Manager_PrintAll()
{
	NODE * cur = list.head;
	printf("문자의 개수 : %d\n",list.count);
	fflush(stdin);
	printf("문자 출력 : ");
	fflush(stdin);
	while(cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");	
}
NODE* charToNODE(LIST list, char data)
{
	NODE * cur = list.head;
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
void Manager_Search()
{
	char data;
	NODE * cur;
	
	Manager_PrintAll();
	printf("검색 문자 : ");		
	scanf("%c",&data);
	fflush(stdin);

	cur = charToNODE(list, data);

	if(cur != NULL)
	{
		printf("검색 결과 : 주소값 : %p, 데이터 : %c, 다음 주소값 : %p\n",cur, cur->data, cur->next);
	}
	else
	{
		printf("데이터가 없습니다..\n");
	
	}
}
void Manager_Modify()
{
	char data;
	NODE * cur;
	
	Manager_PrintAll();
	printf("수정문자 : ");		
	scanf("%c",&data);
	fflush(stdin);

	cur = charToNODE(list, data);
	if(cur != NULL)
	{
		if('a'<= cur->data && cur->data <= 'z')
		{
			cur->data -= 32; 
		}

		else //if('A'<= p.head->data && p.head->data <= 'Z')
		{
			cur->data += 32;
		}
	}
	else
	{
		printf("데이터가 없습니다.\n");
	}

	printf("\n");
	Manager_PrintAll();
}
void Manager_Erase()
{
	NODE * cur;
	char data;
	
	Manager_PrintAll();
	printf("삭제 문자 : ");  
	scanf("%c",&data);
	fflush(stdin);

	cur = charToNODE(list, data);

	if(cur != NULL)
	{
		NODE *del, *prev;
		del = cur;
		prev = cur->prev;
		if(del == list.head)
		{
			list.head = del->next;
			free(del);
		}
		else if(del == list.tail)
		{
			prev->next = NULL;
			list.tail = prev;
			free(del);
		}
		else
		{
			prev->next = del->next;
			del->next->prev = prev;
			free(del);
		}
		list.count--;
	}
	else
	{
		printf("데이터가 없습니다...\n");
	}
}
//NODE* find(char ch)
//{
//	NODE *cur;
//	cur = list.head;
//	while(cur->next != NULL )
//	{
//		if (cur->data == ch)
//		{
//			return cur; //주의 
//		}
//		cur = cur->next;
//	}
//	return NULL;
//}