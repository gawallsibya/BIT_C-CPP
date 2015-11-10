#include "mylist.h"
#include "std.h"

void List_init(List* p)
{
	p->head=NULL;
	p->tail=NULL;
	p->count=0;
}
void List_push_back(List* p,char ch)
{
	
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=ch;
	newnode->next=NULL;
	newnode->prev=NULL;
	if( p->head == NULL)
	{
		p->head		= newnode;
		p->tail     = newnode;
	}
	else
	{
		newnode->prev = p->tail;
		p->tail->next = newnode;
		p->tail		  = newnode;
	}
	p->count++;
}
void List_push_front(List* p,char ch)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=ch;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(p->head ==NULL)
	{
		p->head		= newnode;
		p->tail     = newnode;
	}
	else
	{
		newnode->next= p->head;
		p->head->prev= newnode;
		p->head=newnode;
	}
}


Node* List_find(List* p,char data)
{
	
	Node *cur = p->head;
	while( cur != NULL)
	{
		if( cur->data == data)
		{
			//printf("찾았다...:%d\n", cur->data);
			//cout<<"검색 결과: "<<"주소값: "<<cur<<",데이터: "<<cur->data<<",다음 주소값: "<<*cur<<endl;
			//printf("검색결과: 주소값: %p, 데이터:%c, 다음 주소값: %p\n",cur,cur->data,cur->next);
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void List_modify(List* p,char ch)
{
	Node *cur = List_find(p,ch);
	if(cur->data >= 'a' && cur->data <= 'z')
		cur->data=cur->data-32;
	else
		cur->data=cur->data+32;
}

void List_del(List* p,char ch)
{
	Node *cur = List_find(p, ch);
	if( cur == NULL)
	{
		printf("못찾았다...\n");
	}
	else
	{
		Node *del, *prev;
		del		= cur;
		prev	= cur->prev;

		if( cur == p->head)
		{
			p->head = cur->next;
		}
		else if( cur == p->tail)
		{
			prev->next		= NULL;
			p->tail	= prev;
		}
		else
		{
		prev->next		= del->next;
		del->next->prev	= prev;
		}

		free(del);
		p->count--;
	}
}