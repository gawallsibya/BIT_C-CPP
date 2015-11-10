#include "mylist.h"
#include "std.h"

void mylist_init(LIST *p)
{
	p->head  = NULL;		// start
	p->count = 0;			// 저장개수;
}

void mylist_push_front(LIST *p, char data)
{
	NODE *newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = data;
	newnode->next = NULL;
	
	if(p->head == NULL)
	{
		p->head = newnode;
		p->count++;
	}
	else
	{
		newnode->next = p->head;
		p->head	  = newnode; 
		p->count++;
	}
	
}

void mylist_push_back(LIST *p, char data)
{
	NODE *newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = data;
	newnode->next = NULL;

	if(p->head == NULL)
	{
		p->head = newnode;
		p->count++;
	}
	else
	{
		NODE *cur = p->head;
		
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		p->count++;
	}
}