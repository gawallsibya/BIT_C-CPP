//mylist.h
#ifndef _MYLIST_H_
#define _MYLIST_H_

typedef struct tagNode Node;
struct tagNode
{

	ACCOUNT data;
	Node* next;

};


typedef struct tagLIST LIST;
struct tagLIST
{

	Node* head;
	int count;

};
void con_init(LIST *parr);
int con_insert(LIST *parr, void *pdata);
int con_size(LIST *parr);
ACCOUNT* con_getdata(LIST *parr,int idx);

#endif /*_MYLIST_H_*/