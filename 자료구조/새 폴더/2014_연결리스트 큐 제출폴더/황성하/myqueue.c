//myqueue.c
#include "std.h"

void init_queue(MYQUEUE *pqueue)
{
	pqueue->front = pqueue->rear = NULL;
}


void clear_queue(MYQUEUE *pqueue)
{
	pqueue->front = pqueue->rear;
}


int put(MYQUEUE *pqueue, void* pdata)
{

	QUE_NODE * newnode = (QUE_NODE*)malloc(sizeof(QUE_NODE));

	newnode->queue	= pdata;
	newnode->next   = NULL;

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

	pdata = pqueue->front->queue;
	pqueue->front = pqueue->front->next;

	return pdata;
}


void push_back(MYQUEUE *pqueue)
{

}
