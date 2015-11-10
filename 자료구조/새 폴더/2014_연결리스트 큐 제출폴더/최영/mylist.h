//mylist.h

typedef struct tagNode Node;
struct tagNode
{
//	void* data;
	ACCOUNT data;
	Node* next;
};


typedef struct tagLIST LIST;
struct tagLIST
{
	Node* head;
	int count;
};

void con_init(LIST *parr);

int con_insert(LIST *parr, void *pdata);

int con_size(LIST *parr);

ACCOUNT* con_getdata(LIST *parr,int idx);