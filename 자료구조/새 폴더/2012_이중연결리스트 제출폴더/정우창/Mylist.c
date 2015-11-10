#include "std.h"
#include "Mylist.h"

void Mylist_init(LIST * p)
{
	p->head  = NULL;		// start
	p->tail  = NULL;
	p->count = 0;			// 저장개수;
}

/*
void push_front(LIST * p, int data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;
	newnode->prev   = NULL;

	if( pdlist->head == NULL)
	{
		p->head = newnode;
		p->tail = newnode;
		p->count++;
	}
	else
	{
		newnode->next	= p->head;
		p->head->prev   = newnode;
		p->head			= newnode;
		p->count++;
	}
}
*/

void mylist_push_back(LIST * p, char data)
{
	NODE * newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->prev	= NULL;
	newnode->next	= NULL;

	if( p->head == NULL)
	{
		p->head	= newnode;
		p->tail = newnode;
		p->count++;
	}
	else
	{
		newnode->prev = p->tail;
		p->tail->next = newnode;
		p->tail		  = newnode;
		p->count++;
	}
}
