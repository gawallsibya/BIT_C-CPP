//mylist.c
#include "std.h"

void con_init(LIST *parr)
{
	parr->head=NULL;
	parr->count=0;
}


int con_insert(LIST *parr, ACCOUNT *pdata)
{
	Node *cur;
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data.id=pdata->id;
	newnode->data.balance=pdata->balance;
	strcpy(newnode->data.name,pdata->name);
	newnode->next=NULL;

	if( parr->head == NULL)
	{
		parr->head		= newnode;
		parr->count++;
		return 1;
	}
	else if(parr->count==QUEUE_MAX)
	return 0;
	else
	{
		cur = parr->head;
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		parr->count++;
		return 1;
	}
	
	return 0;
	
	
}

int con_size(LIST *parr)
{
	return parr->count;
}

ACCOUNT* con_getdata(LIST *parr,int idx)
{
	int i;
	Node* cur=parr->head;
	for(i=0;i<idx;i++)
	{
		cur=cur->next;
	}
	return &cur->data;
}
