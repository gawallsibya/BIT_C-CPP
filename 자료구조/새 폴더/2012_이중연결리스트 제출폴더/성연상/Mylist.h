#ifndef _MYLIST_
#define _MYLIST_
typedef struct tagNODE NODE;
struct tagNODE
{
	char data;
 	struct tagNODE *next;
	struct tagNODE *prev;
};
typedef struct tagLIST LIST;

struct tagLIST
{
	NODE *head;
	NODE *tail;
	int    count;
};

#endif /*_MYLIST_*/