//arr.c
#include "std.h"

void con_init(LIST *L)
{
	L->count	= 0;
	L->head		= NULL;
	L->tail		= NULL;
}


int con_insert(LIST *L, void *pdata)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= pdata;
	newnode->next	= NULL;
	newnode->prev	= NULL;
	if( L->head == NULL)
	{
		L->head		= newnode;
		L->tail		= newnode;
		L->count++;
		return 1;
	}
	else
	{
		newnode->prev	= L->tail;
		L->tail->next	= newnode;
		L->tail			= newnode;
		L->count++;
		return 1;
	}
	return 0;
}

int con_size(LIST *L)
{
	return L->count;
}

void* con_getdata(LIST *L, int idx)
{
	int i;
	NODE *cur = L->head;
	for(i = 0; i < idx; i++)
	{
		cur = cur->next;	
	}
	return cur->data;
}
