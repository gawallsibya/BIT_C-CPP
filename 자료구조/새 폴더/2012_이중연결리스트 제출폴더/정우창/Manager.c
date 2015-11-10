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

	printf("���ڿ� �Է��Ͻÿ�. : "); fflush(stdin);	gets(arr);
	
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

NODE * _Search(NODE * start, char ch)
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
	printf("�˻��� ���ϴ� ���ڸ� �Է��Ͻÿ�. : ");
	scanf("%c", &ch);

	cur = _Search(list.head, ch);
	
	if( cur == NULL)
	{
		printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
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
	printf("�빮�� �Ǵ� �ҹ��ڸ� ������ ���ڸ� �Է��Ͻÿ�. : ");
	fflush(stdin);
	scanf("%c", &ch);
	cur = _Search(list.head, ch);

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
	char ch;
	NODE * cur;

	fflush(stdin);
	Printall();
	printf("������ ���ϴ� ���ڸ� �Է��Ͻÿ�. : ");
	scanf("%c", &ch);

	cur = _Search(list.head, ch);
	if( cur == NULL)
	{
		printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
	}
	else
	{
		NODE *_cur, *prev;
		_cur	= cur;
		prev	= cur->prev;

		if(cur == list.head)
		{
			list.head = cur->next;
		}
		else if(cur == list.tail)
		{
			prev->next	= NULL;
			list.tail	= prev;
		}
		else
		{
			prev->next		= _cur->next;
			_cur->next->prev	= prev;
		}

		free(_cur);
		list.count--;
	}
}