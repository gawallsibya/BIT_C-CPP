//account.c
#include "std.h"

void acc_addmoney(ACCOUNT *pData, int money)
{
	pData->balance	+= money;
}

int acc_minmoney(ACCOUNT *pData, int money)
{
	if( pData->balance >= money)
	{
		pData->balance	-= money;
		return 1;
	}
	else
		return 0;
}

void acc_dataprint(ACCOUNT *pData)
{
	printf("ID   : %d\n", pData->id);
	printf("ÀÌ¸§ : %s\n", pData->name);
	printf("ÀÜ¾× : %d\n", pData->balance);
	printf("\n");
}