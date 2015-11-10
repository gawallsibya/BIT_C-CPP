#include "Manager.h"
#include "std.h"

LIST list;	//������ �ʱ�ȭ�� �׻� �ҽ����Ͽ��� �ؾ� �Ѵ�.

void Manager_myinit()
{
	mylist_init(&list);
}

void Manager_Insert()	//push_back
{
	int i = 0;
	char a[MAX];
	fflush(stdin);
	printf("���� �Է� : ");		
	gets(a);
	fflush(stdin);
	while(a[i] != 0)
	{
		push_back(&list,a[i]);
//		push_front(&list,a[i]);
		i++;
	}
	printf("�Է� ��� : �� %d���� �����Ͱ� ����Ǿ����ϴ�.\n",list.count);
	fflush(stdin);
}
void Manager_PrintAll()
{
	NODE * cur = list.head;
	printf("������ ���� : %d\n",list.count);
	fflush(stdin);
	printf("���� ��� : ");
	fflush(stdin);
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
void Manager_Search()
{
	char data;
	NODE * cur;
	
	Manager_PrintAll();
	printf("�˻� ���� : ");		
	scanf("%c",&data);
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
void Manager_Modify()
{
	char data;
	NODE * cur;
	
	Manager_PrintAll();
	printf("�������� : ");		
	scanf("%c",&data);
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
	Manager_PrintAll();
}
void Manager_Erase()
{
	NODE * cur;
	char data;
	
	Manager_PrintAll();
	printf("���� ���� : ");  
	scanf("%c",&data);
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
//NODE* find(char ch)
//{
//	NODE *cur;
//	cur = list.head;
//	while(cur->next != NULL )
//	{
//		if (cur->data == ch)
//		{
//			return cur; //���� 
//		}
//		cur = cur->next;
//	}
//	return NULL;
//}