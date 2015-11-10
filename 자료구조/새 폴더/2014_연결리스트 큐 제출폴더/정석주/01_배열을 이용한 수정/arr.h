//arr.h

typedef struct tagMYARR MYARR;
struct tagMYARR
{
	ACCOUNT *data;
 	struct tagMYARR *next;
};

typedef struct tagLIST LIST;
 
struct tagLIST
{
	MYARR * head;		// start
	int    count;		// 저장개수
};

void con_init(LIST *p);

int con_insert(LIST *p, ACCOUNT *pdata);

int con_size(LIST *p);

void* con_getdata(LIST *p, int idx);

