/************************************************************
  07. �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ���� 
       �̸�, ��ȭ��ȣ�� �����迭��,
	     char* name;	// �����ڿ��� ���� �޸� �Ҵ�, �Ҹ��ڿ��� �޸� ����
		 char* phone;   // �����ڿ��� ���� �޸� �Ҵ�, �Ҹ��ڿ��� �޸� ����
	   ȸ���, ������ �����迭�� ������ �� 

       ���� ������ ������ �� 
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
		N = new char[strlen(a)+1]; //�����޸𸮷� ���� �������� �ݵ�� �迭����+�ΰ����� ���� ����ش�.
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