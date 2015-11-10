#ifndef _MYLIST_H_
#define _MYLIST_H_

typedef struct tagNODE NODE;
struct tagNODE
{
	char data;
	NODE * next;
};

typedef struct tagLIST LIST;
struct tagLIST
{
	NODE * head;		// start
	int    count;		// 저장개수
};

void Mylist_init(LIST * p);
//void mylist_push_front(LIST * p, char data);
void mylist_push_back(LIST * p, char data);

#endif /*_MYLIST_H_*/