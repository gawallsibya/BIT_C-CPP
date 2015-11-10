//arr.h

#ifndef _ARR_H_
#define _ARR_H_

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


#endif /*_ARR_H_*/