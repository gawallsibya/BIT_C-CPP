/************************************************************
  06. 다중 정의되어 있는 함수들을 기본값을 갖는 함수 하나로 
      변경하시오.

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
