//myqueue.h

#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

typedef struct tagQueNode QueNode;
struct tagQueNode
{
	void* data;
	QueNode* next;

};
typedef struct tagMYQUEUE MYQUEUE;
struct tagMYQUEUE 
{
	QueNode* front;
	QueNode* rear;	
};

void init_queue(MYQUEUE *pqueue);
void clear_queue(MYQUEUE *pqueue);
int put(MYQUEUE *pqueue, ACCOUNT* pdata);
void* get(MYQUEUE *pqueue);

#endif /*_MYQUEUE_H_*/