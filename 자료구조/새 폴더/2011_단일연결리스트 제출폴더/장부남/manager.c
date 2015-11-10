#include "std.h"
#include "manager.h"
void push_front()
{
	int i;
	printf("���ڸ� �Է� �ּ���:");
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
	printf("����:%d",list.count);
	printf("\n");
	system("pause");
}

void search()
{
	NODE *cur;
	char ch;
	printall();
	printf("�˻� ����:");
	fflush(stdin);
	scanf("%c",&ch);
	cur = find(ch);
	if (cur == NULL)
	{
		printf("��ã�Ҵ�..\n");
	}
	else
	{
		printf("ã�Ҵ�..:%c\n",cur->data);
	}
	system("pause");
}
void change()
{
	NODE *cur;
	char ch,CH;
	printall();
	printf("���� & ���� ����:");
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
		printf("�d�� ���� �� �����ϴ�...\n");
	}
	system("pause");
}
void dele()
{
	NODE *prev, *cur;char ch;
	prev = cur = list.head;
	
	printall();
	printf("���� ����:");
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