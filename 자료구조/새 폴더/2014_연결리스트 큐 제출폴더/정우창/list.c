#include "std.h"

void con_init(LIST * plist)
{
	plist->head		= NULL;
	plist->count	= 0;
}

int con_insert(LIST * plist, ACCOUNT * pdata)
{
	MYARR * newnode			= (MYARR*)malloc(sizeof(MYARR));
	newnode->data.id		= pdata->id;
	newnode->data.balance	= pdata->balance;
	strcpy(newnode->data.name, pdata->name);
	newnode->next			= NULL;

	if(plist->head == NULL)
	{
		plist->head = newnode;
		plist->count++;
		return 1;
	}
	else if(plist->count == QUEUE_MAX)
	{
		return 0;
	}
	else
	{
		MYARR * cur = plist->head;
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		plist->count++;
		return 1;
	}
	return 0;
}

int con_size(LIST * plist)
{
	return plist->count;
}

void * con_getdata(LIST * plist, int idx)
{
	int i;

	MYARR * cur = plist->head;

	for(i=0; i<idx; i++)
	{
		cur = cur->next;
	}
	return &cur->data;
}
