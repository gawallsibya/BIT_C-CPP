//arr.h

typedef struct tagNODE NODE;
struct tagNODE
{
	ACCOUNT*	data;
	struct tagNODE *next;
	struct tagNODE *prev;
};

typedef struct tagLIST LIST; 
struct tagLIST
{
	NODE		*head;
	NODE		*tail;
	int			count;

};


void con_init(LIST *L);

int con_insert(LIST *L, void *pdata);

int con_size(LIST *L);

void* con_getdata(LIST *L, int idx);