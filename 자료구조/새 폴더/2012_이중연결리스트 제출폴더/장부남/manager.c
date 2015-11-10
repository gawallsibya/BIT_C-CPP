#include "manager.h"

LIST list;
void manager_myinit()
{
	mylist_init(&list);
}

void insert()
{
	int i = 0;
	char a[MAX];

	printf("���� �Է� : ");		gets(a);
	while(a[i] != 0)
	{
		push_back(&list,a[i]);
//		push_front(&list,a[i]);
		i++;
	}
	printf("�Է� ��� : �� %d���� �����Ͱ� ����Ǿ����ϴ�.\n",list.count);		
}

void printall()
{
	NODE * cur = list.head;
	printf("������ ���� : %d\n",list.count);
	printf("���� ��� : ");
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

void search()
{
	char data;
	NODE * cur;
	printall();
	printf("�˻� ���� : ");		scanf("%c",&data);

	fflush(stdin);
	cur = charToNODE(list, data);

	if(cur != NULL)
	{
		printf("�˻� ��� : �ּҰ� : %p, ������ : %c, ���� �ּҰ� : %p\n",cur, cur->data, cur->next);
	}
	else
	{
		printf("�����Ͱ� �����ϴ�..\n");
	
	}
}
void dele()
{
	NODE * cur;
	char data;
	printall();
	printf("���� ���� : ");  scanf("%c",&data);
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
		printf("�����Ͱ� �����ϴ�...\n");
	}

}

void modify()
{
	char data;
	NODE * cur;
	printall();
	printf("�������� : ");		scanf("%c",&data);
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
		printf("�����Ͱ� �����ϴ�.\n");
	}

	printf("\n");
	printall();

}
 