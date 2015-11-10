#include "std.h"
#include "Mylist.h"


void Mylist_init(LIST *p)
{
	p->count = 0;
	p->head = NULL;
	p->tail = NULL;
}

void Mylist_push_front(LIST *P, char data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;
	newnode->prev	= NULL;
	if( P->head == NULL)
	{
		P->head		= newnode;
		P->tail		= newnode;
		P->count++;
	}
	else
	{
		newnode->next	= P->head;
		P->head->prev	= newnode;
		P->head			= newnode;
		P->count++;
	}
	
}


void Mylist_push_back(LIST *P, char data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;
	newnode->prev	= NULL;
	if( P->head == NULL)
	{
		P->head		= newnode;
		P->tail		= newnode;
		P->count++;
	}
	else
	{
		newnode->prev		= P->tail;
		P->tail->next		= newnode;
		P->tail				= newnode;
		P->count++;
	}
	
}