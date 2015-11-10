#ifndef _MYLIST_H_
#define _MYLIST_H_

typedef struct tagNODE NODE;
struct tagNODE
{
	char  data;
	NODE* next;
};

typedef struct tagLIST LIST;
struct tagLIST
{
	NODE* head;			// 시작점
	int   count;		// 저장개수
};

#endif //_MYLIST_H_