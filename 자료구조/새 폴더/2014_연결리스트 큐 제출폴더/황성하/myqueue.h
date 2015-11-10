//myqueue.h

typedef struct tagQUE_NODE QUE_NODE;
struct tagQUE_NODE
{
	void* queue;
	struct tagQUE_NODE * next;
};

typedef struct tagMYQUEUE MYQUEUE;
struct tagMYQUEUE 
{
	QUE_NODE * front;
	QUE_NODE * rear;
};



void init_queue(MYQUEUE *pqueue);

void clear_queue(MYQUEUE *pqueue);

int put(MYQUEUE * pqueue, void* pdata);

void* get(MYQUEUE *pqueue);

void push_back(MYQUEUE *pqueue);