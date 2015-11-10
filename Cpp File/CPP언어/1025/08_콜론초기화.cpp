#include <iostream>
using namespace std;

class CA
{
	int num;
	char ch;
	char name[20];
public:
	CA( int _num, char _ch, char *_name) : num(_num), ch(_ch)
	{
//		num = _num;
//		ch  = _ch;
		strcpy(name, _name);
	}
};

void main()
{
	CA		a(10, 'a', "홍길동");
}

/*
class CA
{
	int num;
	char ch;
	char name[20];
public:
	// 기본값 오버로딩을 같이 사용....금지....
	void foo(int num =10)		{}
	void foo()				   {}
};

void main()
{
	CA  a;			a.foo();
}
*/