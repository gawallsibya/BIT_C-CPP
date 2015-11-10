
struct Account
{
	int		id;					// 계좌번호
	int		balance;			// 잔    액
	char	name[NAME_LEN];		// 고객 이름
};

void PrintMenu();				// 메뉴 출력
void MakeAccount();				// 계좌 개설을 위한 함수
void Deposit();					// 입 금
void Withdraw();				// 출 금
void Inquire();					// 잔액 조회
void fnEnter();




extern Account		pArray[100];		// 저장을 위한 배열
extern int			index;				// 저장된 Account 수

