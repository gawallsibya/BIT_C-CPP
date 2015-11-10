/************************************************************
  07. 아래 코드가 실행될 수 있는 클래스 구현 
       이름, 전화번호는 동적배열로,
	     char* name;	// 생성자에서 동적 메모리 할당, 소멸자에서 메모리 해제
		 char* phone;   // 생성자에서 동적 메모리 할당, 소멸자에서 메모리 해제
	   회사명, 직급은 정적배열로 구성할 것 

       복사 생성자 구현할 것 
*************************************************************/
#include <iostream>
using namespace std;

class NameCard
{
	char *N, *Pn; 
	char Cn[20], Y[20];
public:
	NameCard (char *a, char *b, char *c, char *d)
	{
		N = new char[strlen(a)+1]; //동적메모리로 방을 잡을때는 반드시 배열길이+널값으로 방을 잡아준다.
		Pn = new char[20];
		strcpy(N, a);
		strcpy(Pn, b);
		strcpy(Cn, c);
		strcpy(Y, d);
	}

	NameCard (const NameCard & Sibal)
	{
		N = new char[20];
		Pn = new char[20];
		strcpy(N, Sibal.N);
		strcpy(Pn, Sibal.Pn);
		strcpy(Cn, Sibal.Cn);
		strcpy(Y, Sibal.Y);
	}

	~NameCard()
	{
		delete [] N;
		delete [] Pn;
	}

	void ShowData();
};

void NameCard::ShowData()
{
	cout << N << " : " << Pn << " : " << Cn << " : " << Y << endl;
}

int main(void)
{
    NameCard Lee("Lee Hun", "333-3333", "freelec", "manager");
    NameCard Lee2(Lee);
    Lee.ShowData();
    return 0;
}