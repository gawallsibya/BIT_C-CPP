/************************************************************
  01. 아래 코드가 실행될 수 있는 클래스 구현 
		>실행 결과
		3+5=8
		3/5=0.6
		12-4=8
		12/4=3
*************************************************************/

int main(void)
{
    Calculator cal;
    cout<< "3+5= "<<cal.Add(3,5)<<endl;
    cout<< "3/5= "<<cal.Div(3,5)<<endl;
    cout<< "12-4= "<<cal.Min(12,4)<<endl;
    cout<< "12/4= "<<cal.Div(12,4)<<endl;
    return 0;
}


/************************************************************
  02. 다음 클래스는 은행 계좌 정보를 담을 수 있도록 정의되어 있는 
      Account 클래스이다.

  Account 클래스를 public 상속하는 KBAccount 클래스를 정의해 보자. 
  KBAccount 클래스는 Account 클래스가 지니고 있는 멤버 변수 
  이외에 고객별 이체 한도 정보를 담고 있는 멤버 변수 
  (trans_limit)를 지녀야 한다. 
  다음에 제시하고 있는 main 함수의 예와 실행 결과를 참조해서 
  정의하기 바란다.

  > 실행 결과
	계좌 번호: 1234-5678
	계좌 잔액: 5000원
	이체 한도: 100000원
*************************************************************/
/*
class Account
{
private:
    char acc_num[10];   // 계좌 번호
    int balance;      // 계좌 잔액
    public:
    Account (char* num, int bal)
    {
       strcpy(acc_num, num);
       balance = bal;
    }
};


//main 함수의 예
int main(void)
{
    //계좌 번호: 1234-5678
    // 초기 입금액: 5000원
    // 이체 한도: 100000원
    KBAccount acc("1234-5678", 5000 100000);
    acc.ShowData();
    return 0;
};
*/


/************************************************************
  
여러분이 정의한 클래스는 다음의 main 함수와 더불어 무리 없이
 실행되어야 한다.
단 Student 클래스는 나이, 이름, 전공의 정보를 갖고 있으며,
이름과 전공은 동적메모리로 구성된다.

  > 실행 결과
	이름: Hong Gil Dong
	나이: 20
	전공: computer
	이름: Hong Gil Dong
	나이: 20
	전공: computer

*************************************************************/
/*
int main()
{
    Student Hong1(20, "Hong Gil Dong", "computer");
    Hong1.ShowData();
    Student Hong2 = Hong1;
    Hong2.ShowData();
    return 0;
}
*/

