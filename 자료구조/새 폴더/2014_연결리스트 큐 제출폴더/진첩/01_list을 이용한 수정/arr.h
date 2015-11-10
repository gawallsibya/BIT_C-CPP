//arr.h

typedef struct tagNODE NODE;
struct tagNODE
{
	void * data;
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


void con_init(LIST *parr);

int con_insert(LIST *parr, void *pdata);

int con_size(LIST *parr);

void* con_getdata(LIST *parr,int idx);