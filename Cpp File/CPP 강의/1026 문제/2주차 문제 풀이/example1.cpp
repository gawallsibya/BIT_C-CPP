/************************************************************
  01. �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ���� 
*************************************************************/
#include <iostream>
using namespace std;

class Position
{
	int A, B;
	char C;
public:
	Position (int a, int b, char c) : A(a), B(b), C(c) {}
	Position (int a, int b) : A(a), B(b) {}
	Position (int a) : A(a) {}

	void OutPosition()
	{
		cout << A << ", " << B << ", " << C << endl;
	}

};

void main()
{
     Position Here(30,10,'A');
     Position There(40,5);
     Position Where('K');

     Here.OutPosition();
     There.OutPosition();
     Where.OutPosition();
}
