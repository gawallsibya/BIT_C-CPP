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
	NODE* head;			// ������
	int   count;		// ���尳��
};

#endif //_MYLIST_H_