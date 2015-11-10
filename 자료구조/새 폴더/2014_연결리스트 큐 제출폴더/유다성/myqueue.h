//myqueue.h

typedef struct tagMYQUEUE MYQUEUE;
struct tagMYQUEUE 
{
	void* queue[QUEUE_MAX];
	int front;
	int rear;
};


void init_queue(MYQUEUE *pqueue);

void clear_queue(MYQUEUE *pqueue);

int put(MYQUEUE *pqueue, ACCOUNT* pdata);

void* get(MYQUEUE *pqueue);
