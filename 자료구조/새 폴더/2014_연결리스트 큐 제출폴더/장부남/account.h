//account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
typedef struct tagACCOUNT ACCOUNT;
struct tagACCOUNT
{
	int		id;				
	int		balance;			
	char	name[NAME_LEN];		

           	
};

void acc_addmoney(ACCOUNT *pData, int money);
int acc_minmoney(ACCOUNT *pData, int money);
void acc_dataprint(ACCOUNT *pData);

#endif /*_ACCOUNT_H_*/