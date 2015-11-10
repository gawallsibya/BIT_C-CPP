#include "node.h"
#include "std.h"

typedef struct tagList List;
struct tagList
{
	Node* head;		// start
	Node* tail;
	int    count;
};
void List_init(List* p);
void List_push_back(List* p,char ch);
void List_push_front(List* p,char ch);
Node* List_find(List* p,char data);
void List_modify(List* p,char ch);
void List_del(List* p,char ch);
