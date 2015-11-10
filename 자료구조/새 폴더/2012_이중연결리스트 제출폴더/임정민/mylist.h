#include "std.h"
#include "malloc.h"

typedef struct tagNODE NODE;
 
 struct tagNODE
 {
	char data;
 	struct tagNODE *next;
	struct tagNODE *prev;
 };

 typedef struct tagDLIST DLIST;
 
 struct tagDLIST
 {
	NODE		*head;		// start
	NODE		*tail;
	int			count;		// 저장개수
 };
	
void mylist_init(DLIST *p);
void push_front(DLIST *p, char data);
void push_back(DLIST *p, char data);
