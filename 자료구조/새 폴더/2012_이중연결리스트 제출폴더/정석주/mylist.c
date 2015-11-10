#include "stdio.h"
#include "mylist.h"
#include "malloc.h"

void _init(LIST *p)
{
	p->head=NULL;
	p->count=0;
}

void _push_front(LIST *p, char data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;
	newnode->prev   = NULL;

	if( p->head == NULL)
	{                           
		p->head		= newnode;
		p->tail		= newnode;
	}
	else
	{		 
		newnode->next	= p->head;
		p->head->prev	= newnode;
		p->head			= newnode;
	}
}

/*
void _push_back(LIST *p, char data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;

	if( p->head == NULL)
	{                           
		p->head		= newnode;
		p->tail		= newnode;
	}
	else
	{
		newnode->prev = p->tail;
		p->tail->next = newnode;
		p->tail=newnode;					
	}
		
}
*/
