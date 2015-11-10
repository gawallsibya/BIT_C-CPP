//arr.c
#include "std.h"

LIST list;
void con_init(MYARR *parr)
{
	
	parr=(MYARR*)malloc(sizeof(MYARR));
		parr->data = NULL;
		parr->next=NULL;
}


int con_insert(MYARR *parr, void *pdata)
{
	if(parr->next!=NULL)
		return 0;
	else
	{
		parr->data = pdata;
		//	mylist_push_front(&list,parr);
		mylist_push_back(&list,parr);
		return 1;
	}
}

int con_size(MYARR *parr)
{
	//return parr->next;
	return list.count;
}

void* con_getdata(MYARR *parr, int idx)
{
	return parr->data;
}



void mylist_init(LIST *p)
{
	p	= (LIST*)malloc(sizeof(LIST));
	p->count = 0;
	p->head = NULL;
}
void mylist_push_front(LIST *p,MYARR *newMYARR)
{	
	//노트 생성 초기화 하는 부분 만들기.
	if(p->head == NULL)
	{
		p->head = newMYARR;
		p->count++;
	}
	else
	{
		newMYARR->next = p->head;
		p->head = newMYARR;
		p->count++;
	}
}

void mylist_push_back(LIST *p,MYARR *newMYARR)
{
	//노트 생성 초기화 하는 부분 만들기.
		if( p->head == NULL)
		{
			p->head		= newMYARR;
			p->count++;
		}
		else
		{
			MYARR *cur = p->head;
			while( cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = newMYARR;
			p->count++;
		}
	
}
