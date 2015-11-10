#include "manager.h"

DLIST list;

void insert()
{
	int i = 0;
	char a[MAX];
	mylist_init(&list);
	fflush(stdin);
	printf("���ڸ� �Է��Ͻÿ� : ");	gets(a);
	while(a[i] != 0)
	{
		push_back(&list,a[i]);
		//push_front(&list,a[i]);
		i++;
	}
	printf("�Է� ��� : �� %d ���� �����Ͱ� ����Ǿ����ϴ�.\n",list.count);
}

void printall()
{
	DLIST p = list;
	printf("������ ���� : %d\n",list.count);
	printf("���� ��� : ");
	while(p.head != NULL)
	{
		printf("%c",p.head->data);
		p.head = p.head->next;
	}
	printf("\n");
}
void search()
{
	DLIST p = list;
	char data;
	printall();
	fflush(stdin);
	printf("�˻� ���� : ");		scanf("%c",&data);
	while(p.head !=NULL)
	{
		if(p.head->data == data)
		{
			printf("ã�� ������ : %c, �ּ� : %d\n",p.head->data, &p.head->data);
			return;
		}
		p.head = p.head->next;
	}
	printf("�����͸� ã�� ���߽��ϴ�...\n");
}

void dele()
{
	DLIST prev, cur;
	char data;
	printall();
	fflush(stdin);
	printf("���� ���� : ");  scanf("%c",&data);
	prev = cur = list;
	if(cur.head->data == data)
	{
		list.head = cur.head->next;
		free(cur.head);
	}
	else
	{
		cur.head = cur.head->next;
		while(cur.head->data)
		{
			if(cur.head->data == data)
			{
				prev.head->next = cur.head->next;
				free(cur.head);
				return;
			}
			prev.head = prev.head->next;
			cur.head = cur.head->next;
		}
	}
}

void modify()
{
	DLIST p = list;
	char data;
	printall();
	fflush(stdin);
	printf("���� ���� : ");		scanf("%c",&data);
	while(p.head !=NULL)
	{
		if(p.head->data == data)
		{
			p.head->data -= 32;
			printf("�����Ǿ����ϴ�.\n");
			return;
		}
		p.head = p.head->next;
	}
	printf("�����͸� ã�� ���߽��ϴ�...\n");
}
 