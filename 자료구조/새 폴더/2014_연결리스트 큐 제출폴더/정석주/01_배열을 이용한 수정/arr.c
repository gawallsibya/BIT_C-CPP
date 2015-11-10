//arr.c
#include "std.h"


void con_init(LIST *p)
{
	p->head  = NULL;
	p->count = 0;	
}


int con_insert(LIST *p, ACCOUNT *pdata)
{
	MYARR *newnode	= (MYARR*)malloc(sizeof(MYARR));
	newnode->data	= pdata;
	newnode->next	= NULL;

	if( p->head == NULL)
	{                           
		p->head		= newnode;		
		p->count++;

		return 1;
	}
	else
	{
		MYARR *cur= p->head;
		while(cur->next!=NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		p->count++;

		return 1;
	}
}

int con_size(LIST *p)
{
	return p->count;
}

void* con_getdata(LIST *p, int idx)
{
	int i;
	MYARR *cur = p->head;
	for(i=0; i < idx; i++)
	{
		cur = cur->next;
	}
	return cur->data;
}