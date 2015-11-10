typedef struct tagNODE NODE;
struct tagNODE
{
	char data;
 	struct tagNODE *next;
};

typedef struct tagLIST LIST;
struct tagLIST
{
	NODE * head;		// start
	int    count;		// 저장개수
};

void Mylist_init(LIST *p);
void Mylist_push_front(LIST *P, char data);
void Mylist_push_back(LIST *P, char data);
