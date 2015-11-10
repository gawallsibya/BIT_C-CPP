#include "manager.h"
#include "mylist.h"
#include "std.h"
LIST list;
NODE* CharToNode(LIST pdlist, char data)
{
	NODE *cur = pdlist.head;
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

void manager_init()
{
	mylist_init(&list);
}
void manager_insert()
{	
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	char Data[256];
	int i=0;
	printf("���� �Է� : ");		
	gets(Data);
	while(Data[i] != 0)
	{
	//	push_back(&list, Data[i]);
		push_front(&list, Data[i]);
		i++;
	}
	printf("�� %d���� �����Ͱ� ����Ǿ����ϴ�.\n",list.count);
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
void manager_Search()
{
	char Data;
	NODE *cur;
	manager_printall();
	printf("�˻����� �Է� : ");		scanf("%c" , &Data);
	fflush(stdin);
	cur = CharToNode(list, Data);
	if(cur != NULL)
	{
		printf("�˻� ��� : �ּҰ� : %p, ������ : %c, ���� �ּҰ� : %p\n",cur, cur->data, cur->next);
	}
	else
	{
		printf("��ã��..\n" ) ;	
	}
}	
void manager_Modify()
{
	char Data;
	NODE *cur;
	manager_printall();
	printf("�������� �Է� : ");		scanf("%c" , &Data);
	fflush(stdin);
	cur = CharToNode(list, Data);
	if(cur != NULL)
	{
		if(Data>64 && Data<97)
		{
			cur->data = cur->data+32;
		}
		else
		{
			cur->data	= cur->data-32;
		}
	}
	else
	{
		printf("�����͸� ã�� ���߽��ϴ�...\n");
	}
	printf("\n");
	manager_printall();
}
void manager_Dele()
{

	NODE * prev;
	NODE * cur;
	char data;
	manager_printall();
	printf("���� ���� : ");  scanf("%c", &data);
	fflush(stdin);
	cur = list.head;
	prev = cur;
	
	if(cur->data == data)
	{
		list.head = cur->next;
		list.count--;
		free(cur);
	}
	else
	{
		cur = cur->next;
		while( cur->data )
		{
			if( cur->data == data )
			{
				prev->next = cur->next;
				free(cur);
				list.count--;
				return;
			}
			prev = prev->next;
			cur = cur->next;
		}
	}

}