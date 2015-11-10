//arr.c
#include "std.h"

void con_init(MYARR *parr)
{
	parr->index	= 0;
}


int con_insert(MYARR *parr, void *pdata)
{
	if(parr->index	>= DATA_MAX)
		return 0;
	else
	{
		parr->pArray[parr->index++] = pdata;
		return 1;
	}
}

int con_size(MYARR *parr)
{
	return parr->index;
}

void* con_getdata(MYARR *parr, int idx)
{
	return parr->pArray[idx];
}