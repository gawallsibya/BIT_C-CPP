#include "std.h"
#include "Manager.h"
#include "Mylist.h"

LIST list;

void manager_init()
{
	Mylist_init(&list);
}

void Insert()
{
	int i, num;
	char arr[256];

	printf("���ڿ� �Է� : "); fflush(stdin);	gets(arr);
	
	num = strlen(arr);

	for(i = 0; i < num; i++)
	{
		mylist_push_back(&list, arr[i]);
	}

	printf("���� ���� : %d\n", list.count);
}

void Printall()
{
	NODE * cur;
	cur = list.head;

	printf("���� ���� : %d\n", list.count);
	printf("���� ��� : ");

	while(cur != NULL)
	{
		printf("%c", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

NODE * _Search(char ch)
{
	NODE * cur = list.head;
	while( cur != NULL )
	{
		if( cur->data == ch)
		{
			return cur;
		}
		cur = cur->next;
	}
	return cur;
}

void Search()
{
	NODE * cur;
	char ch;

	Printall();
	
	fflush(stdin);
	printf("�˻����� : ");
	scanf("%c", &ch);

	cur = _Search(ch);
	
	if( cur == NULL)
	{
		printf("�� ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("�˻���� = �ּҰ� : %p, ������ : %c, : ���� �ּҰ� : %p\n", 
			cur, cur->data, cur->next);
	}
}

void Modify()
{
	NODE * cur;
	char ch;

	Printall();
	printf("�빮�� �Ǵ� �ҹ��ڸ� ������ ���� : ");
	fflush(stdin);
	scanf("%c", &ch);
	cur = _Search(ch);

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
	Printall();
}

void Del()
{
	NODE * prev, * cur;
	char ch;
	prev = cur = list.head;

	Printall();
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