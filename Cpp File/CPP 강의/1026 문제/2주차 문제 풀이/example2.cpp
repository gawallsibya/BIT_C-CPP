/************************************************************
  02. �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ���� 
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
     Student Kim(8906123);	// �й�
     Kim.SetName("ȫ�浿");
     Kim.SetScore(99);		// �� �ش� Set�޼��忡�� 0~100�� 
							// ���� ó���� �� �ֵ��� �Ұ� 

	 cout << "�й� : " << Kim.GetStNum() << endl;
	 cout << "�̸� : " << Kim.GetName() << endl;
	 cout << "���� : " << Kim.GetScore() << endl;
}