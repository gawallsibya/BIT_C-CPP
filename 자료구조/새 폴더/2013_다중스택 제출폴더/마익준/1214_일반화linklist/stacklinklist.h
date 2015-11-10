#ifndef _STACK_LINKLIST_H_
#define _STACK_LINKLIST_H_
typedef struct StackLinkListNode NODE;
struct StackLinkListNode
{
	void* data;
	struct StackLinkListNode *next;
	struct StackLinkListNode *prev;
};
typedef struct StackList Slist;
struct StackList 
{
	NODE *head;
	int count;
};
#endif /*_STACK_LINKLIST_H_*/