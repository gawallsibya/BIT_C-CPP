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
	CA		a(10, 'a', "ȫ�浿");
}

/*
class CA
{
	int num;
	char ch;
	char name[20];
public:
	// �⺻�� �����ε��� ���� ���....����....
	void foo(int num =10)		{}
	void foo()				   {}
};

void main()
{
	CA  a;			a.foo();
}
*/