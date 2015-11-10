#include "manager.h"

LIST list;
void manager_myinit()
{
	mylist_init(&list);
}
void manager_insert()
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

void manager_printall()
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

void manager_search()
{
	char data;
	NODE * cur;
	manager_printall();
	printf("�˻� ���� : ");		scanf("%c",&data);

	fflush(stdin);
	cur = charToNODE(list, data);

	if(cur != NULL)
	{
		printf("�˻� ��� : �ּҰ� : %p, ������ : %c, ���� �ּҰ� : %p\n",cur, cur->data, cur->next);
	}
	else
	{
		printf("�����͸� ã�� ���߽��ϴ�...\n");
	}
	
}

void manager_dele()
{
	NODE * prev;
	NODE * cur;
	char data;
	manager_printall();
	printf("���� ���� : ");  scanf("%c",&data);
	fflush(stdin);
	prev = cur = list.head;
	if(cur->data == data)
	{
		list.head = cur->next;
		list.count--;
		free(cur);
	}
	else
	{
		cur = cur->next;
		while(cur != NULL)
		{
			if(cur->data == data)
			{
				prev->next = cur->next;
				free(cur);
				list.count--;
				return;
			}
			prev = prev->next;
			cur = cur->next;
		}
		printf("�����Ͱ� �����ϴ�...\n");
	}

}

void manager_modify()
{
	char data;
	NODE * cur;
	manager_printall();
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
		printf("�����͸� ã�� ���߽��ϴ�...\n");
	}

	printf("\n");
	manager_printall();

}
 