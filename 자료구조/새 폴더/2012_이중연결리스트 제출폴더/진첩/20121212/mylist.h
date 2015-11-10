#ifndef _MYLIST_H_
#define _MYLIST_H_
typedef struct tagNODE NODE;
struct tagNODE
{
	int data;
	struct tagNODE *next;
	struct tagNODE *prev;
};
typedef struct tagDLIST DLIST;
struct tagDLIST
{
	NODE *head;
	NODE *tail;
	int  count;	
};
void List_push_front(DLIST *p,char ch);
void List_push_back(DLIST *p, char ch);
#endif