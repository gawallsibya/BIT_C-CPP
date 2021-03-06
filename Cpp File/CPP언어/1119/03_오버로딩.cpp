/************************************************************
  01. 아래 코드가 실행될 수 있는 클래스 구현 
*************************************************************/

void main()
{
     Complex C1(1.1,2.2);
     Complex C2(3.3,4.4);
     C1.OutComplex();
     C2.OutComplex();

     Complex C3;
     C3=C1+C2;			// 맴버로 구현할 것
	 C3.OutComplex();
	 C3=C1-C2;			// 전역함수로 구현할 것
	 C3.OutComplex();
}

/************************************************************
  02. 아래 코드가 실행될 수 있는 클래스 구현 
*************************************************************/
/*
void main()
{
     Time A(1,1,1);
     Time B(1,1,1);

     if (A == B) {
          puts("A와 B는 같다.");
     } else {
          puts("A와 B는 다르다.");
     }
}
*/

/************************************************************
  03. 아래 코드가 실행될 수 있는 클래스 구현 
*************************************************************/
/*
void main()
{
     Time A(1,1,1);
     Time B;

     B=++A;
     A.OutTime();
     B.OutTime();
     B=A++;
     A.OutTime();
     B.OutTime();
}
*/

/************************************************************
  04. 아래 코드가 실행될 수 있는 클래스 구현 
       단 이름은 char *name으로 선언할 것
*************************************************************/
/*
void main()
{
     Person Boy("홍길동",22);
     Person Young("김길동",25);
     Young=Boy;
     Young.OutPerson();
}
*/


/************************************************************
  05. 아래 코드가 실행될 수 있는 클래스 구현 
*************************************************************/
void main()
{
     Time A(1,1,1);
     Time *p;
     p=new Time(2,2,2);
     cout << "현재 시간은 " << A << "입니다." << endl;
     cout << "현재 시간은 " << p << "입니다." << endl;
     delete p;
}


/************************************************************
  06. 아래 코드가 실행될 수 있는 클래스 구현 
*************************************************************/
void main()
{
     Time A(1,1,1);

     A[0]=12;		// 첨자 0은 시간 1은 분, 2는 초를 리턴
     printf("현재 %d시입니다.\n",A[0]);
}

