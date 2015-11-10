
/************************************************************
  09. 아래 코드가 실행될 수 있는 클래스 구현 
      Student 클래스는 맴버 변수로 학번, 이름, 점수가 있다.

      생성자 오버로딩		: 
	  Set 메서드			: 
	  Get 메서드			: 
*************************************************************/
#include <iostream>
using namespace std;

class Student
{
	int Sn, S;
	char N[20];
public:
	Student(int a) : Sn(a){}
	Student(char *a, int b)
	{
		strcpy(N, a);
		S = b;
	}

	void SetName(char *a)
	{
		strcpy(N, a);
	}

	void SetScore(int a)
	{
		if(a <= 100)
			S = a;
		else
			cout << "저장할 수 있는 범위를 벗어났습니다." << endl;
	}

	void SetNumber(int a)
	{
		S = a;
	}

	int GetStNum(){return Sn;}
	char * GetName(){return N;}
	int GetScore(){return S;}
};

void main()
{
     Student Hong(906123);	// 학번
     Hong.SetName("홍길동");

     Hong.SetScore(99);		// 단 해당 Set메서드에서 0~100의 
							// 값만 처리할 수 있도록 할것 
	 Hong.SetScore(101);		// "저장할 수 있는 범위를 벗어났습니다."라는 문자열을 출력할 것

	 cout << "학번 : " << Hong.GetStNum() << endl;
	 cout << "이름 : " << Hong.GetName() << endl;
	 cout << "점수 : " << Hong.GetScore() << endl;

	 Student Kim("김길동", 80);	// 이름, 점수
	 Kim.SetNumber(945126);	// 학번
}