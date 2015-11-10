//myqueue.h

typedef struct tagNODE NODE;
struct tagNODE 
{
	void * queue;
	struct tagNODE * next;
};

typedef struct tagMYQUEUE MYQUEUE;
struct tagMYQUEUE 
{
	NODE * front;
	NODE * rear;
};


void init_queue(MYQUEUE * pqueue);

void clear_queue(MYQUEUE * pqueue);

int put(MYQUEUE * pqueue, ACCOUNT * pdata);

void* get(MYQUEUE * pqueue);
