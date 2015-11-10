//account.h

typedef struct tagACCOUNT ACCOUNT;
struct tagACCOUNT
{
	int		id;					// 계좌번호
	int		balance;			// 잔    액
	char	name[NAME_LEN];		// 고객 이름
	int     flag;				//1 입금 2.  출금
};

void acc_addmoney(ACCOUNT *pData, int money);
int acc_minmoney(ACCOUNT *pData, int money);
void acc_dataprint(ACCOUNT *pData);