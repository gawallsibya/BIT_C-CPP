/************************************************************
  06. ���� ���ǵǾ� �ִ� �Լ����� �⺻���� ���� �Լ� �ϳ��� 
      �����Ͻÿ�.

*************************************************************/
#include <iostream>
using namespace std;

class CA
{
	int A, B;
public:
	void DrawShape( int a = 0, int b = 0)
	{
		A = a;
		B = b;
		cout << a << " : " << b << endl;
	}
};

void main()
{
	CA a;
	a.DrawShape(10, 20);
	a.DrawShape(10);
}
