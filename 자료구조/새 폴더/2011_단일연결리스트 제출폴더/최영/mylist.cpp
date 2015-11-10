#include "mylist.h"
#include "std.h"

void List_init(List* p)
{
	p->head=NULL;
	p->count=0;
}
void List_push_back(List* p,char ch)
{
	Node** start=&p->head;
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=ch;
	newnode->next=NULL;
	if( *start == NULL)
	{
		*start		= newnode;
	}
	else
	{
		Node *cur = *start;
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	p->count++;
}
void List_push_front(List* p,char ch)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=ch;
	newnode->next=NULL;
	if(p->head ==NULL)
	{
		p->head		= newnode;
	}
	else
	{
		newnode->next= p->head;
		p->head=newnode;
	}
}

void List_Dataprint(List* p)
{
	printf("������ ����: %d\n",p->count);
	Node *cur = p->head;
	while(cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

Node* List_find(List* p,char data)
{
	
	Node *cur = p->head;
	while( cur != NULL)
	{
		if( cur->data == data)
		{
			//printf("ã�Ҵ�...:%d\n", cur->data);
			//cout<<"�˻� ���: "<<"�ּҰ�: "<<cur<<",������: "<<cur->data<<",���� �ּҰ�: "<<*cur<<endl;
			//printf("�˻����: �ּҰ�: %p, ������:%c, ���� �ּҰ�: %p\n",cur,cur->data,cur->next);
			return cur;
		}
		cur = cur->next;
	}
	printf("����Ʈ���� ��ã�Ҵ�..\n");
	return NULL;
}

void List_modify(List* p,char ch)
{
	Node *cur = List_find(p,ch);
	if(cur->data >= 'a' && cur->data <= 'z')
		cur->data=cur->data-32;
	else
		cur->data=cur->data+32;
}

void List_del(List* p,char ch)
{
	Node *prev, *cur;
	Node** start=&p->head;
	prev = cur = *start;
	if( cur->data == ch)
	{
		*start = cur->next;
		free(cur);
	}
	else
	{
		cur = cur->next;
		while( cur != NULL)
		{
			if( cur->data == ch)
			{
				prev->next	= cur->next;
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