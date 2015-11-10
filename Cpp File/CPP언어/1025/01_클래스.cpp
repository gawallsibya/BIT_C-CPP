#include <iostream>
using namespace std;

//1. struct 와 class의 차이?
//   C++언어에서는 거의 동일  : 기본 접근 제한 : public or private
//   외부(클래스)

class C_Name
{
public:
	int num;
	void foo() { cout << num << endl; }

	void woo();
};

void C_Name::woo()		// 맴버 함수의 외부 정의
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