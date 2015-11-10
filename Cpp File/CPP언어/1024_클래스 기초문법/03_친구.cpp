/**********************************************************
 [ friend ] 
**********************************************************/
/*
 - Private 멤버에 접근 할 수 있는 일반 함수.
 - 정보은닉, 캡슐화의 원칙이 깨지가 되므로 되도록 사용하지 
   않는다.
 - 연산자 재정의에서 주로 사용된다.

 - friend function
 - friend member function
 - friend class


class Point
{
private:
	int x;
	int y;

public:
	Point( int _x = 0, int _y = 0) : x(_x), y(_y) {}

	friend void print( const Point& );
};

void print( const Point& p)
{
	cout << "(" << p.x << ", " << p.y << ")" << endl;
}
void main()
{	
	Point p(3,4);
	print( p );
}

----------------------------------------------
*) friend function
   C++ 에서는 객체의 private 멤버를 외부 함수 에서 접근 
   하는 것은 명백한 Error이다.
   하지만 friend 함수 에서는 객체의 Private멤버에 접근하는
   것이 허용된다. 주로 연산자 재정의에서 사용한다.
 
*) friend class
   friend class 를 만드는 것도 가능하다. 
   아래 예제에서 Circle 은 Point 의 friend class 이므로 
   Circle 의 모든 멤버에서 Point 의 privae멤버인 x, y를 
   접근하는 것은 허용된다.

#include <iostream>
using namespace std;
class Point
{
private:
	int x, y; 
public:
	Point(int _x = 0,int _y = 0) : x(_x), y(_y) {}
	friend class Circle;
};

class Circle
{
private:
	Point orign;
	int radius;
public:
	Circle(Point or, int r) : orign(or),radius(r) {}
	Circle(int x, int y, int r) : orign(Point(x,y)), radius(r) {}

	void SetOrign(int x, int y)
	{
		orign.x = x;
		orign.y = y;
	}
};

void main()
{
	Circle c( 10, 10,5);
	c.SetOrign( 2,2);
}

*/