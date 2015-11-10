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
	printf("���ڸ� �Է� �ּ���:");
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
	printf("\t�Էµ� ���ڴ� :");
	printf("%d",list.count);
	printf("\n");
	system("pause");
}

NODE *IntToNODE(NODE *start,char data)//Search����ϱ����� (���ڸ� �ѱ�� ��带 �ް�...a)
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
	printall();		printf("�˻� ����:");
	scanf("%c",&ch);
	
	cur = IntToNODE(cur,ch);
	if (cur == NULL)
	{
		printf("��ã�Ҵ�..\n");
	}
	else
	{
		printf("ã�Ҵ�..:%c\n",cur->data);
	}

}
void change()
{
	NODE *cur;

	char ch,CH;
	printall();

	printf("����, ���� ����:");
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
		printf("�ش� ���� �� �����ϴ�...\n");
	}
	system("pause");
}
void dele()
{

	NODE *prev, *cur;	char ch;
	prev = cur = list.head;
	
	printall();
	printf("������ ����:");

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
