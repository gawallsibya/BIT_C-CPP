//arr.h

typedef struct tagARRLIST ARRLIST;
struct tagARRLIST
{
	void*	pArray;
	struct tagARRLIST * next;

};

typedef struct tagMYARR MYARR;
struct tagMYARR
{
	ARRLIST * front;
	ARRLIST * rear;
	int size;
};

void con_init(MYARR *parr);

int con_insert(MYARR *parr, void *pdata);

int con_size(MYARR *parr);

void* con_getdata(MYARR *parr, int idx);


/*
typedef struct tagMYARR MYARR;
struct tagMYARR
{
	void*	pArray[DATA_MAX];
	int			index ;
};

void con_init(MYARR *parr);

int con_insert(MYARR *parr, void *pdata);

int con_size(MYARR *parr);

void* con_getdata(MYARR *parr, int idx);
*/