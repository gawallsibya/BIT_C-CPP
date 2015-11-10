#include "Manager.h"
#include "std.h"

LIST list;

void Manager_init()
{
	Mylist_init(&list);
}

void Manager_Insert()
{
	int i;

	char arr[256];

	printf("���� �Է� : ");
	fflush(stdin);
	gets(arr);

	for(i = 0; i < (int)strlen(arr); i++)
	{
		Mylist_push_back(&list, arr[i]);		
	}
	printf("�Է� ��� : �� %d���� ���ڰ� ����Ʈ�� ����Ǿ����ϴ�.\n", list.count);
}

void Manager_printall()
{
	NODE *cur = list.head;
	printf("���� ���� : %d\n", list.count);
	printf("���� ��� : ");
	while(cur != NULL)
	{
		printf("%c", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void Manager_search()
{
	char arr;
	NODE *cur;
	Manager_printall();
	printf("���� �Է� : ");
	fflush(stdin);
	scanf("%c", &arr);
	cur = CharToNode(arr);
	if(cur == NULL)
	{
		printf("ã�� ���߽��ϴ�.\n");
	}
	else
	{
		printf("�˻� ��� : �ּҰ� : %d, ������ : %c, ���� ����� �ּҰ� : %d\n", &cur->data, cur->data, &cur->next);	
	}
}

void Manager_modify()
{
	char arr;
	NODE *cur;
	Manager_printall();
	printf("���� �Է� : ");
	fflush(stdin);
	scanf("%c", &arr);
	cur = CharToNode(arr);
	if(cur == NULL)
	{
		printf("ã�� ���߽��ϴ�.\n");
		return;
	}
	else
	{
		if(cur->data >= 'A' && cur->data <= 'Z')
		{
			cur->data += 32; 
		}
		else if(cur->data >= 'a' && cur->data <= 'z')
		{
			cur->data -= 32;
		}
	}
	printf("���� ��...\n");
	Manager_printall();
}

void Manager_dele()
{
	char arr;
	NODE *cur;
	Manager_printall();
	printf("���� �Է� : ");
	fflush(stdin);
	scanf("%c", &arr);
	cur = CharToNode(arr);
	if(cur == NULL)
	{
		printf("ã�� ���߽��ϴ�.\n");
		return;
	}
	else
	{
		NODE *prev;
		prev = cur->prev;
		if(cur == list.head)
		{
			list.head = cur->next;
		}
		else if(cur == list.tail)
		{
			prev->next = NULL;
			list.tail = prev;
		}
		else
		{
			prev->next = cur->next;
			cur->next->prev = prev;
		}
		free(cur);
		list.count--;
		printf("���� ��...\n");
		Manager_printall();
	}
}

NODE* CharToNode(char arr)
{
	int i;
	NODE *cur = list.head;
	for(i = 0; i < list.count; i++)
	{
		if(cur->data == arr)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

