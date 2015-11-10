/************************************************************
  02. 아래 코드가 실행될 수 있는 클래스 구현 
*************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Student
{
	int Sd, S;
	char N[10];

public:
	Student (int a) : Sd(a) {}

	void SetName(char *a)
	{
		strcpy(N, a);
	}

	void SetScore(int a)
	{
		if(0 <= a && a <= 100)
			S = a;
	}

	int GetStNum(){return Sd;}

	char* GetName(){return N;}

	int GetScore(){return S;}

};

void main()
{
     Student Kim(8906123);	// 학번
     Kim.SetName("홍길동");
     Kim.SetScore(99);		// 단 해당 Set메서드에서 0~100의 
							// 값만 처리할 수 있도록 할것 

	 cout << "학번 : " << Kim.GetStNum() << endl;
	 cout << "이름 : " << Kim.GetName() << endl;
	 cout << "점수 : " << Kim.GetScore() << endl;
}