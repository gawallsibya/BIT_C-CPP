
struct Account
{
	int		id;					// ���¹�ȣ
	int		balance;			// ��    ��
	char	name[NAME_LEN];		// �� �̸�
};

void PrintMenu();				// �޴� ���
void MakeAccount();				// ���� ������ ���� �Լ�
void Deposit();					// �� ��
void Withdraw();				// �� ��
void Inquire();					// �ܾ� ��ȸ
void fnEnter();




extern Account		pArray[100];		// ������ ���� �迭
extern int			index;				// ����� Account ��

