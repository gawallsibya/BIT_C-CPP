#include <iostream>
using namespace std;

//1. struct �� class�� ����?
//   C++������ ���� ����  : �⺻ ���� ���� : public or private
//   �ܺ�(Ŭ����)

class C_Name
{
public:
	int num;
	void foo() { cout << num << endl; }

	void woo();
};

void C_Name::woo()		// �ɹ� �Լ��� �ܺ� ����
{
	num;
}

void foo()
{

}


void main()
{
	C_Name	data;			data.num;		data.foo();

	foo();
}