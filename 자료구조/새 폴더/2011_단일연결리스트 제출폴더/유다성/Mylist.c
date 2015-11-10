#include "std.h"
#include "Mylist.h"


void Mylist_init(LIST *p)
{
	p->count = 0;
	p->head = NULL;
}

void Mylist_push_front(LIST *P, char data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;
	if( P->head == NULL)
	{
		P->head		= newnode;
	}
	else
	{
		newnode->next	= P->head;
		P->head		= newnode;
	}
	P->count++;
}


void Mylist_push_back(LIST *P, char data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;
	if( P->head == NULL)
	{
		P->head		= newnode;
	}
	else
	{
		NODE *cur = P->head;
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	P->count++;
}