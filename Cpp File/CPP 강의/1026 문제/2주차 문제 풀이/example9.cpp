
/************************************************************
  09. �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ���� 
      Student Ŭ������ �ɹ� ������ �й�, �̸�, ������ �ִ�.

      ������ �����ε�		: 
	  Set �޼���			: 
	  Get �޼���			: 
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
			cout << "������ �� �ִ� ������ ������ϴ�." << endl;
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
     Student Hong(906123);	// �й�
     Hong.SetName("ȫ�浿");

     Hong.SetScore(99);		// �� �ش� Set�޼��忡�� 0~100�� 
							// ���� ó���� �� �ֵ��� �Ұ� 
	 Hong.SetScore(101);		// "������ �� �ִ� ������ ������ϴ�."��� ���ڿ��� ����� ��

	 cout << "�й� : " << Hong.GetStNum() << endl;
	 cout << "�̸� : " << Hong.GetName() << endl;
	 cout << "���� : " << Hong.GetScore() << endl;

	 Student Kim("��浿", 80);	// �̸�, ����
	 Kim.SetNumber(945126);	// �й�
}