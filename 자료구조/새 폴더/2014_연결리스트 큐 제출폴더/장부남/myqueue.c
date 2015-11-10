//myqueue.c
#include "std.h"

void init_queue(MYQUEUE *pqueue)
{
	pqueue->front= pqueue->rear = NULL;

}


void clear_queue(MYQUEUE *pqueue)
{
	pqueue->front = pqueue->rear;
}


int put(MYQUEUE *pqueue, ACCOUNT* pdata)
{
	QueNode* newnode= (QueNode*)malloc(sizeof(QueNode));
	newnode->data = pdata;
	newnode->next = NULL;
	

	if( pqueue->front == NULL)
	{
		pqueue->front = newnode;
		pqueue->rear  = newnode;
	}
	else
	{
		pqueue->rear->next = newnode;
		pqueue->rear = newnode;
	}
	return 1;
}


void* get(MYQUEUE *pqueue)
{
	void* pdata;
	if(pqueue->front == NULL)
	{
		return NULL;
	}

	pdata = pqueue->front->data;
	pqueue->front = pqueue->front->next;

	return pdata;
}
