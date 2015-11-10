#include "manager.h"
#include "std.h"

LIST list;

void manager_init()
{
	mylist_init(&list);
}

void manager_insert()
{
	int i;
	char arr[MAX];
	int num;
	
	printf("���� �Է� : ");	fflush(stdin);	gets(arr);
	
	num = strlen(arr);

	for(i=0; i<num; i++)
	{
		mylist_push_back(&list, arr[i]);
	}
	printf("���� �Ϸ�\n");
}

NODE * _search(char ch)
{
	NODE * cur = list.head;
	while(cur != NULL)
	{
		if(cur->data == ch)
		{
			return cur;
		}
		cur = cur->next;
	}
	return cur;
}

void manager_search()
{
	NODE * cur;
	char ch;

	manager_printall();
	
	fflush(stdin);
	printf("�˻����� : ");
	scanf("%c", &ch);

	cur = _search(ch);
	
	if( cur == NULL)
	{
		printf("��ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("�˻����\n�ּҰ� : %p, ������ : %c, : ���� �ּҰ� : %p\n", cur, cur->data, cur->next);
	}
}

void manager_modify()
{
	NODE * cur;
	char ch;

	manager_printall();
	printf("�빮�� �Ǵ� �ҹ��ڷ� ������ ���� : ");
	fflush(stdin);
	scanf("%c", &ch);
	cur = _search(ch);

	if(cur == NULL)
	{
		printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
		return;
	}
	else
	{
		if(cur->data >= 'a' && cur->data <= 'z')
			cur->data -= 32;
		else if(cur->data >= 'A' && cur->data <= 'Z')
			cur->data += 32;
	}
	printf("\n");
	manager_printall();
}

void manager_del()
{
	NODE * prev;
	NODE * cur;
	char ch;
	prev = list.head;
	cur = list.head;

	manager_printall();
	printf("�����ϰ� ���� ���� : ");
	fflush(stdin);
	scanf("%c", &ch);

	if( cur->data == ch)
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
			if( cur->data == ch)
			{
				prev->next = cur->next;
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

void manager_printall()
{
	NODE * cur;
	cur = list.head;

	printf("���� ���� ���� : %d\n", list.count);
	printf("���� ��� : ");

	while(cur != NULL)
	{
		printf("%c", cur->data);
		cur = cur->next;
	}
	printf("\n");
}