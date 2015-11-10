#ifndef _MYLIST_H_
#define _MYLIST_H_

typedef struct tagNODE NODE;
struct tagNODE
{
	NODE* prev;	//전 포인터
	char  data;
	NODE* next;	//다음 포인터
};

typedef struct tagLIST LIST;
struct tagLIST
{
	NODE* head;			// 시작점
	int   count;		// 저장개수
	NODE* tail;			// 꼬리
};

void mylist_init(LIST *p);
void push_front(LIST *p, char data);
void push_back(LIST *p, char data);

#endif //_MYLIST_H_