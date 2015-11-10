// 동적 & 정적 함수( 동적 binding 
// 정적 : 컴파일시 호출되는 함수가 정해지는 것 : 대다수 함수
// 동적 : 실행시 호출되는 함수가 정해지는 것 : virtual function

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