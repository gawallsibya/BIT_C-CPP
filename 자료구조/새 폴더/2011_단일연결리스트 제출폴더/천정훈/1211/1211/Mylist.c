#include"Mylist.h"
#include"std.h"
void mylist_init(LIST *p)
{
	p	= (LIST*)malloc(sizeof(LIST));
	p->count = 0;
	p->head = NULL;
}
void mylist_push_front(LIST *p,NODE *newnode)
{	
	//��Ʈ ���� �ʱ�ȭ �ϴ� �κ� �����.
	if(p->head == NULL)
	{
		p->head = newnode;
		p->count++;
	}
	else
	{
		newnode->next = p->head;
		p->head = newnode;
		p->count++;
	}
}

void mylist_push_back(LIST *p,NODE *newnode)
{
	//��Ʈ ���� �ʱ�ȭ �ϴ� �κ� �����.
		if( p->head == NULL)
		{
			p->head		= newnode;
			p->count++;
		}
		else
		{
			NODE *cur = p->head;
			while( cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = newnode;
			p->count++;
		}
	
}