// ���� & ���� �Լ�( ���� binding 
// ���� : �����Ͻ� ȣ��Ǵ� �Լ��� �������� �� : ��ټ� �Լ�
// ���� : ����� ȣ��Ǵ� �Լ��� �������� �� : virtual function

#include <iostream>
using namespace std;

class CA
{
	int a;
public:
	virtual void foo() { cout << "CA::foo" << endl; }
	virtual void goo() { cout << "CA::foo" << endl; }
	void woo() { cout << "CA::woo" << endl; }
};

class CB : public CA
{
public:
	 void foo() { cout << "CB::foo" << endl; }
	void woo() { cout << "CB::woo" << endl; }

};

void main()
{
	CA *p = new CB;
}