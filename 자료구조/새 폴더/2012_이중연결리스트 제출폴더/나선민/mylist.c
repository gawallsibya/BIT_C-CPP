#include "stdio.h"
#include "mylist.h"
#include "malloc.h"
void mylist_init(LIST *pdlist)
{
	pdlist->head = NULL;
	pdlist->tail = NULL;
	pdlist->count = 0;
}

void push_front(LIST *pdlist, char Data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= Data;
	newnode->next	= NULL;
	newnode->prev   = NULL;
	if( pdlist->head == NULL)
	{                           
		pdlist->head		= newnode;
		pdlist->tail	   = newnode;
	
	}
	else
	{		 
		newnode->next	= pdlist->head;	
		pdlist->head->prev = newnode;
		pdlist->head	= newnode;

	}
	pdlist->count++;
}
void push_back(LIST *pdlist, char Data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= Data;
	newnode->next	= NULL;
	newnode->prev   = NULL;
	if( pdlist->head == NULL )
	{
		pdlist->head		= newnode;
		pdlist->tail		= newnode;
	}
	else
	{
		newnode->prev = pdlist->tail;
		pdlist->tail->next = newnode;
		pdlist->tail		  = newnode;
	}
	pdlist->count++;
}

