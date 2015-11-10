#include "std.h"
#include "manager.h"
void init(LIST *plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->count = 0;
}
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
		newnode->prev = NULL;

	if(list.head == NULL)
		{
			list.head = newnode;
			list.tail = newnode;
			list.count++;
		}
		else
		{
			newnode->prev = list.tail;
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
	printf("\t입력된 숫자는 :");
	printf("%d",list.count);
	printf("\n");
	system("pause");
}

NODE *IntToNODE(NODE *start,char data)//Search사용하기위해 (숫자를 넘기면 노드를 받게...a)
{
	NODE *cur = start; 

	while(cur != NULL)
	{
		if(cur->data == data)
		return cur;
	}
	return NULL;
}

void search()
{
	NODE *cur; char ch;
	cur = list.head;
	printall();		printf("검색 문자:");
	scanf("%c",&ch);
	
	cur = IntToNODE(cur,ch);
	if (cur == NULL)
	{
		printf("못찾았다..\n");
	}
	else
	{
		printf("찾았다..:%c\n",cur->data);
	}

}
void change()
{
	NODE *cur;

	char ch,CH;
	printall();

	printf("문자, 수정 문자:");
	scanf("%c%c",&ch,&CH);

	cur = list.head;
	cur = IntToNODE(cur,ch);

	fflush(stdin);
	if (cur != NULL)
	{
		cur->data = CH;
	}
	else
	{
		printf("해당 파일 중 없습니다...\n");
	}
	system("pause");
}
void dele()
{

	NODE *prev, *cur;	char ch;
	prev = cur = list.head;
	
	printall();
	printf("삭제할 문자:");

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
