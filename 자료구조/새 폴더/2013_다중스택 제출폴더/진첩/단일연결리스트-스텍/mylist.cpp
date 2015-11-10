
#include "std.h"
#include"mylist.h"

void List_init(List* p)
{
	p->head=NULL;
}

void List_push_front(List* p, char ch)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	if( newnode == NULL)	//"overflow"
		return;
	newnode->data=ch;
	newnode->next=NULL;

	if(p->head ==NULL)
	{
		p->head		= newnode;
	}
	else
	{
		newnode->next= p->head;
		p->head=newnode;
	}
}


void List_pop_back(List *p, char *ch)
{
	Node *cur;
	if(p->head == NULL)
	{
		printf("underflow");
		return;
	}
	
	*ch = p->head->data;
	cur = p->head;

	p->head = cur->next;
	free(cur);
	
}


