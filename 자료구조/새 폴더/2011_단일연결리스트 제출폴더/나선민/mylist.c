#include "stdio.h"
#include "mylist.h"
#include "malloc.h"
void mylist_init(LIST *pdlist)
{
	pdlist->head = NULL;
	pdlist->count = 0;
}

void push_front(LIST *pdlist, char Data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= Data;
	newnode->next	= NULL;
	if( pdlist->head == NULL)
	{                           
		pdlist->head		= newnode;
	
	}
	else
	{		 
		newnode->next	= pdlist->head;
		pdlist->head	= newnode;

	}
	pdlist->count++;
}


void push_back(LIST *pdlist, char Data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= Data;
	newnode->next	= NULL;
	if( pdlist->head == NULL )
	{
		pdlist->head		= newnode;
	}
	else
	{
		LIST cur = *pdlist;
		while(cur.head->next !=NULL)
		{
			cur.head = cur.head->next;
		}
		cur.head->next = newnode;
	}
	pdlist->count++;
}

