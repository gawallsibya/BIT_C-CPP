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
	NODE *prev, *cur;
	Manager_printall();
	printf("���� �Է� : ");
	fflush(stdin);
	scanf("%c", &arr);
	prev = cur = list.head;
	if( cur->data == arr)
	{
		list.head = cur->next;
		free(cur);
		printf("���� ��...\n");
		list.count--;
		Manager_printall();
		return;
	}
	else
	{
		cur = cur->next;
		while( cur != NULL)
		{
			if( cur->data == arr)
			{
				prev->next	= cur->next;
				free(cur);
				printf("���� ��...\n");
				list.count--;
				Manager_printall();
		
				return;
			}
			else
			{
				cur = cur->next;
				prev = prev->next;
			}
		}
	}
	printf("ã�� ���߽��ϴ�\n");
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

