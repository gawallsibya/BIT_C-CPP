//account.h

typedef struct tagACCOUNT ACCOUNT;
struct tagACCOUNT
{
	int		id;					// ���¹�ȣ
	int		balance;			// ��    ��
	char	name[NAME_LEN];		// �� �̸�
	int     flag;				//1 �Ա� 2.  ���
};

void acc_addmoney(ACCOUNT *pData, int money);
int acc_minmoney(ACCOUNT *pData, int money);
void acc_dataprint(ACCOUNT *pData);