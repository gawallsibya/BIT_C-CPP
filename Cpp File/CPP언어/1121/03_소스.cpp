//queue
#include <stdio.h>

/*
#define MAX	10
struct Queue
{
	int data[MAX];
	int rear;
	int front;
};

void queue_init(Queue* q)
{
	q->rear = q->front = 0;
}

void queue_put(Queue* q, int num)
{
	if( (q->rear + 1 )%MAX == q->front)
	{
		printf("Overflow.. \n");
		return;
	}
	q->data[q->rear] = num;	
	q->rear = (q->rear + 1) % MAX;
}

int queue_get(Queue *p)
{
	if( p->front == p->rear)
	{
		printf("Underflow...\n");
		return -1;
	}
	int num = p->data[p->front];
	p->front = (p->front + 1)%MAX;
	return num;
}

void main()
{
	Queue queue;
	queue_init(&queue);

	for(int i=0; i<10; i++)
		queue_put(&queue, i*10);

	for(i=0; i<10; i++)
		printf("%d\n", queue_get(&queue)); 
}
*/

/*
#include <iostream>
using namespace std;
#define MAX	10
class Queue
{
	int data[MAX];
	int rear;
	int front;
public:
	Queue() : rear(0), front(0)	{	}

	void put(int num)
	{
		if( (rear + 1 )%MAX == front)
		{
			cout << "Overflow.." << endl;
			return;
		}
		data[rear] = num;	
		rear = (rear + 1) % MAX;
	}

	int get()
	{
		if( front == rear)
		{
			cout << "Underflow..."<< endl;
			return -1;
		}
		int num = data[front];
		front = (front + 1)%MAX;
		return num;
	}
};


void main()
{
	Queue queue;

	for(int i=0; i<10; i++)
		queue.put(i*10);

	for(i=0; i<10; i++)
		cout << queue.get() << endl; 
}
*/


/*
#include <iostream>
using namespace std;
#define MAX	10

template<typename T>
class Queue
{
	T data[MAX];
	int rear;
	int front;
public:
	Queue() : rear(0), front(0)	{	}

	void put(T num)
	{
		if( (rear + 1 )%MAX == front)
		{
			cout << "Overflow.." << endl;
			return;
		}
		data[rear] = num;	
		rear = (rear + 1) % MAX;
	}

	T get()
	{
		if( front == rear)
		{
			cout << "Underflow..."<< endl;
			return NULL;
		}
		T num = data[front];
		front = (front + 1)%MAX;
		return num;
	}
};


void main()
{
	Queue<int*> queue;

	for(int i=0; i<10; i++)
	{
		int *p = new int(i*10);
		queue.put(p);
	}


	for(i=0; i<10; i++)
	{
		int * p = queue.get(); 
		if( p == NULL)
			return;
		cout << *p << endl;
		delete p;
	}
}
*/