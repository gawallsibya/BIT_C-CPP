
#include<malloc.h>

typedef struct tagNODE NODE;
struct tagNODE
{
char data;	
struct tagNODE *next;
};

typedef struct tagLIST LIST;
   struct tagLIST
{
NODE * head;
int    count;
};


void mylist_init(LIST *p);

void mylist_push_front(LIST *p,NODE *newnode);

void mylist_push_back(LIST *p,NODE *newnode);
//{}

