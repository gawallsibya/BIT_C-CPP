#ifndef _MYLIST_H_
#define _MYLIST_H_

typedef struct tagNODE NODE;
struct tagNODE
{
	NODE* prev;	//�� ������
	char  data;
	NODE* next;	//���� ������
};

typedef struct tagLIST LIST;
struct tagLIST
{
	NODE* head;			// ������
	int   count;		// ���尳��
	NODE* tail;			// ����
};

void mylist_init(LIST *p);
void push_front(LIST *p, char data);
void push_back(LIST *p, char data);

#endif //_MYLIST_H_