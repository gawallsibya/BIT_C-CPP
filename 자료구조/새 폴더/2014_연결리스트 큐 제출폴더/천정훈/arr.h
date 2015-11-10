//arr.h

//typedef struct tagMYARR MYARR;
//struct tagMYARR
//{
//	void*	pArray[DATA_MAX];
//	int			index ;
//};

typedef struct tagMYARR MYARR;
struct tagMYARR
{
void* data;	
struct tagMYARR *next;
};

typedef struct tagLIST LIST;
   struct tagLIST
{
MYARR * head;
int    count;
};


void mylist_init(LIST *p);

void mylist_push_front(LIST *p,MYARR *newnode);

void mylist_push_back(LIST *p,MYARR *newnode);


///////////////////////////////////////////////////////////

void con_init(MYARR *parr);

int con_insert(MYARR *parr, void *pdata);

int con_size(MYARR *parr);

void* con_getdata(MYARR *parr, int idx);
