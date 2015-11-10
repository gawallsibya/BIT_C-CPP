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

	if( p->head == NULL)
	{                           
		p->head		= newnode;
	}
	else
	{		 
		newnode->next	= p->head;
		p->head		= newnode;
	}
}

/*void _push_back(LIST *p, char data)
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
		NODE *cur= p->head;
		while(cur->next!=NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
		
}
*/
