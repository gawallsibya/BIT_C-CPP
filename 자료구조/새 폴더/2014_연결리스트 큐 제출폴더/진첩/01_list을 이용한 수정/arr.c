//arr.c
#include "std.h"

void con_init(LIST *parr)
{
	parr->count	= 0;
	parr->head=NULL;
}


int con_insert(LIST *parr, void *pdata)
{
	if(parr->count	>= DATA_MAX)
		return 0;
	else
	{
	//	parr->pArray[parr->index++] = pdata;
	//	return 1;
		NODE *newnode = (NODE*)malloc(sizeof(NODE)); 

		newnode->data = pdata;
		newnode->next = NULL;
		newnode->prev = NULL;

		if(parr->head == NULL)
		{
			parr->head  = newnode;
			parr->count++;
		}
		else
		{
			parr->head->prev = newnode;
			newnode->next = parr->head;
			parr->head = newnode;
			parr->count++;
		}
		return 1;
	}
}

int con_size(LIST *parr)
{
	return parr->count;
}

void* con_getdata(LIST *parr,int idx)
{
	NODE *cur;ACCOUNT *data;int i;
	cur = parr->head;
	data=cur->data;
	for(i=0 ; i<idx ; i++)
	{
		cur=cur->next;
		data=cur->data;
	}
	return data;
}
