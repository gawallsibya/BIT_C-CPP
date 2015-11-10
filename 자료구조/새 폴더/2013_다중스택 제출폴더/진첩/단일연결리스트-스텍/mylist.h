#ifndef  _MYLIST_H_
#define  _MYLIST_H_

typedef struct tagNode Node;
struct tagNode
{
	char data;
 	Node* next;
};


typedef struct tagList List;
struct tagList
{
	Node *head;		// start
};


void List_init(List* p);
void List_push_front(List*p, char ch);
void List_pop_back(List *p, char *ch);
#endif