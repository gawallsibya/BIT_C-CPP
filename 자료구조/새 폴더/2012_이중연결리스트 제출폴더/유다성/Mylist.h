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
	NODE * head;
	NODE * tail;
	int    count;	
};

void Mylist_init(LIST *p);
void Mylist_push_front(LIST *P, char data);
void Mylist_push_back(LIST *P, char data);
