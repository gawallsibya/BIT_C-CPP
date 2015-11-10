#ifndef _MYLIST_
#define _MYLIST_
typedef struct tagNODE NODE;
struct tagNODE
{
	char data;
 	struct tagNODE *next;

};
typedef struct tagLIST LIST;

struct tagLIST
{
	NODE *head;

	int    count;
};

#endif /*_MYLIST_*/