#include "std.h"
#include "manager.h"
void manager_init()
{
	list.head = NULL;
	list.count = 0;
}
void manager_push_front()
{
	int i;
	printf("문자를 입력 주세요:");
	fflush(stdin);
	gets(arr);
	for(i = 0;arr[i] != '\0'; i++)
	{
		NODE *newnode = (NODE*)malloc(sizeof(NODE)); 

		newnode->data = arr[i];
		newnode->next = NULL;
		if(list.head == NULL)
		{
			list.head = newnode;
			list.count++;
		}
		else
		{
			newnode->next = list.head;
			list.head = newnode;
			list.count++;
		}
	}
}
void manager_printall()
{
	NODE *cur;
	cur = list.head;
	while (cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");
	printf("개수:%d",list.count);
	printf("\n");

}

void manager_search()
{
	if(list.count == 0)
	{
		printf("개수:0\n");
		printf("삽입 해 주세요...\n");
		return;
	}
	else
	{
		NODE *cur;
		char ch;
		manager_printall();
		printf("검색 문자:");
		fflush(stdin);
		scanf("%c",&ch);
		cur = find(ch);
		if (cur == NULL)
		{
			printf("못찾았다..\n");
		}
		else
		{
			printf("찾았다..:%c\n",cur->data);
		}
	}
}
void manager_change()
{
	if(list.count == 0)
	{
		printf("개수:0\n");
		printf("삽입 해 주세요...\n");
		return;
	}
	else
	{
		NODE *cur;
		char ch,CH;
		manager_printall();
		printf("문자 & 수정 문자:");
		fflush(stdin);
		scanf("%c%c",&ch,&CH);//주의
		cur = find(ch);
		fflush(stdin);
		if (cur != NULL)
		{
			cur->data = CH;
		}
		else
		{
			printf("해당 파일 중 없습니다...\n");
		}
	}
}
void manager_dele()
{
	if(list.count == 0)
	{
		printf("개수:0\n");
		printf("삽입 해 주세요...\n");
		return;
	}
	else
	{
		NODE *cur,*p;char ch;
		cur = list.head;
		
		manager_printall();
		printf("삭제 문자:");
		fflush(stdin);
		scanf("%c",&ch);
		if( cur->data == ch)
		{
			list.head = cur->next;
			list.count--;
			free(cur);
		}
		else
		{
			//cur = cur->next;
			while( cur != NULL)
			{
				p = cur->next;
				if( p->data == ch)
				{
					cur->next=p->next;
					free(p);
					list.count--;
					return;
				}
				else
				{
					cur = cur->next;
				}
			}
		}
	}
}

NODE* find(char ch)
{
	NODE *cur;
	cur = list.head;
	while(cur != NULL )
	{
		if (cur->data == ch)
		{
			return cur; //주의 
		}
		cur = cur->next;
	}
	return NULL;
}