typedef struct tagMYARR MYARR;
struct tagMYARR
{
	ACCOUNT data;
	struct tagMYARR * next;
};

typedef struct tagLIST LIST;
struct tagLIST
{
	MYARR * head;		// start
	int    count;		// 저장개수
};

void con_init(LIST * plist);

int con_insert(LIST * plist, void * pdata);

int con_size(LIST * plist);

void* con_getdata(LIST * plist, int idx);


