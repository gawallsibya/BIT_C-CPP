#include "stdio.h"
#include "mylist.h"
#include "malloc.h"

void mylist_init(LIST *p)
{
	p->head = NULL;
	p->count = 0;
}

void push_front(LIST *p, char data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;

	if( p->head == NULL)
	{                           
		p->head		= newnode;
	}
	else
	{		 
		newnode->next	= p->head;
		p->head		= newnode;
	}
	p->count++;
}

void push_back(LIST *p, char data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;

	if( p->head == NULL )
	{
		p->head		= newnode;
	}
	else
	{
		LIST cur = *p;
		while(cur.head->next !=NULL)
		{
			cur.head = cur.head->next;
		}
		cur.head->next = newnode;
	}
	p->count++;
}

