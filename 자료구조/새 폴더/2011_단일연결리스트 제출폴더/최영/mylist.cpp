#include "mylist.h"
#include "std.h"

void List_init(List* p)
{
	p->head=NULL;
	p->count=0;
}
void List_push_back(List* p,char ch)
{
	Node** start=&p->head;
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=ch;
	newnode->next=NULL;
	if( *start == NULL)
	{
		*start		= newnode;
	}
	else
	{
		Node *cur = *start;
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	p->count++;
}
void List_push_front(List* p,char ch)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
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

void List_Dataprint(List* p)
{
	printf("문자의 개수: %d\n",p->count);
	Node *cur = p->head;
	while(cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");
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
	printf("리스트에서 못찾았다..\n");
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
	Node *prev, *cur;
	Node** start=&p->head;
	prev = cur = *start;
	if( cur->data == ch)
	{
		*start = cur->next;
		free(cur);
	}
	else
	{
		cur = cur->next;
		while( cur != NULL)
		{
			if( cur->data == ch)
			{
				prev->next	= cur->next;
				free(cur);
				return;
			}
			else
			{
				cur = cur->next;
				prev = prev->next;
			}
		}
	}
}