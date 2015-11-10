#include "std.h"
#include "manager.h"

void init()
{
	List *list = (List*)malloc(sizeof(List));
	list->head=NULL;
	list->tail=NULL;
	list->count =0;
}
void insert()
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
			list.tail = newnode;
			list.count++;
		}
		else
		{
			newnode->next = list.head;
			list.head->prev = newnode;
			list.head=newnode;
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
	printf("\n������? %d",list.count);
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
	cur = find(list.head, ch);


	if (cur == NULL)
	{
		printf("�����Ͱ� �����ϴ�..\n");
	}
	else
	{
		printf("ã�� ����:%c, �ּ� : %d\n",cur->data, &cur->data);
	}
	system("pause");
}

void modify()
{
	NODE *cur;
	char ch;

	printall();

	printf("������ ����:");
	fflush(stdin);
	scanf("%c",&ch);

	cur = find(list.head, ch);
	fflush(stdin);

	if ('a'<=ch&&ch<='z')
	{
		cur->data = ch-32;
	}

	else if('A'<=ch&&ch<='Z')
	{
		cur->data = ch+32;
	}

	else
	{
		printf("�ش� ���ڰ� �����ϴ�...\n");
	}system("pause");
		printall();

}
void dele()
{
	
	NODE *cur;

	char ch;
	printall();
	printf("���� ����:");
	fflush(stdin);
	scanf("%c", &ch);

	cur = find(list.head, ch);
	if( cur == NULL)
	{
		printf("��ã�Ҿ��~...\n");
	}
	else
	{
		NODE *del, *prev;
		del		= cur;
		prev	= cur->prev;

		if( cur == list.head)
		{
			list.head = cur->next;
		}
		else if( cur == list.tail)
		{
			prev->next		= NULL;
			list.tail	= prev;
		}
		else
		{
		prev->next		= del->next;
		del->next->prev	= prev;
		}

		free(del);
		list.count--;
	}

		printall();

}

NODE* find(NODE *start, char ch)
{
	NODE *cur;
	cur = list.head;

	while(cur != NULL )
	{
		if (cur->data == ch)
		{
			return cur;
		}
		
		cur = cur->next;
	}
	
	return NULL;
}