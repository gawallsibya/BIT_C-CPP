#ifndef _MYLIST_H_
#define _MYLIST_H_


typedef struct tagNODE NODE;
struct tagNODE
{
	char data;
	struct tagNODE *next;
};

typedef struct tagLIST LIST;
struct tagLIST
{
	NODE * head;		// start
	int    count;		// 저장개수
};


void mylist_init(LIST *p);
void push_front(LIST *p, char data);
void push_back(LIST *p, char data);


#endif /*_MYLIST_H_*/