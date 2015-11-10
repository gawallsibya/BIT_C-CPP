//list.cpp
#include "std.h"

List::List()
{
	head=NULL;
	tail=NULL;
	ncount=0;
}

void List::list_insert(Member* data)
{
	
	Node* newnode=new Node(data, NULL, NULL);
	

	if( head == NULL)
	{
		head		= newnode;
		tail		= newnode;
		ncount		= newnode->data->count;
		return;
	}
	else
	{
		Node *cur = head;
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		ncount  =newnode->data->count;
		return;
	}
}

void List::list_print(Member* data)
{
	data->mem_print();
}

Member* List::list_search(char* ch)
{
	Node* cur=head;
	while(cur != NULL)
	{
		if(!strcmp(cur->data->GetPhone(),ch) || !strcmp(cur->data->GetNum(),ch))
			return cur->data;
		cur=cur->next;
	}
	return NULL;
}