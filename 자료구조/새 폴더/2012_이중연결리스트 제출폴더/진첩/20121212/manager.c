#include"mylist.h"
#include"manager.h"
#include "std.h"
DLIST dlist;
void manager_init()
{
	dlist.head=NULL;
	dlist.tail=NULL;
	dlist.count=0;
	
}
void manager_insert()
{
	int idx;int num;
	printf("[insert]\n");
	printf("�����Է��ϼ��� \n");
	fflush(stdin);
	gets(arr);
	 num=strlen(arr);
	for(idx=0;idx<num;idx++)
	{
		//List_push_front(&dlist,arr[idx]);
		List_push_back(&dlist,arr[idx]);
	}
	printf("�Է°��: �� %d���� ���ڸ� �Է��ϼ̽��ϴ�.\n",dlist.count);

	
}
void manager_printall()
{
	NODE * cur=dlist.head;
	printf("[printall]\n");
	printf("�Է°��: �� %d���� ���ڸ� �Է��ϼ̽��ϴ�.\n",dlist.count);
	while(cur!=NULL)
	{
		printf("%c",cur->data);
		cur=cur->next;
	}
	printf("\n");
}
NODE * CharToNode(NODE *p, char ch)
{
	NODE *cur=p;
	while(cur!=NULL)
	{
		if(cur->data==ch)
			return cur;
		else
			cur=cur->next;
	}
	return NULL;
}
void manager_search()
{
	char ch;
	NODE *cur ;
	printf("[search]\n");
	printf("�˻��� ����  �Է��ϼ���\n");
	fflush(stdin);
	ch=getchar();
	cur = CharToNode(dlist.head, ch);
	if( cur != NULL)
	{
		printf("ã�Ҵ�. : %c\n", cur->data);
	}
	else
	{
		printf("��ã�Ҵ�...\n");
	}
}
void manager_update()
{
	char ch;
	NODE *cur ;
	printf("[update]\n");
	printf("������ ���� �Է��ϼ��� \n");
	fflush(stdin);
	ch=getchar();
	cur = CharToNode(dlist.head, ch);
	if( cur != NULL)
	{
		printf("���������ƽ��ϴ�.\n");
		if(cur->data>='a'&&cur->data<='z')
			cur->data=cur->data-32;
		else
			cur->data=cur->data+32;
	}
	else
	{
		printf("��ã�Ҵ�...\n");
	}
}
void manager_delete()
{
	NODE *cur ;char ch;
	printf("[delete]\n");
	printf("������ ����  �Է��ϼ���\n");
	fflush(stdin);
	ch=getchar();
	cur=CharToNode(dlist.head, ch);
	if( cur == NULL)
	{
		printf("��ã�ҵ�...\n");
	}
	else
	{
		NODE *del, *prev;
		del		= cur;
		prev	= cur->prev;

		if( cur == dlist.head)
		{
			dlist.head = cur->next;
		}
		else if( cur == dlist.tail)
		{
			prev->next		= NULL;
			dlist.tail	= prev;
		}
		else
		{
		prev->next		= del->next;
		del->next->prev	= prev;
		}
		printf("���������ƽ��ϴ�\n");
		free(del);
		dlist.count--;
	}
}