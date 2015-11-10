//arr.c
#include "std.h"

void con_init(MYARR *parr)
{
	parr->front = NULL;
	parr->rear	= NULL;
	parr->size	= 0;
}


int con_insert(MYARR *parr, void *pdata)
{

	ARRLIST * newnode = (ARRLIST*)malloc(sizeof(ARRLIST));

	newnode->pArray	= pdata;
	newnode->next   = NULL;

	if( parr->front == NULL )
	{
		parr->front = newnode;
		parr->rear  = newnode;
		parr->size++;
		return 1;
	}
	else
	{
		parr->rear->next = newnode;
		parr->rear = newnode;
		parr->size++;
		return 1;
	}
	parr->size++;
	return 0;
}

int con_size(MYARR *parr)
{
	return parr->size;
}

void* con_getdata(MYARR *parr, int idx)
{
	int i;
	ARRLIST * cur = parr->front;
	ACCOUNT * data = cur->pArray;
	for(i=0 ; i<idx ; i++)
	{
		cur = cur->next;
		data = cur->pArray;
	}
	return data;
/*
	while(search->next != NULL)
	{
		ACCOUNT *pData = search->pArray;
		if(pData->id == idx)
		{
			return pData;
		}
		search = search->next;
	}
	return NULL;
*/

}