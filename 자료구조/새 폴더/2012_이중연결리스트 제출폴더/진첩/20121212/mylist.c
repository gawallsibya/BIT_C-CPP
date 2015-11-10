#include"std.h"
#include"mylist.h"
void List_push_front(DLIST *p,char ch)
{
	NODE* newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=ch;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(p->head ==NULL)
	{
		p->head		= newnode;
		p->tail     = newnode;
		p->count++;
	}
	else
	{
		newnode->next= p->head;
		p->head->prev= newnode;
		p->head=newnode;
		p->count++;
	}
}


void List_push_back(DLIST *p, char ch)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= ch;
	newnode->next   = NULL;
	newnode->prev   = NULL;

	if( p->head == NULL)
	{
		p->head = newnode;
		p->tail = newnode;
		p->count++;
	}
	else
	{
		newnode->prev		= p->tail;
		p->tail->next		= newnode;
		p->tail				= newnode;
		p->count++;
	}
}