/**********************************************************
 [ this ] 
**********************************************************/

/*
 this는 객체 자신의 주소를 나타내는 포인터 상수이다.

class Point
{
	int x, y;
public:
	Point(int x=0, int y=0) // : x(_x), y(_y) 
	{
		this->x = x;
		this->y = y;
	}
	
	void foo()
	{
		cout << this << endl;
	}

	// this를 리턴하는 함수.
	Point goo()
	{
		return *this;
	}

    Point* GetThis()
	{
		return this;
	}
};

void main()
{
	Point p;
	
	p.goo().foo();
	
	
	Point p1;
	Point p2;
	
	cout << p1.foo() << endl;
	cout << &p1 << endl;
	
	cout << p2.foo() << endl;
	cout << &p2 << endl;

	cout << p2.GetThis() << endl;
}

  --------------------------------------------
  this 는 객체 자신을 가르키는 Pointer 상수 이다
  멤버 변수와 함수 파라미터 사이에 이름 충돌이 있을 

class Point
{
private:
	int x, y;

public:
	void Set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
경우 this 를 사용하면 멤버 변수에 접근할 수 있다.

------------------------------------------
다음 예제는 각 멤버 함수가 this를 리턴 하는 경우 이다.
#include <iostream>
using namespace std;

class Car
{
public:
	Car* go() 	{ cout << "go" << endl;	return this;	}
	Car* stop()	{ cout << "stop" << endl;	return this;	}
	Car* back()	{cout << "back" << endl;	return this;	}
};
void main()
{
	Car* pCar = new Car;

	pCar->go()->stop()->back();

	delete pCar;
}


*/