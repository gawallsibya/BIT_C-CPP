/**********************************************************
 [ this ] 
**********************************************************/

/*
 this�� ��ü �ڽ��� �ּҸ� ��Ÿ���� ������ ����̴�.

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

	// this�� �����ϴ� �Լ�.
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
  this �� ��ü �ڽ��� ����Ű�� Pointer ��� �̴�
  ��� ������ �Լ� �Ķ���� ���̿� �̸� �浹�� ���� 

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
��� this �� ����ϸ� ��� ������ ������ �� �ִ�.

------------------------------------------
���� ������ �� ��� �Լ��� this�� ���� �ϴ� ��� �̴�.
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