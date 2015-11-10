/**********************************************************
 [ 맴버 함수와 함수 포인터 ] 
**********************************************************/

/*
============================================================
 함수 포인터의 개념 
============================================================
//──────────────────────────────────
// [ 함수 포인터 ]
//──────────────────────────────────

#include <iostream>	
using namespace std;


void foo(int a){	cout << "foo : " << a << endl;	}

void goo(void(*p)(int)); // 함수 포인터를 파라미터로 같는 함수의 선언

void goo(void(*p)(int)){ 	p(100);	}

void main()
{
	int a;			
	int* p = &a;
	goo(foo); // 아주 많이 쓴다.

	void (*pf)(int); // 반환형과 매개형은 같게 한다. pf는 함수를 담는 포인터이다.
	pf = foo; // foo()를 하지 않는다.

	pf(10); // 밑에랑 같은 표현
	(*pf)(20); // = pf(1) == foo(1)
	foo(1);

	cout << "foo의 주소 : "<< foo << endl; // ?? foo함수의 주소
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
	void (*pf[3])() = {foo, goo, hoo}; // pf는 함수의 주소를 담는 배열이다.
	

	int n;

	cout << "0 or 1 or 2? ";
	cin >> n;
	
	pf[n]();
}


*/

/*
==========================================================
 맴버 함수와 함수 포인터 
===========================================================
 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다.
 일반 함수 포인터에 static 멤버 함수의 주소를 담을 수 는 있다.

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
멤버함수의 주소를 담는 포인터 변수를 만들려면 아래 처럼 해야 
한다.
void(Good::*p4)(int) = Good::foo;

하지만 static 멤버 함수는 일반 함수포인터에 담을 수 있다.
void(*p3)(int) = Good::goo;

========================================================
 다음중 틀린곳을 찾아서 고쳐보자.
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

