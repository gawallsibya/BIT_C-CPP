#include <iostream>
using namespace std;
// �����ε� : CPP�� �Լ��̸� = C����� �Լ��� �̸� + ����
/*
int Add(int num, int num2)
{
	return num + num2;
}

float Add(float num, float num2)
{
	return num + num2;
}


void main()
{
	cout << Add(10, 10) << endl;
	cout << Add(10.1f, 10.1f) << endl; 
}
*/

// �����ε� ���谡 �ƴϴ�.
/*
int		add();		
void	add();

void foo(int, int);
void foo(int);
void foo(char);
*/


void foo(int num)	{ cout << num << endl; }
//void foo(char ch)	{ cout << ch << endl;  }

void main()
{
	foo('A');
}