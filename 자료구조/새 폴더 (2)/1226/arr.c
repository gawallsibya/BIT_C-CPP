//arr.c

#include "std.h"

void init_arr(Arr* parr)
{
	parr->ncount=0;
}

void arr_info(Arr* parr)
{
	int i;
	char ch[40];
	for(i=0; i<MAX; i++)
	{
		if(parr->data[i] != NULL)
		{
			ch[i]= 'X';
		}
		else
			ch[i]= 'O';	
	}
	printf("===================================\n");
	printf("1  5  9  13 17 21 25 29 33 37\n");
	for(i=0; i<MAX; i+=4)
	{
		printf("%c  ", ch[i]);
	}
	printf("\n2  6  10 14 18 22 26 30 34 38\n");
	for(i=1; i<MAX; i+=4)
	{
		printf("%c  ", ch[i]);
	}
	printf("\n");
	printf("3  7  11 15 19 23 27 31 35 39\n");  
	for(i=2; i<MAX; i+=4)
	{
		printf("%c  ", ch[i]);
	}
	printf("\n4  8  12 16 20 24 28 32 36 40\n");  
	for(i=3; i<MAX; i+=4)
	{
		printf("%c  ", ch[i]);
	}
	printf("\n");
};

void arr_insert(Arr *parr, Member *pdata,int idx)
{
	parr->data[idx-1] = pdata;	
}

Member* arr_getdata(Arr* parr,int idx)
{
	return parr->data[idx-1];
}