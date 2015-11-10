#include "std.h"
#include "manager.h"

LIST list;		//...............

void manager_myinit()
{
	mylist_init(&list);
}

void manager_insert()
{
	int i = 0;
	char a[MAX];
	mylist_init(&list);
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
	NODE *cur = list.head;

	printf("������ ���� : %d\n",list.count);
	printf("���� ��� : ");
	
	while(cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

NODE *charToNode(LIST list, char data)
{
	NODE *cur = list.head;
	while( cur != NULL)
	{
		if( cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


void manager_search()
{
	char data;
	NODE *cur;
	manager_printall();

	printf("�˻� ���� : ");		scanf("%c",&data);
	fflush(stdin);

	cur = charToNode(list, data);
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
	LIST prev, cur;
	char data;
	manager_printall();
	printf("���� ���� : ");  scanf("%c",&data);
	fflush(stdin);

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


void manager_modify()
{
	char data;

	NODE *cur;
	
	manager_printall();
	printf("�������� : ");		scanf("%c",&data);
	fflush(stdin);

	cur = charToNode(list, data);
	if( cur != NULL)
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
		printf("�����Ͱ� ����..\n");
	}

	printf("\n");
	manager_printall();
}
 