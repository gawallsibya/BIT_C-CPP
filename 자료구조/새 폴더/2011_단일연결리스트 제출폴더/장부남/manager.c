#include "std.h"
#include "manager.h"
void push_front()
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
void printall()
{
	NODE *cur;
	cur = list.head;
	while (cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("개수:%d",list.count);
	printf("\n");
	system("pause");
}

void search()
{
	NODE *cur;
	char ch;
	printall();
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
	system("pause");
}
void change()
{
	NODE *cur;
	char ch,CH;
	printall();
	printf("문자 & 수정 문자:");
	fflush(stdin);
	scanf("%c%c",&ch,&CH);
	cur = find(ch);
	fflush(stdin);
	if (cur != NULL)
	{
		cur->data = CH;
	}
	else
	{
		printf("햏당 파일 중 없습니다...\n");
	}
	system("pause");
}
void dele()
{
	NODE *prev, *cur;char ch;
	prev = cur = list.head;
	
	printall();
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
		cur = cur->next;
		while( cur != NULL)
		{
			if( cur->data == ch)
			{
				prev->next	= cur->next;
				list.count--;
				free(cur);
				return;
			}
			else
			{
				cur = cur->next;
				prev = prev->next;
			}
		}
	}
}

NODE* find(char ch)
{
	NODE *cur;
	cur = list.head;
	while(cur->next != NULL )
	{
		if (cur->data == ch)
		{
			return cur; 
		}
		cur = cur->next;
	}
	return NULL;
}