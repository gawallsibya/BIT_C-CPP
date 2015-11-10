#include "mylist.h"

void mylist_init(DLIST *p)
{
	p->head		= NULL;
	p->tail		= NULL;
	p->count		= 0;
}

void push_front(DLIST *p, char data)
{
	NODE *newnode		= (NODE*)malloc(sizeof(NODE));
	newnode->data		= data;
	newnode->next		= NULL;
	newnode->prev		= NULL;

	if( p->head == NULL)
	{                           
		p->head		= newnode;
		p->tail		= newnode;
	}
	else
	{		 
		newnode->next		= p->head;
		p->head->prev		= newnode;
		p->head				= newnode;
	}
	p->count++;
}

void push_back(DLIST *p, char data)
{
	NODE *newnode		= (NODE*)malloc(sizeof(NODE));
	newnode->data		= data;
	newnode->next		= NULL;
	newnode->prev		= NULL;

	if( p->head == NULL )
	{
		p->head		= newnode;
		p->tail		= newnode;
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



