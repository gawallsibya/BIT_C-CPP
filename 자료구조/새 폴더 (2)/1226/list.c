//list.c

#include "std.h"

void init_list(List* plist)
{
	plist->head=NULL;
	plist->ncount=0;
}

void list_insert(List* plist,Member* data)
{
	Node *cur;
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;

	if( plist->head == NULL)
	{
		plist->head		= newnode;
		plist->ncount   = newnode->data->count;
		return;
	}
	else
	{
		cur = plist->head;
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		plist->ncount  =newnode->data->count;
		return;
	}
}

void list_print(Member* data)
{
	mem_print(data);
}

Member* list_search(List* plist, char* ch)
{
	Node* cur=plist->head;
	while(cur != NULL)
	{
		if(!strcmp(cur->data->phone,ch) || !strcmp(cur->data->number,ch))
			return cur->data;
		cur=cur->next;
	}
	return NULL;
}