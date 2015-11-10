/**********************************************************
 [ �ɹ� �Լ��� �Լ� ������ ] 
**********************************************************/

/*
============================================================
 �Լ� �������� ���� 
============================================================
//��������������������������������������������������������������������
// [ �Լ� ������ ]
//��������������������������������������������������������������������

#include <iostream>	
using namespace std;


void foo(int a){	cout << "foo : " << a << endl;	}

void goo(void(*p)(int)); // �Լ� �����͸� �Ķ���ͷ� ���� �Լ��� ����

void goo(void(*p)(int)){ 	p(100);	}

void main()
{
	int a;			
	int* p = &a;
	goo(foo); // ���� ���� ����.

	void (*pf)(int); // ��ȯ���� �Ű����� ���� �Ѵ�. pf�� �Լ��� ��� �������̴�.
	pf = foo; // foo()�� ���� �ʴ´�.

	pf(10); // �ؿ��� ���� ǥ��
	(*pf)(20); // = pf(1) == foo(1)
	foo(1);

	cout << "foo�� �ּ� : "<< foo << endl; // ?? foo�Լ��� �ּ�
}



#include <iostream>
using namespace std;

void foo(){cout << "foo" << endl;}
void goo(){cout << "goo" << endl;}
void hoo(){cout << "hoo" << endl;}

void main()
{
	void (*p)() = foo;
	p();
	void (*pf[3])() = {foo, goo, hoo}; // pf�� �Լ��� �ּҸ� ��� �迭�̴�.
	

	int n;

	cout << "0 or 1 or 2? ";
	cin >> n;
	
	pf[n]();
}


*/

/*
==========================================================
 �ɹ� �Լ��� �Լ� ������ 
===========================================================
 �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ���� �� ����.
 �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ���� �� �� �ִ�.

  #include <iostream>
  using namespace std;

class Good
{
public:
	void foo(int n) { cout << "Good::foo" << endl;}
	static void goo(int n) { cout << "Good::goo" << endl;}
};

void global_foo(int n)
{
	cout << "global foo" << endl;
}

void main()
{
	void(*p1)(int) = global_foo;	// Ok
	void(*p2)(int) = Good::foo;	// Error
	void(*p3)(int) = Good::goo;	// Ok

	void(Good::*p4)(int) = Good::foo; // Ok
}
-------------------------------------------------
����Լ��� �ּҸ� ��� ������ ������ ������� �Ʒ� ó�� �ؾ� 
�Ѵ�.
void(Good::*p4)(int) = Good::foo;

������ static ��� �Լ��� �Ϲ� �Լ������Ϳ� ���� �� �ִ�.
void(*p3)(int) = Good::goo;

========================================================
 ������ Ʋ������ ã�Ƽ� ���ĺ���.
=========================================================
typedef void (*CALLERPROC)(void* param );

void SetFunction( int n, CALLERPROC f, void* param )
{
	for ( int i = 0; i < n; i++)
		(*f)(param);
}
void foo(void* param)
{
	char* msg = (char*)param;
	cout << msg << endl;
}
class Good
{
public:
	void goo(void* param) 
	{
		char* msg = (char*)param;
		cout << msg << endl;
	}
};
void main()
{
	SetFunction( 5, foo, "Hello");
	SetFunction( 5, Good::goo, "Hello");
}

*/

