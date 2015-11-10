//myqueue.c
#include "std.h"

void init_queue(MYQUEUE *pqueue)
{
	pqueue->front = pqueue->rear = 0;
}


void clear_queue(MYQUEUE *pqueue)
{
	pqueue->front = pqueue->rear;
}


int put(MYQUEUE *pqueue, ACCOUNT* pdata)
{
	ACCOUNT *data = (ACCOUNT*)malloc(sizeof(ACCOUNT));
	
	data->balance = pdata->balance;
	data->flag = pdata->flag;
	data->id = pdata->id;
	strcpy(data->name, pdata->name);
	
	if((pqueue->rear + 1) % QUEUE_MAX == pqueue->front)
	{
		return 0;
	}

	pqueue->queue[pqueue->rear] = data;		// 데이터 저장
	pqueue->rear = ++pqueue->rear % QUEUE_MAX;	// 원형이동
	return 1;
}


void* get(MYQUEUE *pqueue)
{
	void* pdata;
	if(pqueue->front == pqueue->rear)
	{
		return NULL;
	}

	pdata = pqueue->queue[pqueue->front];
	pqueue->front = ++pqueue->front % QUEUE_MAX;
	return pdata;
}
