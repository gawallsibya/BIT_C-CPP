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

void mylist_init(LIST * p);
void mylist_push_front(LIST *p, char data);
void mylist_push_back(LIST *p, char data);